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
	SERVO.WritePos(1, 1023, 4000);
	SERVO.WritePos(2, 1023, 4000);
	delay(4200); 
	SERVO.WritePos(1, 0x0000, 3000);
	SERVO.WritePos(2, 0x0000, 3000);
	delay(3200);
	SERVO.WritePos(1, 1023, 2000);
	SERVO.WritePos(2, 1023, 2000);
	delay(2200);
	SERVO.WritePos(1, 0x0000, 1000);
	SERVO.WritePos(2, 0x0000, 1000);
	delay(1200);
}
