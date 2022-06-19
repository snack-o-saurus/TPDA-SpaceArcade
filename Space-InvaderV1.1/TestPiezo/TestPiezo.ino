//https://www.watelectronics.com/piezoelectric-sensor-and-its-operation/
const int ledPin = 13; // LED is connected to pin D13
const int knockSensor = 19; //piezo element is connected to Analog input A0 (pin 40)
const int threshold = 100; //specified threshold limit when the detected sound is either knock or not

//altering variables
int sensorReading = 0; // declaration of a variable to store the value sent from sensor pin
int ledState = LOW; // declaration of a variable to store the status of LED, to toggle the light

void setup (){
pinMode (ledPin, OUTPUT); // declaring ledPin as the output pin
Serial.begin (9600); // using of serial port
}

void loop (){}
sensorReading = analogRead (knockSensor);
if (sensorReading >= threshold)}
ledState = !ledState; // toggle the state of the ledPin
digitalWrite (ledPin, ledState); //automatically update the status of LED pin
serial.println(“Knock”); // sends back the Knock string to the computer
}
delay(100); // declared to avoid any kind of overloading of the serial port buffer
}
