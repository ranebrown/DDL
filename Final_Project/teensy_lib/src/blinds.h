#ifndef BLINDS_H
#define BLINDS_H

#include "WProgram.h"

extern int currRot;
extern int maxRot;
extern int dir;

// turn servo left
void left();

// turn servo right
void right();

// stop servo
void stop();

// count rotations
void rotCount();

// set blinds open/close to given percentage
void setPerc(int p);

#endif