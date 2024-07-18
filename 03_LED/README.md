# Lesson 3 LED

## Required Components

(1) x Elegoo Uno R3
(1) x Breadboard MB-102
(1) x 5mm red LED
(1) x 220 ohm resistor
(1) x 1k ohm resistor
(1) x 10k ohm resistor
(2) x M-M wires (Male to Male jumper wires)

### Elegoo Uno R3
The UNO is a convenient source of 5 volts, which we will use to provide power to
the LED and the resistor. You do not need to do anything with your UNO, except to
plug it into a USB cable.

### Breadboard MB-102

A breadboard enables you to prototype circuits quickly, without having to solder the connections. 
The simplest kind is just a grid of holes in a plastic block. Inside are strips of metal 
that provide electrical connection between holes in the shorter rows. Pushing the legs of 
two different components into the same row joins them together electrically. A deep channel
running down the middle indicates that there is a break in connections there,
meaning, you can push a chip in with the legs at either side of the channel without
connecting them together. Some breadboards have two strips of holes running
along the long edges of the board that are separated from the main grid. These have
strips running down the length of the board inside and provide a way to connect a
common voltage. They are usually in pairs for +5 volts and ground. These strips are
referred to as rails and they enable you to connect power to many components or
points in the board.

### 5mm Red LED

LEDs make great indicator lights. They use very little electricity and they pretty much
last forever. 5mm refers to the diameter of the LED. Other common sizes are 3mm and 10mm.
You cannot directly connect an LED to a battery or voltage source because 1) the
LED has a positive and a negative lead and will not light if placed the wrong way and
2) an LED must be used with a resistor to limit or 'choke' the amount of current
flowing through it; otherwise, it will burn out!\
If you do not use a resistor with an LED, then it may well be destroyed almost
immediately, as too much current will flow through, heating it and destroying the
'junction' where the light is produced.\
There are two ways to tell which is the positive lead of the LED and which the
negative.

1. The positive lead is longer.
2. Where the negative lead enters the body of the LED, there is a flat edge
to the case of the LED.

If you happen to have an LED that has a flat side next to the longer lead, you should
assume that the longer lead is positive.

### Resistors

As the name suggests, resistors resist the flow of electricity. The higher the value of
the resistor, the more it resists and the less electrical current will flow through it.\
The unit of resistance is called the Ohm, which is usually shortened to Ω the Greek
letter Omega. Because an Ohm is a low value of resistance (it doesn't resist much at
all), we also denote the values of resistors in kΩ (1,000 Ω) and MΩ (1,000,000 Ω).
These are called kilo-ohms and mega-ohms.\
These resistors all look the same, except that they have different colored
stripes on them. These stripes tell you the value of the resistor.
The resistor color code has three colored stripes and then a gold stripe at one end.\
Unlike LEDs, resistors do not have a positive and negative lead. They can be
connected either way around.

## Project

With the 220 Ω resistor in place, the LED should be quite bright. If you swap out the
220 Ω resistor for the 1kΩ resistor, then the LED will appear a little dimmer. Finally,
with the 10 kΩ resistor in place, the LED will be just about visible. Pull the red jumper
lead out of the breadboard and touch it into the hole and remove it, so that it acts
like a switch. You should just be able to notice the difference.
At the moment, you have 5V going to one leg of the resistor, the other leg of the
resistor going to the positive side of the LED and the other side of the LED going to
GND. However, if we moved the resistor so that it came after the LED, as shown
below, the LED will still light.
You will probably want to put the 220Ω resistor back in place.
It does not matter which side of the LED we put the resistor, as long as it is there
somewhere

### Images 

#### LED with 220 Ohm Resistor (Brighter)

![](./images/220_ohm.jpg)

#### LED with 10k Ohm Resistor (Dimmer)

![](./images/10k_ohm.jpg)
