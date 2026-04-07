Smart Distance Alert System :

Components Used –  
Arduino Uno 

A Ultrasonic Sensor 

A buzzer 

A LDR 

3 LED’s 

4 Resistors 

Jumper wires 


Code Logic- The ultrasonic sensor sends a soundwave 
and receives it back and using the pulseIn() function the 
time the wave took to come back once sent is known. 
Using the classic speed formula distance is calculated 
since the speed of sound is known. Then if the distance 
is greater than 60 then its safer region i.e.white light 
will glow with no buzzer sound and also an option to 
control the brightness of the led using LDR.  
If distance detected is between 20-60 then the object is 
in a caution region and yellow light will start to blink 
and buzzer starts to ring and the buzzer sound 
frequency ,led blinking speed changes with distance as 
distance decreasing increases the speed and frequency 
of LED,buzzer and this is done with the help of map() 
function between the distance and the duration.  
If the distance is less then 20 then the red LED will glow 
with buzzer to be constantly producing sound which 
represents danger zone.  

Tinkedcad Link -  https://www.tinkercad.com/things/cbODvxde2Tu-section-b-31smart-distance-alert-system?sharecode=aaGa07rtBMKP6W-fNsr4Za5a6PzzFk8xaH-6jiAubys

Schematic Diagram - 
<img width="1191" height="890" alt="image" src="https://github.com/user-attachments/assets/94691aad-0052-442e-b56d-6f44c9e0e8dc" />
