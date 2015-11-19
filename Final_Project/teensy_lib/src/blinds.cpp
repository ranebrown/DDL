#include "blinds.h"

int currRot = 0;
int maxRot = 0;
int dir = 0;

// turn servo left
void left() {
	delay(100);
	analogWriteFrequency(A9, 270);
	analogWrite(A9,127);
	dir = 0;
}

// turn servo right
void right() {
	delay(100);
	analogWriteFrequency(A9, 600);  
	analogWrite(A9,127);
	dir = 1;
}

// stop servo
void stop() {
	delay(100);
	analogWrite(A9,0);
}

// count rotations
void rotCount() {
	if(digitalRead(2) == 0) {
		if(dir == 1)
			currRot++;
		else 
			currRot--;
		delay(100);
	}
}

// set blinds open/close to given percentage
void setPerc(int p) {
	int x = (maxRot*p)/100;
	if(x > maxRot) {
		x = maxRot;
	}
	if(x > currRot) {
		right();
	  	while(currRot < x) {
            rotCount();
        }
        stop();
	}
	else if(x < currRot) {
		left();
		while(currRot > x) {
            rotCount();
        }
        stop();
	}
}
