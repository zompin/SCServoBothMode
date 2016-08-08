#include <SoftwareSerial.h>
#include <SCServoBothMode.h>

SCServo SERVO(SOFT_MODE);
int i;

void setup(){
	SERVO.init(115200);
	delay(250);
	SERVO.EnableTorque(0xfe, 1);
	SERVO.WritePos(0xfe, 0, 1000);
	delay(1200);
}

void loop(){
	for(i = 0; i < 1024; i++){
		SERVO.WritePos(0xfe, i, 20);
		delay(20);
	}
	for(i = 1024; i > 0; i--){
		SERVO.WritePos(0xfe, i, 20);
		delay(20);
	}
}
