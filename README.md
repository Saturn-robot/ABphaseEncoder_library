[![Project Status: Active – The project has reached a stable, usable state and is being actively developed.](http://www.repostatus.org/badges/latest/active.svg)](http://www.repostatus.org/#active)

# Overview

The driver is to drive AB phase encoders. You can get two counters simultaneously using it.

# Installation

You can install this library via the Library Manager interface. For example, as for Arduino 1:1.0.5+dfsg2-2, you can install it from directory in **Sketch** menu > Import library... > Add library... in form of zip file or folder.

If you want to add a library manually, you need to uncompress it and put in the proper directory. Arduino libraries are managed in three different places: inside the IDE installation folder, inside the core folder and in the libraries folder inside your sketchbook. The location of your sketchbook defaults to “..\<you>\DOCUMENTS\Arduino” on Windows machines. The path is clearly shown in the Preferences panel. If you want to see where the sketchbook defaults open Preferences under File.

# Usage

## Create ABPhaseEncoders

Creating an Object which contains four parameters:port of left encoder output-A, port of left encoder output-B, right encoder output-A and right encoder output-B. You must connect both output-As with digital pins usable for interrupts of your arduino board. Note that you should create **only one** ABPhaseEncoders object in a program and if you create several objects, only **the last** takes effect.

You can find which pins are usable for interrupts here:<https://www.arduino.cc/en/Reference/AttachInterrupt>

```
ABPhaseEncoders encoders(RIGHT_OUTPUT_A, RIGHT_OUTPUT_B, LEFT_OUTPUT_A, LEFT_OUTPUT_B);
```

## Get counts of encoders

This library offer a method to return current count of encoder and you need to specify which encoder to read as parameter. The parameter is either `LEFT` or `RIGHT`.

```
encoders.readEncoder(LEFT);
encoders.readEncoder(RIGHT);
```

## Reverse value of encoders

If you get values which are reverse with the direction of wheel rotation, you can use this method.

```
// When you get reversed value, just reverse it
encoders.rightReverse();
```

This library is very easy to use. You can learn it from codes in example folder.

# License

This library is licensed under the GNU General Public License, v3. A copy of this license is included in the file [LICENSE](LICENSE).
