## Description
This purpose of this project is to be able to use all the buttons of the msp430
on the LCD screen (green board). Also when each button is pressed all the
led's are supposed to change or be dimmed and atleast on button should have a buzzer.


## Running & Compiling
To run this, you must first access the button_demo folder and use the "make
clean" command to make sure no other files are there. Then run the "make"
command and then run the "make load" command while the msp430 is connected.


## How to use it
Assuming you compiled and ran the code correctly, then you will notice that
there are no led's turned on or buzzing noises, thats a good sign. Now then...

__Button1__: When this button is pressed, both the green and red led should be
turned on, along with a high pitched buzzer sound.

__Button2__: When this button is pressed, both led's should be dimmed by 75
percent and making a lower buzzing noise.

__Button3__: When this button is pressed, both led's should be dimmed by 25
percent and making the lowest buzzing noise out of all of them.

__Button4__: When this button is pressed, both led's should be turned off and the
buzzer should be turned off too.
