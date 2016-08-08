#include <SoftwareSerial.h>
#include <SCServoBothMode.h>

SCServo SERVO(SOFT_MODE);

void setup(){
	SERVO.init(115200);
	Serial.begin(115200);
	delay(500);
}

void loop(){
	int vol = SERVO.ReadVoltage(1);
	if(vol!=-1){
		Serial.println(vol);
	}
	delay(50);
}
