Thanks for making the choice to chose IntruderBeware! Let's start setting things up!  
The first thing you'll need to do is get your PCB. OSHPark makes great PCBs.  
Then, start soldering to your PCB. Here's a shopping list:  
3 IR LEDs, with appropiate resistors. The supply voltage is 3.3V.  
A short strip of NeoPixels, which you can find on AdaFruit.  
1 Arducam 5MP camera module (find it at http://www.arducam.com/product/arducam-5mp-plus-spi-cam-arduino-ov5642/)  
1 Adafruit SD card reader  
1 PIR motion sensor  
ESP32 Feather board, also from Adafruit.  
A loud buzzer (I mean, like a buzzer that can be 100dB at 16V)  
A quieter buzzer (you might find this type in electronic kits)  
A smoke detector  
Something to turn the signal from a smoke detector into something the Feather can understand  
And that's it! Give yourself a pat on the back.  
Before you start soldering, remember to not solder the jumper next to the perfboard for the smoke detector until you've cut all of the places that need to be cut in order to make your circuit. Soldering the jumper without cutting any of the traces will create a short circuit. Also, remove the IR filter on the camera.
Now, begin the laborious task of soldering everything. Don't forget to add the resistors for the IR LEDs.  
Okay. Now, plug in the ESP32 into your computer. If it works, yay! If it doesn't, immediately unplug the Feather and create an issue on GitHub.  
Next, follow Adafruit's excellent guide on setting up the Feather, which can be found here: bit.ly/2DkHflr  
Once set up, upload the setup wizard. It should walk you through testing your IntruderBeware.  
If everything works, that's great! Else, create an issue on GitHub.  
Before your IntruderBeware is ready to use, it needs a case! I designed a case in TinkerCad.  
You can download the case here: https://www.tinkercad.com/things/1xVMmSq07KZ  
And you can download the lid here: https://www.tinkercad.com/things/261wE7LMHAP  
For a reminder, this is still a work in progress!
