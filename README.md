# trt_pose-as-keystrokes
Use nVidia's trt_pose model to detect changes in xy coordinates and send keystrokes to computer via Arduino from the Jetson Nano.

# Demo
This is just a bandaid until I can figure out how to use the Jetson Nano to send inputs to SteamVR and play.
![demo](https://user-images.githubusercontent.com/41629493/110740715-dc609100-8276-11eb-8463-7185211b41c7.mp4)


# Instructions
Install trt_pose as normal
https://github.com/NVIDIA-AI-IOT/trt_pose

You need: Jetson Nano, Arduino Pro Micro, a USB camera

You can use a CSI camera but I tested with a USB camera so you will have to make code modifications on your own.
You can use a different Arduino but make sure it can act as an HID or send keyboard inputs using Keyboard.h

1. Follow the instructions from the trt_pose repo and run it and make sure it is working.
2. Then upload the live_demo_modified.ipynb to Jupyter lab into the same folder as the live_demo.ipynb folder from step 1. It uses the OPTIMISED model generated by the code in live_demo in step 1.
3. In the execute function near the bottom, the GPIO mode and pins are defined. Modify them according to your needs or just connect them according to the GPIO.mode labeling.
4. Make sure the live_demo_modified.ipynb works. If it works stop it and proceed onto the Arduino code.
5. Connect your GPIO pins to your Arduino Pro Micro digital pins.
6. Use the code in Arduino-Keyboard-code.txt and upload it into a new sketch in the Arduino IDE.
7. Make sure the pins on the Jetson Nano are connected to the appropriate pins on the Arduino Pro Micro and connect the ground pin to ground on the Nano. In my case I used the following so I connect my GPIO pins to those digital pins. Ex: GPIO 4 pin to pin 8 on Arduino Pro Micro.
 ```python
          #define pin8 8 //WS 4
          #define pin9 9 //AD 5
          #define pin10 10 //INT1 6  
          #define pin14 14 //INT2 12  
          #define pin15 15 //UPDOWN 13  
          #define pin16 16 //LEFTRIGHT 16  
 ```
8. Modify your keys to your preferences. WS detects change in vertical left hand position. AD detects horizontal position. UPDOWN detects change right hand vertical position. LEFTRIGHT detects change right hand horizontal position. Upload the code into your Arduino via USB. 
9. Run live_demo_modified code. Connect your Arduino to your PC. Open Notepad. You will see your hand movements sending keystrokes to your PC. Change the margins and timething in your Nano to make it harder to send input to Arduino which lessesn the chances of accidental inputs. Change the delay on the Arduino code to modify how long a key is being pressed.


# The VR part that I haven't tested much
Use this repo for emulating SteamVR input on keyboard
https://github.com/r57zone/OpenVR-driver-for-DIY

Keyboard inputs are provided in that repo so modify your Arduino code accordingly.

Using the fabo MPU9250 IMU I was also able to emulate an HMD somewhat.

To do this you need: A fabo MPU9250 and another Arduino Pro Micro

1. Connect the SDA and SCL ports and VCC and GND onto the Aruduino accordingly. IF you don't know where the SDA and SCL ports are on the Arduino, search online for images for your specific board. On the Pro Micro the ports were 2 and 3.
2. Upload the Arduino MPU9250 code onto the Arduino via the Arduino IDE. 
3. Hopefully you get keypad keystrokes. 

You can modify the MPU code so that you have the gyro and magnetometer information for more accuracy. The current implementation relies on the Earth's gravitational force to detect the orientation. 

# Issues
Please DM me any errors or problem with instructions. I will do my best to help you out.
