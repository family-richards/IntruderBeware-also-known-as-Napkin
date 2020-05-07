# Hi!
  Thanks for choosing Napkin! The first thing you'll need to do is download this repository. Download the [zip of it](https://github.com/family-richards/Napkin/archive/master.zip) and unzip it, or clone it with `git clone https://github.com/family-richards/Napkin.git`.
# Testing your Feather
- Napkin is powered by the [ESP32 Feather](https://adafru.it/3405), so make sure you have one (without headers).
- Make sure you have the Arduino IDE installed. If not, [download it](https://www.arduino.cc/en/Main/Software). If you need to, restart your computer.
- Open the file called [`code/setupwizard/setupwizard.ino`](code/setupwizard/setupwizard.ino) with the Arduino IDE.
- Take your ESP32 Feather, and find a matching USB cable. If you've already plugged it in, unplug it.
- In the Arduino IDE, open the `File` menu. Click on `Examples` > `01. Basics` > `Blink` to open the test sketch.
- Click on `Tools` > `Port`. Write down all of the options. Close the menu for now.
- Next, plug in your ESP32 Feather. Click on `Tools` > `Port` again. Find the option that used not to be there, and select it.
- Open `File` > `Preferences`. Find the place where it says `Additional Boards Manager URLs:`. Click on the icon that looks like this: ![Two side-by-side windows](popout.png)
- If you already have added an additional board manager URL, make a new line. Now put `https://dl.espressif.com/dl/package_esp32_index.json` into the window. Press `OK`, and then click `OK` again.
- Now, press `Tools` > `Board` > `Boards Manager...` and type `ESP32` into the search bar. Then, click the button that says `Install`.
- It'll take a while to install. When it's done, close the window.
- Click on `Tools` > `Board`. Scroll down, and under `ESP32 Arduino`, you should find `Adafruit ESP32 Feather`. Click on it!
- Now, press the Upload button. It looks like this: ![an arrow pointing to the right](upload.png)
- If it works, in a little, a light on your ESP32 Feather should start blinking! Great!
# Shopping
  Now, you need to get your PCB. Your PCB is the thing that connects Napkin. If you want, you can prototype it on a breadboard.  
  OSHPark makes great PCBs. It's okay that you get 3, because you'll want multiple Napkins to protect your house.  
  You can find pictures of the PCB, the Gerber files, the zipped gerber, and the Fritzing files in the [PCB Files](<PCB Files/>) directory. (I downloaded Fritzing while it was still free.)  
  Time to go shopping! Here's a list of stuff you need **for 1 Napkin**:
+ [MicroSD breakout](https://adafru.it/254)
+ [NeoPixel strip](https://adafru.it/3636) (cut to size needed, and can use other neopixels)
+ [PIR motion sensor](https://adafru.it/189)
+ [3 IR LEDs](https://adafru.it/388)
+ [Piezo buzzer](https://adafru.it/160)
+ Speakers with a 3-pin connection (ground, left channel, right channel. **This is your siren! Make it loud!**)
+ [3-pin audio jack](https://adafru.it/2791)
+ [Arducam 5MP module](https://bit.ly/2PjWdNe)
# Soldering
  Are you done? Great! Let's start soldering! You'll need to solder at least 62 points, but don't worry! It's easy.
1. First, let's solder up the MicroSD breakout. You might want to put it on some short wires. You're already more than 1/10 done!
2. Second, solder the piezo buzzer. You might need to extend it, too, so it can make a warning noise. 1/8 of the way there!
3. Third, let's add the speaker. There's only 3 wires to solder to the plug, but it's a very important part!
4. Fourth, solder up the ESP32 Feather. Be careful! Don't worry if it takes a while. You're already 1/2 of the way there!
5. Fifth, solder another very important part: the camera! You're 3/4 of the way done already!
6. Sixth, let's solder up the PIR. You might want to put it on wires, again.
7. Seventh, add your NeoPixels to the mix.
8. For the last step I can help you with, add the IR LEDs. Remember to add resistors!
**DO NOT solder the jumper.** It's to the right of the grid. If you solder it, your thing will short-circuit!
# Setup
  We can finally test everything! Plug in the ESP32 Feather to your computer. Do you immediately see the "CHG" LED rapidly blinking on the Feather? **If not, immediately yank the cord out**, and make an issue on GitHub. If it does, great! Also make sure that your computer detected it. You might need to unplug it and plug it back in to check.
- Remember at the [very start](#testing-your-feather), you opened [`code/setupwizard/setupwizard.ino`](code/setupwizard/setupwizard.ino) with the Arduino IDE? Open that window again.
- Press the upload button. If you need a refresher, it looks like this: ![an arrow pointing to the right](upload.png)
- Open the Serial Monitor. It has a button that looks like this: ![a magnifying glass](serialmonitor.png)
- Make sure your baud rate is set to 9600 baud. There's a dropdown menu that looks like this: ![a dropdown menu with all of the baud numbers](bauddropdown.png)
- Now, reset the ESP32 Feather to restart the sketch. I'll guide you through what it should say. *Sorry I use goto, I'm not doing bad stuff with it!*
# Testing
+ `Welcome to the Napkin setup wizard! Wait a moment as I setup the inputs, outputs, and EEPROM...`  
  - Hopefully it doesn't say `Hmm... I'm having trouble with the EEPROM. Try again by running this code again. If that didn't work, put up a issue on GitHub.`
+ `Done! First, let's setup your PIR. Go behind your PIR, so it can't see you. In five seconds, I'll take 10 snapshots of the PIR pin.`
+ `Taking snapshots...`
+ `Okay, now let's have you make a whole bunch of motion in front of your PIR. Again, in 5 seconds, I'll take 10 snapshots.`
+ `Taking snapshots...`
+ `Hmm... let me figure out if your PIR is reverse...`  
  - Hopefully, it says `It's reverse! Give me a second to save that...`  
  - Or `It's not reverse! Give me a second to save that...`  
  - But not `Hmm... I'm having trouble. Try again by running this code again. If that didn't work, put up a issue on GitHub.`  
+ `Now, let's test the buzzer. In 5 seconds, I'll play a low tone, a medium tone, and then a high tone.`
+ `Did you hear the tones? y/n`  
  - *At this point, you type `y` or `n` into the serial monitor and press enter.*  
  - Hopefully it says `Great!`  
  - But not `Hmm... try making a issue on GitHub to get some assistance.`  
  - Or not `Please type y or n.`  
+ `Cover your ears! In 10 seconds, I'll test the siren.`
+ `Did you hear the tone? y/n `  
  - *At this point, you type `y` or `n` into the serial monitor and press enter.*  
  - Hopefully it says `Great!`  
  - But not `Hmm... try making a issue on GitHub to get some assistance.`.  
  - Or `Please type y or n`.  
+ `Let's try testing your NeoPixels. How many NeoPixels are in your strip? (I would discourage more than 25.)`
  - *At this point, you type the number of NeoPixels in your strip (as a number, not a word for a number) into the serial monitor and press enter.*
+ `Let me save that...`  
+ `Okay, now I have some more questions. First, are your NeoPixels RGBW or RGB?`  
  - *At this point, you type `rgbw` or `rgb` into the serial monitor and press enter.*  
  - If your NeoPixels are `RGBW`:
    + It'll straight away say `The settings are found! Give me a second to save them...`  
  - If your NeoPixels are `RGB`:
    + It'll ask `Great! Now, second: Are your NeoPixels V1 or V2?`  
    + *At this point, you type `v1` or `v2` into the serial monitor and press enter.*  
    + Hopefully it'll now say `The settings are found! Give me a second to save them...`
  - Hopefully it doesn't say any of: `Please type V1 or V2` or `Please type RGBW or RGB.`.
+ `Now, let's test your NeoPixels. Give me a second to set them up...`
+ `Done! You should see all of them turn red, then green, then blue.`  
  - *At this point, all of the NeoPixels in your strip should turn red, then green, then blue.*  
+ `Did that work? Type y or n.`  
  - *At this point, you type `y` or `n` into the serial monitor and press enter.*  
  - Hopefully it says `Great!`  
  - But not `Hmm... try making a issue on GitHub.`  
  - Or not `Please type y or n.`  
# Checking Settings
Yahoo! 😊 You're all done with the setup wizard! But now that you've tested everything and figured out the settings, time to check that the settings are correct.  
Open the file called [`code/settinggetter/settinggetter.ino`](code/settinggetter/settinggetter.ino) with the Arduino IDE.  
Upload the code to your ESP32 Feather using the steps mentioned [above](#setup). Open the Serial Monitor at 9600 baud, and reset the board like you did [before](#setup).  
It should tell you the settings that are stored. If any of them are incorrect, go [back here](#setup) and [back here](#testing) to run the setup wizard again.  
If all of the settings are great, then you're ready to move on! Start thinking, because you're doing this too.  
# Setting Up Smoke
Sadly, I forgot something. You know that smoke detector you bought earlier?
- Well, find your multimeter. You might need to get one, because you'll probably want both voltage and conductivity testing.
- Now, open your smoke detector up. Start poking around with your probes.
- Earmuffs might be handy, because basically you're going to:
  + remove the batteries and plug the detector into your own power source
  + set it off and test where electricity turns on during a fire  
  
Once you've found how it works, **write it down**.  
Think a little bit. Now, when you got your Napkin PCB, did you notice that little 8 by 8 spot of protoboard? It has some labels on it.  
You have access to 3 GPIO pins, power, and ground. You can use a knife to form a mini-circuit. And what will that mini-circuit do? Plug the smoke detector into the ESP32 safely.  
So what are you waiting for?
- Start with using a 3v power supply, a breadboard, a multimeter, and some jumper wires. Earmuffs might be handy here again.
- Cut the traces in the proper places,
- triple-check there are no short circuits,
- and solder on the components.
- Once you're done, solder the jumper that's to the right of the board for your mini-circuit to give power to your circuit.  
  
#
Now, **carefully** plug the ESP32 in to the power source.  
Make sure nothing is getting hot. Then, write an Arduino function to check if there's smoke or not. Quick guide:  
- IO1 is IO16
- IO2 is IO17
- IO3 is IO21  
  
**Yay! You've set up smoke detection!**  
Now, open up [code/template/template.ino](code/template/template.ino) and start coding and researching! Imagine:  
+ a night camera...
+ warning lights that are internet connected...
+ a camera that can make a timelapse at 100x speed for a year without uploading...
+ "Baby Shark" playing when an intruder enters your home...
  
it's endless.  
Anyway, [KTibow](https://github.com/KTibow) out for now! Bye!  
