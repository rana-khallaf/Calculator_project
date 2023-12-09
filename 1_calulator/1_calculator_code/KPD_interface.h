/*
 * KPD_interface.h
 *
 *  Created on: Oct 12, 2023
 *      Author: hp
 */

#ifndef MINE_HAL_KPD_KPD_INTERFACE_H_
#define MINE_HAL_KPD_KPD_INTERFACE_H_

#define NOT_PRESSED  0xff

void KPD_voidInit(void);


u8 KPD_u8GetPressed(void);

#endif /* MINE_HAL_KPD_KPD_INTERFACE_H_ */
