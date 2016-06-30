#!/bin/python
#This script was authored by AndrewH7 and belongs to him (www.instructables.com/member/AndrewH7)
#You have permission to modify and use this script only for your own personal usage
#You do not have permission to redistribute this script as your own work
#Use this script at your own risk
#
#		INSTALL INSTRUCTIONS FOR VOLUMIO2 
#
#apt-get update
#apt-get install gcc python-dev python-pip i2c-tools libi2c-dev python-smbus 
#pip install RPi.GPIO 
#
#put this file on /home/pi/off_button.py
#
#sudo nano /etc/rc.local
#          before exit 0; add   python /home/pi/off_button.py
#
#

import RPi.GPIO as GPIO
import os

#
# We chose GPIO16 beacuse is unused by HiFiBerry DAC+, Digi+ and Amp+ (i2C and gpio 18 to 21)
#It's very important the pin is an input to avoid short-circuits
#The pull-up resistor means the pin is high by default

gpio_pin_number=16

GPIO.setmode(GPIO.BCM)

GPIO.setup(gpio_pin_number, GPIO.IN, pull_up_down=GPIO.PUD_UP)


try:
    #Use falling edge detection to see if pin is pulled 
    #low to avoid repeated polling
    GPIO.wait_for_edge(gpio_pin_number, GPIO.FALLING)
    #Send command to system to shutdown
    os.system("sudo shutdown -h now")
    
except:
    pass

#Revert all GPIO pins to their normal states (i.e. input = safe)
GPIO.cleanup()


