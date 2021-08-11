## Standard Code

Current standard code (ProMacroStandard.ino) is written and tested on a Macintosh -  
should work with a PC or Linux, possibly with some modifications.

Includes a mode for media control and browser tabbing, as well as a "jiggle" mode to keep your computer awake.
Switch modes by simultaneously pressing upper-right key, and the key directly below that.

Recently made some code changes, so LEDs are not tested as of now.

Note that after initial install, GND and RST pins may need to be shorted together  
momentarily after hitting upload in the Arduino IDE in order to reprogram.

## Alternative Modes Slihter.io Mode & FCPX

Additional modes are included in the standard code and can be accessed by modifying the array shown below. Modes  
will switch from the 0 indexed number in the array, to the next one and so forth. So if you want your controller to  
go: volume-jiggle-slither, change it to {0, 1, 2}. volume-FCPX would be {0, 4}. All current modes would be {0, 1, 2, 3}

![image](line36.png)

![image](input-modes.png)

In slither mode, align the mouse with the head of worm and press upper-right keyboard button. You can then steer the 
worm with the encoder and speed up with the three bottom buttons. There's also a "NASCAR" mode where the worm keeps
turning left.

![image](slither.jpg)

In FCPX mode, encoder advances/rewinds frames, bottom buttons stop ffwd/rev, top right and below zoom in and out. Press
the encoder to break all clips. Great for trimming extra footage.



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

Amazon links are affiliate, meaning I get a small percentage of sales.
