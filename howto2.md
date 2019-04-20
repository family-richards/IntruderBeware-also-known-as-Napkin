  Thanks for choosing IntruderBeware! The first thing you'll need to do is download this repository. Download the zip of it, and then unzip it.  
  Now, get a ESP32 Feather. You can get one here: https://adafru.it/3405  
  Find the folder called "code". Open it, and find the folder called "setupwizard". Open it, too.  
  Now, make sure you have the Arduino IDE installed. If not, download it here: https://www.arduino.cc/en/Main/Software  
If you need to, restart your computer.  
  When you're back in /code/setupwizard, open the file called setupwizard.ino (or on Windows it might be called just setupwizard). The Arduino IDE should open.  
  Take your ESP32 Feather, and find a matching USB cable. If you've already plugged it in, unplug it.  
  Before we get started, we need to test your ESP32. In the Arduino IDE, click on File > Examples > 01.Basics > Blink.  
Now, click on Tools > Port. Write down all of the numbers and letters. Click away from Tools > Port now.  
Next, plug in your ESP32 Feather. Click on Tools > Port again. Find the combination of numbers and letters that isn't on the list, and click on it.  
  After that, click on File > Preferences. Find the place where it says "Additional Boards Manager URLs:". Click on the icon that looks like this: ![](popout.png)  
If you already have added an additional board manager URL, press enter. Now type "https://dl.espressif.com/dl/package_esp32_index.json" into the window. Press OK, and then click OK again.  
  Now, press Tools > Board > Boards Manager... and type ESP32 into the search bar. Then, click the button that says "Install".  
It'll take a while to install. When it's done, close the window. Now you can finally test your ESP32 Feather!  
  Click on Tools > Board. Scroll down, and under ESP32 Arduino, you should find "Adafruit ESP32 Feather". Click on it! You're so close!  
  Now, press the upload button. It looks like this: ![](upload.png)  
  In a little, your ESP32 Feather should start blinking!  
  Now, you need to get your PCB. OSHPark makes great PCBs. It's okay that you get 3, because you'll want multiple IntruderBewares to protect your house. You can find pictures of the PCB, the Gerber files, and the .fzz files in the /PCB Files/ directory.
  Time to go shopping! Here's a list:
+ MicroSD breakout (https://adafru.it/254)
+ NeoPixel strip (https://adafru.it/3636 (cut to size needed))
+ PIR motion sensor (https://adafru.it/189)
+ 3 IR LEDs (https://adafru.it/388)
+ Piezo buzzer (https://adafru.it/160)
+ Speakers with 3-pin (ground, left channel, right channel)
+ 3-pin audio jack (https://adafru.it/2971)
+ Arducam 5MP module (https://bit.ly/2PjWdNe)

  Are you done? Great! Let's start soldering! You'll need to solder at least 63 points.
1. First, let's solder up the MicroSD breakout. You might want to put it on 1 in. wires. You're already more than 1/10 done!
