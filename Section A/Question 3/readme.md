Reaction Time Tester :

Components Used –  
Arduino UNO 
2 LED’s 
2 Resistors 
A Button 
Jumper wires 

Code Logic- The code uses millis() function to 
determine the amount of time elapsed without 
completely stopping the program. If the user is waiting 
then a random value is assigned to the wait time and if 
the button is not pressed the wait time is elapsed then 
the LED starts to glow until the user presses the button 
and the time the user took to press the button with the 
led glow time as start is shown in serial monitor and an 
extra feature Is if the user presses the button before the 
LED glows then “false start” is displayed in serial 
monitor and resets again.  

Tinkercad Link-https://www.tinkercad.com/things/4mD06a0kSD2-section-a-3reaction-time-tester?sharecode=Kea5OxwogvTQhLrNwU2bwpSQlpbVmjStxFN24KOzrSs

Schematic Diagram - <img width="1136" height="878" alt="image" src="https://github.com/user-attachments/assets/2af893d3-a533-441e-98d7-7de624c281d9" />
