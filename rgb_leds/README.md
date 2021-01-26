# RGB_LED

![RGB LED project](rgb_led_pic.png)

hi! today we're playing with multiple potentiometers and RGB LEDs. I have different resistors purely 
because I didn't have 6 of the same ones, but I tried to keep the same for each LED. 

**EDIT:** The photo uses the wrong
GPIO pins. Must use PWM GPIO pins to use in-between RGB values.

# tools used
- potentiometer x 3   
- RGB LED common cathode x 2  
- 220Ω Resistor x 3  
- 560Ω Resistor x 3  
- button 
- jumper wires
- breadboard

## how it works
- the potentiometers (R, G, B) control the RGBvalues
- the button controls which LED is being controlled: LED1 or LED2
- adjusting the potentiometers simultaneously changes the color of the LED that is lit, 

## what i learned
- LED brands matter. LED2 is brighter, LED1 G and B pins are switched (for some reason?) Each LED glows at different RGB values.
- how to use a potentiometer
- how to use continuity on a multimeter
- difference between a common cathode and a common anode RGB LED & how to differentiate
- analog voltage

**EDIT:** RGB LED requires using PWM GPIO pins, so it's a smoother light up.

## how to run
1. i assume you know how to install the arduino IDE.
2. open the file on arduino IDE.
3. connect them accordingly.
4. upload the file to the arduino!
