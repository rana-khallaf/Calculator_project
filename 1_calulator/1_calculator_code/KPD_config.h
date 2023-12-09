/*
 * KPD_config.h
 *
 *  Created on: Oct 12, 2023
 *      Author: hp
 */


#include"DIO_interface.h"


#ifndef MINE_HAL_KPD_KPD_CONFIG_H_
#define MINE_HAL_KPD_KPD_CONFIG_H_


#define KPD_PORT  DIO_PORTB


#define KPD_ROW_INIT  DIO_PIN4
#define KPD_ROW_END  DIO_PIN7

#define KPD_COL_INIT  DIO_PIN0
#define KPD_COL_END   DIO_PIN3



#define KPD_R0   DIO_PIN4
#define KPD_R1   DIO_PIN5
#define KPD_R2   DIO_PIN6
#define KPD_R3   DIO_PIN7

#define KPD_C0   DIO_PIN0
#define KPD_C1   DIO_PIN1
#define KPD_C2   DIO_PIN2
#define KPD_C3   DIO_PIN3






#define MAX_ROW     4
#define MAX_COL     4

#define KPD_VALUES  {{7,8,9,'/'},{4,5,6,'*'},{1,2,3,'-'},{'&',0,'=','+'}}





                     // col1 col2 clo3 col4
u8 KPD_u8Buttons[4][4]= {{'7','8','9','/'},      // row1
                        {'4','5','6','*'},         // row2
					    {'1','2','3','-'},           // row3
				        {'&','0','=','+'}           // row4

};

/*

u8 KPD_u8Buttons[4][4]=
		{
				{1,2,3,4},
				{5,6,7,8},
				{9,10,11,12},
				{13,14,15,16}
		};
*/


#endif /* MINE_HAL_KPD_KPD_CONFIG_H_ */
