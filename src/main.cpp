#include <Arduino.h>
#include <time.h>


int previous_time = 0;
int current_time = 0;
bool solenoid_state = false; // False for open

void setup() {
    Serial.begin(9600);
    while(!Serial){
    }
    Serial.println("Starting Program...");
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
}

void solenoidOn(){
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
}

void solenoidOff(){
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
}

void loop() {
    
    current_time = millis();

    if(current_time - previous_time >= 100am){
        if(solenoid_state){
            solenoidOn();
        } else{
            solenoidOff();
        }
        previous_time = millis();
        solenoid_state = !solenoid_state;
    }
    
}

