#ifndef EZPROTOGEN_H
#define EZPROTOGEN_H

#include <MD_MAX72xx.h>
#include "frames.h"

struct KeyFrames {
  const unsigned char* left;
  const unsigned char* right;
};

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES   4
#define LEFT_EYE_CS_PIN    9
#define RIGHT_EYE_CS_PIN    10
#define LEFT_MAW_CS_PIN    7
#define RIGHT_MAW_CS_PIN    8


MD_MAX72XX left_eye = MD_MAX72XX(HARDWARE_TYPE, LEFT_EYE_CS_PIN, MAX_DEVICES);
MD_MAX72XX right_eye = MD_MAX72XX(HARDWARE_TYPE, RIGHT_EYE_CS_PIN, MAX_DEVICES);
MD_MAX72XX left_maw = MD_MAX72XX(HARDWARE_TYPE, LEFT_MAW_CS_PIN, MAX_DEVICES);
MD_MAX72XX right_maw = MD_MAX72XX(HARDWARE_TYPE, RIGHT_MAW_CS_PIN, MAX_DEVICES);



void rightEyeDraw(const unsigned char *bmp)
{
  right_eye.clear();

  for (uint8_t x = 0; x < 32; x++)
  {
    uint8_t colByte = pgm_read_byte(bmp + x);

    for (uint8_t y = 0; y < 8; y++)
    {
      bool pixel = (colByte >> y) & 0x01;
      right_eye.setPoint(y, x, pixel);
    }
  }
  right_eye.update();
}

void leftEyeDraw(const unsigned char *bmp)
{
  left_eye.clear();

  for (uint8_t x = 0; x < 32; x++)
  {
    uint8_t colByte = pgm_read_byte(bmp + x);

    for (uint8_t y = 0; y < 8; y++)
    {
      bool pixel = (colByte >> y) & 0x01;
      left_eye.setPoint(y, x, pixel);
    }
  }
  left_eye.update();
}

void leftMawDraw(const unsigned char *bmp)
{
  left_maw.clear();

  for (uint8_t x = 0; x < 32; x++)
  {
    uint8_t colByte = pgm_read_byte(bmp + x);

    for (uint8_t y = 0; y < 8; y++)
    {
      bool pixel = (colByte >> y) & 0x01;
      left_maw.setPoint(y, x, pixel);
    }
  }
  left_maw.update();
}
  
void rightMawDraw(const unsigned char *bmp)
{
  right_maw.clear();

  for (uint8_t x = 0; x < 32; x++)
  {
    uint8_t colByte = pgm_read_byte(bmp + x);

    for (uint8_t y = 0; y < 8; y++)
    {
      bool pixel = (colByte >> y) & 0x01;
      right_maw.setPoint(y, x, pixel);
    }
  }
  right_maw.update();
}

void showStartupLogo() {
  left_eye.begin();
  right_eye.begin();
  left_maw.begin();
  right_maw.begin();
  left_eye.control(MD_MAX72XX::INTENSITY, 2 );
  right_eye.control(MD_MAX72XX::INTENSITY, 2 );
  left_eye.clear();
  right_eye.clear();
  left_eye.control(MD_MAX72XX::UPDATE, MD_MAX72XX::OFF);
  right_eye.control(MD_MAX72XX::UPDATE, MD_MAX72XX::OFF);
  leftEyeDraw(left_logo);
  rightEyeDraw(right_logo);
}

#endif