#define led 13          //pin to be used for the red led
#define buzzer 12       //pin to be used for the Piezo buzzer

char data = 0;

void setup(){
    pinMode(led, OUTPUT);
    pinMode(buzzer, OUTPUT);
    Serial.begin(9600);
}

void animation(){
    Serial.println("Starting animation");
    /*Let the animation go on for 10 times*/
    for(unsigned char x=0; x<10; x++){ 
        digitalWrite(led, HIGH);
        tone(buzzer, 2000, 250);
        delay(1000);
        digitalWrite(led, LOW);
        noTone(buzzer);
        delay(1000);
    }
    Serial.println("Ending animation");
}

void loop(){
    if(Serial.available() > 0){ 
        data = Serial.read();       //read the data from the module if available
        Serial.print("> ");         //user entered commands will contain that prompt on the monitor
        Serial.println(data);
        if (data == '1') {
            animation();
        }
        else {
            Serial.println("Waiting...");
            digitalWrite(led, LOW);
        }
    }
}

