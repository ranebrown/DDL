/*
 * lock.h
 *
 *  Created on: Oct 14, 2015
 *      Author: Rane
 */

#ifndef LOCK_H_
#define LOCK_H_

/*
 * Lock deadbolt
 *
 */
void lock();

/*
 * unlock deadbolt
 *
 */
void unlock();

/*
 * calculates the value needed to set the specified frequency
 */
int freq(float f);

/*
 * delay in seconds
 */
void delaySec();

#endif /* LOCK_H_ */
