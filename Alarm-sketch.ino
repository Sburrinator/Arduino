#define buzzer 9 //buzzer pin
#define led 8    //led pin
#define trig 13  //trigger pin
#define echo 12  //echo pin
void setup() { 
    pinMode(trig, OUTPUT); 
    pinMode(echo, INPUT);
    Serial.begin(9600);
}  
void loop() {   
    digitalWrite(trig, LOW);
    digitalWrite(trig, HIGH);  
    unsigned long time = pulseIn(echo, HIGH);
    float cm =0.03438 * time / 2;                   //it calculates the distance thanks to the duration of the signal
    Serial.print("Cm = " + String(cm) + "cm\n");
    if(cm<40){                                      //the buzzer rings and the led blinksif the distance is <40 centimeters
      digitalWrite(led, HIGH);                      
      tone(buzzer, 3000, 1000);
      delay(1000);
      digitalWrite(led, LOW);
    }
    delay(100);
}
