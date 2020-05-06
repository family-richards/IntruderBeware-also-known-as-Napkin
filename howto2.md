# Setup
  Thanks for choosing Napkin! The first thing you'll need to do is download this repository. Download the [zip of it](https://github.com/family-richards/Napkin/archive/master.zip) and unzip it, or clone it with `git clone https://github.com/family-richards/Napkin.git`.  
  Napkin is powered by the [ESP32 Feather](https://adafru.it/3405).    
  Find the folder called [`code`](code/). Open it, and find the folder called [`setupwizard`](code/setupwizard/). Open it, too.  
  Now, make sure you have the Arduino IDE installed. If not, [download it](https://www.arduino.cc/en/Main/Software).  
If you need to, restart your computer.  
  When you're back in [`/code/setupwizard`](code/setupwizard/), open the file called [`setupwizard.ino`](code/setupwizard/setupwizard.ino) with the  Arduino IDE.  
  Take your ESP32 Feather, and find a matching USB cable. If you've already plugged it in, unplug it.  
  Before we get started, we need to test your ESP32. In the Arduino IDE, click on File > Examples > 01.Basics > Blink.  
# Programming
Now, click on Tools > Port. Write down all of the numbers and letters. Click away from Tools > Port now.  
Next, plug in your ESP32 Feather. Click on Tools > Port again. Find the combination of numbers and letters that isn't on the list, and click on it.  
  After that, click on File > Preferences. Find the place where it says "Additional Boards Manager URLs:". Click on the icon that looks like this: ![Two side-by-side windows](popout.png)  
If you already have added an additional board manager URL, press enter. Now type `https://dl.espressif.com/dl/package_esp32_index.json` into the window. Press OK, and then click OK again.  
  Now, press Tools > Board > Boards Manager... and type ESP32 into the search bar. Then, click the button that says `Install`.  
It'll take a while to install. When it's done, close the window. Now you can finally test your ESP32 Feather!  
  Click on Tools > Board. Scroll down, and under ESP32 Arduino, you should find "Adafruit ESP32 Feather". Click on it! You're so close!  
  Now, press the upload button. It looks like this: ![an arrow pointing to the right](upload.png)  
  In a little, your ESP32 Feather should start blinking!  
# Shopping
  Now, you need to get your PCB. OSHPark makes great PCBs. It's okay that you get 3, because you'll want multiple IntruderBewares to protect your house. You can find pictures of the PCB, the Gerber files, and the .fzz files in the /PCB Files/ directory.
  Time to go shopping! Here's a list of stuff you need:
+ MicroSD breakout (https://adafru.it/254)
+ NeoPixel strip (https://adafru.it/3636 (cut to size needed, and can use other neopixels))
+ PIR motion sensor (https://adafru.it/189)
+ 3 IR LEDs (https://adafru.it/388)
+ Piezo buzzer (https://adafru.it/160)
+ Speakers with 3-pin (ground, left channel, right channel)
+ 3-pin audio jack (https://adafru.it/2791)
+ Arducam 5MP module (https://bit.ly/2PjWdNe)
+ Loud siren/buzzer (https://www.digikey.com/short/zz0phr)
# Soldering
  Are you done? Great! Let's start soldering! You'll need to solder at least 62 points.
1. First, let's solder up the MicroSD breakout. You might want to put it on 1 in. wires. You're already more than 1/10 done!
2. Second, solder the piezo buzzer. 1/8 of the way there!
3. Third, let's add the speaker. There's only 3 wires to solder to the plug, but it's a very important part!
4. Fourth, solder up the ESP32 Feather! Don't worry if it takes a while. You're already 1/2 of the way there!
5. Fifth, solder a very important part: the camera! You're 3/4 of the way done already!
6. Sixth, let's solder up the PIR. You may want to use female headers, so you can plug and unplug it.
7. Seventh, add your NeoPixels to the mix. Remember, a lot adds up!
8. For the last step I can help you with, add the IR LEDs. Remember to add resistors!  
DO NOT solder the jumper.  
# Communication
  We can finally test everything! Plug in the ESP32 Feather to your computer. Do you immediately see the "CHG" LED rapidly blinking and that your computer detects the ESP32 Feather? If not, immediately YANK the cord out, and make an issue on GitHub. If it does, great! Go on to the next step.  
  Now, find the window in the Arduino IDE titled `setupwizard.ino`. Press the upload button. If you need a refresher, it looks like this: ![an arrow pointing to the right](upload.png)  
  Now, open the Serial Monitor. It has a button that looks like this: ![](serialmonitor.png)  
  Make sure your baud rate is set to 9600 baud. There's a dropdown menu that looks like this:  
  ![a dropdown menu with all of the baud numbers](bauddropdown.png)  
  Next, you can reset the ESP32 Feather! I'll guide you through what it should say.   
# Testing
+ Welcome to the IntruderBeware setup wizard! Wait a moment as I setup the inputs, outputs, and EEPROM...  
Hopefully it doesn't say this: Failed to initialise EEPROM!  
+ Done! First, let's setup your PIR. Go behind your PIR, so it can't see you. In five seconds, I'll take 10 snapshots of the PIR pin.  
+ Taking snapshots...  
+ Okay, now let's have you make a whole bunch of motion. Again, in 5 seconds, I'll take 10 snapshots.  
+ Taking snapshots...  
+ Hmm... let me figure out if your PIR is reverse...  
Hopefully, it says this: It's reverse! Give me a second to save that...  
Or this: It's not reverse! Give me a second to save that...  
But not this: Hmm... I'm having trouble. Try again by resetting this, and put up a issue on GitHub.  
+ Now, let's test the buzzer. In 5 seconds, I'll play a low tone, a medium tone, and then a high tone.  
+ Did you hear the tones? y/n  
Hopefully it says this: Great!  
But not this: Hmm... try making a issue on GitHub.  
Or not this: Please type y or n.  
+ Cover your ears! In 5 seconds, I'll test the siren.  
+ Did you hear the tone? y/n  
Hopefully it says this: Great!  
But not this: Hmm... try making a issue on GitHub.  
Or this: Please type y or n.  
+ Let's try testing your NeoPixels. How many NeoPixels are in your strip? (I would discourage more than 25.)  
+ Let me save that...  
+ Okay, now I have some more questions. First, are your NeoPixels RGBW or RGB?  
This is one way it might say: Great! Now, second: Are your NeoPixels V1 or V2?  
Hopefully it says this: The settings are found! Give me a second to save them...  
But not this: Please type V1 or V2.
+ It **might** say Great! Now, second: Are your NeoPixels V1 or V2?  
It might say this: The settings are found! Give me a second to save them...  
But hopefully it doesn't say this: Please type RGBW or RGB.  
+ Now, let's test your NeoPixels. Give me a second to set them up...  
+ Done! You should see all of them turn red, then green, then blue.
+ Did that work? Type y or n.
Hopefully it says this: Great!  
But not this: Hmm... try making a issue on GitHub.  
Or not this: Please type y or n.  
# Checking Settings
Yahoo! 😊 You're all done with the setup wizard! But now that you've tested everything and figured out the settings, time to check that the settings are correct.  
Your computer should still have its file explorer open, underneath of `Blink` and `setupwizard`. Bring the file explorer application to the front.  
Navigate out of the `setupwizard` folder, and find the folder called [`/code/settinggetter`](code/settinggetter/). Open that folder.  
Once you're in [`/code/settinggetter`](code/settinggetter/), open the file called [`settinggetter.ino`](code/settinggetter/settinggetter.ino). The Arduino IDE should open.  
Upload the code to your ESP32 Feather using the steps mentioned above [here.](#programming)  
Open the Serial Monitor at 9600 baud, and reset the board (more detailed instructions [here](#communication)). 
It should tell you the settings that are stored. If any of them are incorrect, go [back here](#communication) and [back here](#testing) to run the setup wizard again.
If all of the settings are great, then I have a little [suprise for you to enjoy!](code/suprise.md) Once you're done enjoying it, it's time to get serious!
# Setting Up Smoke
Sadly, I forgot something. You know that smoke detector you bought earlier? Well, find your multimeter. If you don't have a multimeter, ask yourself if you're really the type of person for Napkin.  
Now, open your smoke detector up. Start poking around. Earmuffs might be handy, because you might want to test the alarm while you're probing around.  
Think a little bit. Now, when you got your Napkin PCB, did you notice that little 8 by 8 spot of protoboard? It has some labels on it.  
You have access to 3 GPIO pins, power, and ground. You can use a knife to form a mini-circuit. And what will that mini-circuit do? Use miscellaneous parts to convert some pins on the smoke detector into something the ESP32 can understand.  
So what are you waiting for? Start with using a 3v power supply, a breadboard, a multimeter, and some jumper wires. Earmuffs might be handy here again.  
Eventually, cut the traces in the proper places, triple-check there are no short circuits, and solder on the components. Once you're done, solder the jumper that's to the right of the board for your mini-circuit to give power to your circuit.  
Make sure nothing is getting hot. Then, write a function to check if there's smoke or not. Don't know how to write an Arduino program? Reconsider Napkin.  
Are you still convinced that Napkin is right for you? All right, all right.  
You know, it's pretty good. You get a safe home in exchange for pressing 100 keys and clicking on buttons 100 times, and you get a safe home and have a interesting, fun project.  
Well, find the template folder and open up template.ino. Remember this is a WIP (Work In Progress), so it may not be all the way working.    
Anyway, [KTibow](https://github.com/KTibow) out for now! Bye!
