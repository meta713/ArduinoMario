int SpeakerPin = 8;
unsigned int i,j;

String str = "1UP";

void setup(){
pinMode(SpeakerPin, OUTPUT);
Serial.begin(9600);
}

void mario_1up(){
for (i=0; i<97; i++){
digitalWrite(SpeakerPin,HIGH);
delayMicroseconds(379);
digitalWrite(SpeakerPin,LOW);
delayMicroseconds(379);
}
for (i=0; i<235; i++){
digitalWrite(SpeakerPin,HIGH);
delayMicroseconds(319);
digitalWrite(SpeakerPin,LOW);
delayMicroseconds(319);
}
for (i=0; i<396; i++){
digitalWrite(SpeakerPin,HIGH);
delayMicroseconds(189);
digitalWrite(SpeakerPin,LOW);
delayMicroseconds(189);
}
for (i=0; i<315; i++){
digitalWrite(SpeakerPin,HIGH);
delayMicroseconds(238);
digitalWrite(SpeakerPin,LOW);
delayMicroseconds(238);
}
for (i=0; i<353; i++){
digitalWrite(SpeakerPin,HIGH);
delayMicroseconds(212);
digitalWrite(SpeakerPin,LOW);
delayMicroseconds(212);
}
for (i=0; i<471; i++){
digitalWrite(SpeakerPin,HIGH);
delayMicroseconds(159);
digitalWrite(SpeakerPin,LOW);
delayMicroseconds(159);
}
}


void loop(){
  if (Serial.available() > 0) {
    String strBuf = Serial.readStringUntil('\n');
    if(str.compareTo(strBuf) == 0){
      mario_1up();
      delay(500);
    }
  }
  delay(100);
}
