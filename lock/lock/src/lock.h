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
 * returns 0 for success, 1 for fail
 */
uint32_t lock();

/*
 * unlock deadbolt
 * returns 0 for success, 1 for fail
 */
uint32_t unlock();

#endif /* LOCK_H_ */
