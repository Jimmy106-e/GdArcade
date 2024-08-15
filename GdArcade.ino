//**************************************************************
// Tiny Arcade Game Tutorial - Tiny Brick LITE
// Written by: Brandon Farmer for TinyCircuits
// Initiated:  Mon. 3/27/2017 @  4:00pm
//   Updated: Thur. 3/30/2017 @  2:30pm
//**************************************************************
#include <TinyScreen.h>
#include <Wire.h>
#include <SPI.h>
#include "TinyArcade.h"
#include "GameTutorialSprites.h"

TinyScreen display = TinyScreen(TinyScreenPlus);

unsigned long frameStart = 0;
unsigned long frameTime = 18;
unsigned int frame = 0;

typedef struct {
  int x;
  int y;
  int width;
  int height;
  int collisions;
  unsigned char *bitmap;
  int gravity;
  int velocityY;
  int jumpForce;
  int moveSpeed;
  int oldx;
  int oldy;
} ts_char;

typedef struct {
  int x;
  int y;
  int width;
  int height;
  int collisions;
  unsigned char *bitmap;
  bool deadly;
} ts_sprite;

bool isJumping = false;

ts_char cube8 = { 40, 17, 8, 8, 0, GDCUBE8, 1, 0, -5, 2, 0, 0 };
ts_sprite Spike = { 70, 48, 8, 8, 0, spike, true };
ts_sprite Block = { 62, 48, 8, 8, 0, block, false };
ts_sprite scene[] = { Block, Spike };

int groundLevel = 48;
const uint8_t bgColour = TS_8b_Red;
const uint8_t ALPHA = bgColour;

void setup() {
  Serial.begin(9600);
  arcadeInit();
  display.begin();
  display.setBitDepth(TSBitDepth8);
  display.setBrightness(15);
  display.setFlip(false);

  // USBDevice.init();
  // USBDevice.attach();
  // SerialUSB.begin(9600);
}

void loop() {
  // display.clearScreen();
  unsigned long timer = millis();
  while (millis() - frameStart < frameTime) {
    delay(1);
  }
  frameStart = millis();
  display.drawRect(0, 0, 96, 55, TSRectangleFilled, bgColour);
  display.drawLine(0, 56, 96, 56, TS_8b_Black);
  display.drawRect(0, 57, 96, 64, TSRectangleFilled, TS_8b_Gray);

  // Cube
  display.setX(cube8.x, cube8.x + cube8.width - 1);
  display.setY(cube8.y, cube8.y + cube8.height - 1);
  // //now start a data transfer
  display.startData();
  display.writeBuffer(cube8.bitmap, cube8.width * cube8.height);
  display.endTransfer();

  displayScene();

  // // Spike
  // display.setX(Spike.x, Spike.x + Spike.width - 1);
  // display.setY(Spike.y, Spike.y + Spike.height - 1);
  // //now start a data transfer
  // display.startData();
  // display.writeBuffer(Spike.bitmap, Spike.width * Spike.height);
  // display.endTransfer();

  // // Block
  // display.setX(Block.x, Block.x + Block.width - 1);
  // display.setY(Block.y, Block.y + Block.height - 1);
  // //now start a data transfer
  // display.startData();
  // display.writeBuffer(Block.bitmap, Block.width * Block.height);
  // display.endTransfer();

  display.setFont(thinPixel7_10ptFontInfo);
  display.setCursor(12, 12);

  // delay(4);
  frame++;
  moveChar();
  // checkForCollision(Spike);
  timer = millis() - timer;
}

void moveChar() {
  cube8.oldx = cube8.x;
  cube8.oldy = cube8.y;

  cube8.velocityY += cube8.gravity;
  cube8.y += cube8.velocityY;

  checkCollision();
  checkDeath(Spike);

  if (cube8.y >= groundLevel) {
    cube8.y = groundLevel;  // Reset position to ground level
    cube8.velocityY = 0;    // Reset velocity
    isJumping = false;      // The player is on the ground, so they can jump again
  }

  if (checkButton(TAButton1) && !isJumping) {
    cube8.velocityY = cube8.jumpForce;
    isJumping = true;
  }

  if (checkJoystick(TAJoystickLeft) && cube8.x > 0) cube8.x -= cube8.moveSpeed;
  if (checkJoystick(TAJoystickRight) && cube8.x < 96 - 8) cube8.x += cube8.moveSpeed;
}

//collision

void checkDeath(ts_sprite object) {
  if (object.deadly) {
    if (cube8.x > object.x - cube8.width && cube8.x < object.x + cube8.width) {
      if (!isJumping) cube8.x = 40;
    }
  }
}

void checkCollision() {
  //look through scene and check for collision
  ts_sprite object = { 0, 0, 0, 0, 0, temp, false };
  for (int i = 0; i < 2 && scene[i].deadly != true; i++) {
    object = scene[i];
    // Calculate the sides of both objects
    int leftA = cube8.x;
    int rightA = cube8.x + cube8.width;
    int topA = cube8.y;
    int bottomA = cube8.y + cube8.height;

    int leftB = object.x;
    int rightB = object.x + object.width;
    int topB = object.y;
    int bottomB = object.y + object.height;

    bool isCollidingVertically = false;

    // Check if the objects are colliding
    if (bottomA > topB && topA < topB && rightA > leftB && leftA < rightB) {
      // Collision on the top side
      cube8.y = topB - cube8.height;  // Adjust position to land on the platform
      isJumping = false;              // Allow jumping again
      isCollidingVertically = true;
      cube8.velocityY = 0;  // Stop falling
    }

    // Handle bottom collision (if jumping up into a platform)
    if (!isCollidingVertically && topA < bottomB && bottomA > bottomB && rightA > leftB && leftA < rightB) {
      cube8.y = bottomB;    // Adjust position below the platform
      cube8.velocityY = 0;  // Stop upward movement
    }

    // Check for horizontal collisions only if the player is not colliding vertically
    if (!isCollidingVertically) {
      // Check for collision on the left side
      if (rightA > leftB && leftA < leftB && bottomA > topB && topA < bottomB) {
        cube8.x = leftB - cube8.width;  // Adjust position to exactly to the left of the platform
      }
      // Check for collision on the right side
      else if (leftA < rightB && rightA > rightB && bottomA > topB && topA < bottomB) {
        cube8.x = rightB;  // Adjust position to exactly to the right of the platform
      }
    }
  }
}

void displayScene() {
  ts_sprite object = { 0, 0, 0, 0, 0, temp, false };
  for (int i = 0; i < 2; i++) {
    object = scene[i];
    display.setX(object.x, object.x + object.width - 1);
    display.setY(object.y, object.y + object.height - 1);
    display.startData();
    display.writeBuffer(object.bitmap, object.width * object.height);
    display.endTransfer();
  }
}