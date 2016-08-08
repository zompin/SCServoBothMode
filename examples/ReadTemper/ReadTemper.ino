#include <SoftwareSerial.h>
#include <SCServoBothMode.h>

SCServo SERVO(SOFT_MODE);

void setup(){
	SERVO.init(115200);
	Serial.begin(115200);
	delay(500);
}

void loop(){
	int T = SERVO.ReadTemper(1);
	if(T!=-1){
		Serial.println(T);
	}
	delay(50);
}
