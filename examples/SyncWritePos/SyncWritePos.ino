#include <SoftwareSerial.h>
#include <SCServoBothMode.h>

SCServo SERVO(SOFT_MODE);
byte ID[2];
void setup(){
	SERVO.init(115200);//init Serial baudrate
	delay(500);
	SERVO.EnableTorque(1, 1);
	SERVO.EnableTorque(2, 1);
	ID[0] = 1;
	ID[1] = 2;
}

void loop(){
	SERVO.SyncWritePos(ID, 2, 0, 4000);
	delay(4200);
	SERVO.SyncWritePos(ID, 2, 1023, 4000);
	delay(4200);
}
