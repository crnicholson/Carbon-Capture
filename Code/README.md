# Carbon Removal Scripts

There are two scripts here: one to calculate the amount of CO2 capture and one to measure the amount of CO₂ captured.

## Carbon removal calculator

There are two different files for the carbon capture calculator. The ```co2CalculatorBox.py``` calculates captured CO₂ from either the increase or decrease of CO₂ in a closed environment, like a box. On the other hand, ```co2CalculatorPump.py``` calculates CO₂ captured from the air going through the capture membrane, measures the CO₂ difference between the inlet and outlet, and then does some math to find the CO₂ captured.  Both of these can be configured to measure the regeneration of the sorbent and the capture of CO₂. However, ```co2CalculatorBox.py``` is already configured to work in a regeneration style, and ```co2CalculatorPump.py``` is configured to work in a capture style. 

### Steps to use this code

1. Open up a Google Colab or your preferred runtime/editor
2. Fill out the variables at the top of the file
3. Press run, and look at the output in the terminal

### co2CalculatorPump

To configure this snippet to work in a system releasing captured CO₂, find this line: ```ppmDifference = inlet - outlet``` and replace it with ```ppmDifference = outlet - inlet```. Then, change the inlet and the outlet variables accordingly.

### co2CalculatorBox

To configure this snippet to work in a system measuring a decrease in CO₂, find this line: ```ppmRise = ppmEnd - ppmStart``` and replace it with ```ppmRise = ppmStart - ppmEnd```. Then, change the ppmEnd and the ppmStart variables accordingly.

## SCD30 CO2 sensor code

This code is based on code from Adafruit that's easier to paste into a spreadsheet. 

### Prerequisites

This mini tutorial assumes you have some exposure to electronics. Knowledge of Arduino would greatly improve your time doing this.

### Setup

To use this code, first install Adafruit's SCD30 library (https://github.com/adafruit/Adafruit_SCD30) on your Arduino IDE (this is free software you can find online). Then, connect the SCD30 to a 3.3v tolerant Arduino/MCU (another option is to use a level converter) by connecting the SDA and SCL pins of SCD30 to the Arduino pins A4 and A5, respectively. After that, upload the code. To calibrate your sensor, follow Adafruit's guide: https://github.com/adafruit/Adafruit_SCD30.

### Usage

First, open up the serial monitor in Arduino IDE by pressing the little magnifying glass. Then, press the little timestamp button to make sure you know when you got your data. Run your sensor ten minutes before your test to properly warm it up. Then, copy the data from the serial monitor. After that, paste the copied data into a spreadsheet. Once in a spreadsheet, select the column where you pasted the data, and go to ```Data > Split text to columns```. This is pictured below:

<img width="639" alt="Screenshot 2023-09-22 at 7 32 49 PM" src="https://github.com/charlienicholson3/scd30Code/assets/83499056/8134be9d-b50c-4334-8e48-10451ed9d581">

Note: In this picture, the data had already been split into columns, but you get the point.

### Anaylsis

To visualize your data, choose some titles for your columns. I chose the titles Temp, Time, CO2 ppm, and Humidity. Then, select all your columns, and press the chart button to create a graph, like pictured below. Feel free to change your graph style, but in my opinion, the default one is the best.

<img width="1242" alt="Screenshot 2023-09-22 at 7 37 53 PM" src="https://github.com/charlienicholson3/scd30Code/assets/83499056/10e10939-8838-4c5b-a179-1cf996967b2d">

Note: I already made the graph, but you get the idea.

Now you can visualize your data from your CO2 sensor!
Thanks again to Adafruit for the majority of the work.