## Standard Code

Current standard code (ProMacro.ino) is written and tested on a Macintosh -  
should work with a PC or Linux, possibly with some modifications.

Includes a mode for media control and browser tabbing, as well as a "jiggle" mode to keep your computer awake.

Note that after initial install, GND and RST pins may need to be shorted together  
momentarily after hitting upload in the Arduino IDE in order to reprogram.

## Slihter.io Mode

ProMacro-4-slither.ino includes a third mode for playing slither.io. Tab through modes with encoder button.
align the mouse with the head of worm and press upper-right keyboard button. You can then steer the worm with the encoder
and speed up with the three bottom buttons.

![image](slither.jpg)

## Experimental Fan Mode

ProMacro-5-fan.ino includes a PWM output for the broken out pins on the right side that aligns with a standard PC PWM fan.
Allows you to change the fan's speed from 0 - off to 5 - full power. Routines for Slither.io and dedicated fan display
are in the code, but disabled. Code/fan works, but power requirements have not been mearsured so use at your own risk.

Tested with a 12V Noctua fan: https://amzn.to/3jjgQIV (Amazon).
5V version moves more air, https://amzn.to/3A8RofR (Amazon) though color scheme is questionable.

## Experimental Music Mode

ProMacro-6-music.ino allows you to connect a small speaker to GPIO pin 7 to play a number of notes.
Demo: https://twitter.com/JeremySCook/status/1423705079153139716

![image](tone.jpg)

## Experimental Final Cut Pro X Mode

ProMacro-6-FCPX.ino adds a mode where the wheel acts as a jog wheel. Press down to stop. Press down & lower-right button
to switch back to standard mode.

Amazon links are affiliate, meaning I get a small percentage of sales.
