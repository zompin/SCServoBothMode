#include <SoftwareSerial.h>
#include <SCServoBothMode.h>

SCServo SERVO(SOFT_MODE);

void setup(){
	SERVO.init(115200);
	delay(500);
	SERVO.EnableTorque(1, 1);
	delay(500);
	SERVO.WriteLimitAngle(1, 0, 0);
	delay(500);
}

void loop(){
	SERVO.WriteSpe(1, 511);
	delay(5000);
	SERVO.WriteSpe(1, 0);
	delay(2000);
	SERVO.WriteSpe(1, -511);
	delay(5000);
	SERVO.WriteSpe(1, 0);
	delay(2000);
}
