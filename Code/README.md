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

## Experimental Fan Mode

ProMacro-5-fan.ino includes a PWM output for the broken out pins on the right side that aligns with a standard PC PWM fan.
Allows you to chang the fan's speed from 0 - off to 5 - full power. Tested with a 12V Noctua fan: https://amzn.to/3jjgQIV (Amazon).
5V may work better https://amzn.to/3A8RofR (Amazon) though not yet tested, and color scheme is questionable.

## Experimental Music Mode

ProMacro-6-music.ino allows you to connect a small speaker to GPIO pin 7 to play a number of notes.

Amazon links are affiliate, meaning I get a small percentage of sales.
