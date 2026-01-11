# EzProtogen (for Arduino Nano)

This is a plug-and-play software for a protogen fursuit head. It allows for
use of 4 8x32 led matrix displays compatible with MAX72XX library. The features include: animated eyes on both sides, and unanimated maw.
Each display element can be customized by the user.

## Hardware Requirements

 - Arduino Nano (or compatible)
 - MAX72XX Compatible display
 - Jumper wires
 - Breadbord (optional)

## Software Requirements

This project was designed to run on Arduino IDE (at least 1.6.2).
It requires the following libraries:
 - Adafruit MD_MAX72XX

### Installing Libraries

1. Open Arduino IDE
2. Go to **Sketch -> Include Library -> Manage Libraries**.
3. In the Library Manager, search for *MD_MAX72XX* and click *Install*

## Wiring / Connection Diagram

### Left eye display wiring:
 - **MAX72XX VCC** -> Arduino Pin **5v**
 - **MAX72XX GND** -> Arduino Pin **GND**
 - **MAX72XX DIN** -> Arduino Pin **D11**
 - **MAX72XX CS** -> Arduino Pin **D10**
 - **MAX72XX CLK** -> Arduino Pin **D13**

### RIGHT eye display wiring:
 - **MAX72XX VCC** -> Arduino Pin **5v**
 - **MAX72XX GND** -> Arduino Pin **GND**
 - **MAX72XX DIN** -> Arduino Pin **D11**
 - **MAX72XX CS** -> Arduino Pin **D9**
 - **MAX72XX CLK** -> Arduino Pin **D13**

### Left maw display wiring:
 - **MAX72XX VCC** -> Arduino Pin **5v**
 - **MAX72XX GND** -> Arduino Pin **GND**
 - **MAX72XX DIN** -> Arduino Pin **D11**
 - **MAX72XX CS** -> Arduino Pin **D8**
 - **MAX72XX CLK** -> Arduino Pin **D13**

### Left eye display wiring:
 - **MAX72XX VCC** -> Arduino Pin **5v**
 - **MAX72XX GND** -> Arduino Pin **GND**
 - **MAX72XX DIN** -> Arduino Pin **D11**
 - **MAX72XX CS** -> Arduino Pin **D9**
 - **MAX72XX CLK** -> Arduino Pin **D13**

You can also check the visual diagram under **docs/wiring.png**

## Usage

### Upload the Code

1. Open main.ino in Arduino IDE (at least 1.6.2)
2. Select your board and correct COM port
3. Click the **Upload** Button.

### Expected Behaviour

- By default, the eye displays will display **benzene** for 2 seconds.
- After 5 seconds, animated eyes will appear, along with a static maws from both sides.
- The eye displays should display the animation simultaneously.

### Customization

- You can change the default animation, by using your own animation frames.
- You can customize the amount of frames, as well as their duration in **main.ino**.
- The startup logo can be changed in frames.h
- Animation frames can be changed in frames.h

1. Create a 32x8 px canvas in a raster graphics editing software (like GIMP). Ensure the background is white, amd that you are only using black or white (gray / other colors are not supported).
2. draw the desired frame, and export it as png.
3. Convert the png into byte array using eg. image2cpp.
4. Upload the png file and apply the following settings: 
 - Background color: White
 - Invert Image Colors
 - Code output format: Arduino code
 - Draw mode: Vertical - 1 bit per pixel
 - (optional) sometimes, the image might come out flipped. In that case the user must use the **flip image** option.
 
5. Copy the entire frame byte array (cons unsigned char... until the  first **};** sign.
6. Paste the frame into frames.h
7. In **main.ino**, edit the **KeyFrames blinkSequence[]** by replacing the frame names with yours. (the left part is meant for the left eye display and vice versa).
8. Upload the code again.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

You are free to use, modify, and distribute this project, even comercially. Please ensure that you include this license notice in any redistributed versions.

## Contact

For any questions or suggestions, feel free to open an issue or contact me at amichalinaaa@gmail.com
