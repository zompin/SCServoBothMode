#include <SoftwareSerial.h>
#include <SCServoBothMode.h>

SCServo SERVO(SOFT_MODE);

void setup(){
	SERVO.init(115200);
	delay(500);
	SERVO.EnableTorque(1, 1);
	SERVO.EnableTorque(2, 1);
	delay(500);
}

void loop(){
	SERVO.RegWritePos(1, 1023, 6000);
	SERVO.RegWritePos(2, 1023, 6000);
	SERVO.RegWriteAction();
	delay(6200);
	
	SERVO.RegWritePos(1, 0, 3000);
	SERVO.RegWritePos(2, 0, 3000);
	SERVO.RegWriteAction();
	delay(3200);
}
