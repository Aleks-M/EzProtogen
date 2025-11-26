/*
        Ez Protogen
        Copyright© 2025 Aleks Michalina
        For Licensing, check readme.md
*/

#include <SPI.h>
#include "ezprotogen.h"
#include "frames.h"

/*ADJUST FOR CUSTOM SETTINGS*/
const int BLINK_FRAMES = 4;
const int FRAME_DURATION = 90;
const int BLINK_DELAY = 5000;
const int STARTUP_LOGO_DURATION = 2000;
/*END OF ADJUSTMENTS*/

/*KEYFRAMES CAN BE MODIFIED UNDER "frames.h" file*/

/* KEYFRAME SEQUENCE */
const KeyFrames blinkSequence[] = {
  { blink_1_left, blink_1_right },
  { blink_2_left, blink_2_right },
  { blink_3_left, blink_3_right },
  { blink_4_left, blink_4_right },
  { blink_3_left, blink_3_right },
  { blink_2_left, blink_2_right },
  { blink_1_left, blink_1_right }
};

const int blinkCount = sizeof(blinkSequence) / sizeof(blinkSequence[0]);

/* MAIN CODE */
void setup()
{
showStartupLogo();
delay(STARTUP_LOGO_DURATION);
leftMawDraw(maw_left);
rightMawDraw(maw_right);
}

void loop()
{
  for (int i = 0; i < blinkCount; i++) {
    leftEyeDraw( blinkSequence[i].left );
    rightEyeDraw( blinkSequence[i].right );
    delay(FRAME_DURATION);
  }
  delay(BLINK_DELAY);
}