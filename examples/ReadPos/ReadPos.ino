#include <SoftwareSerial.h>
#include <SCServoBothMode.h>

SCServo SERVO(SOFT_MODE);
int LEDpin = 13;

void setup(){
	pinMode(LEDpin,OUTPUT);
	digitalWrite(LEDpin, HIGH);
	SERVO.init(115200);
	delay(500);
	SERVO.EnableTorque(1, 1);
}

void loop(){
	int pos = SERVO.ReadPos(2);
	if(pos!=-1){
		digitalWrite(LEDpin, LOW);
		SERVO.WritePos(1, pos, 0);
	}else{
		digitalWrite(LEDpin, HIGH);
	}
	delay(50);
}
