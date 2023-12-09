/*
 * CLCD_interface.h
 *
 *  Created on: Oct 11, 2023
 *      Author: hp
 */

#ifndef MINE_HAL_CLCD_CLCD_INTERFACE_H_
#define MINE_HAL_CLCD_CLCD_INTERFACE_H_

#include"CLCD_config.h"


//#if CLCD_MODE==4
//#define FORTH_BITS  0x28
//#elif CLCD_MODE==8
#define EIGHT_BITS   0X38   //2lines and 5x8font
//#endif


#define Lcd_DisplayOn_CursorOff  0x0c   //00001100 display on cursor off and don't blink character
#define Lcd_DisplayOn_CursorOn   0x0e   //00001110 display on cursor on and don't blink character
#define Lcd_DisplayOff_CursorOff 0x08   //00001000 display off cursor off and don't blink character
#define Lcd_Clear                0x01   //00000001 replace all characters with ascii  'space'
#define Lcd_EntryMode            0x06   //00000110 shift cursor from left to right
#define Lcd_Home                 0x02   //00000010 return cursor to first line initail position
#define Lcd_SetCursor            0x80   //10000000 return cursor to the first position in lcd
#define Lcd_CGRAM                0X40   //01000000 the first place at CGRAM




#define CLCD_ROW_1  1
#define CLCD_ROW_2  2




#define CLCD_COL_1 1
#define CLCD_COL_2 2
#define CLCD_COL_3 3
#define CLCD_COL_4 4
#define CLCD_COL_5 5
#define CLCD_COL_6 6
#define CLCD_COL_7 7
#define CLCD_COL_8 8
#define CLCD_COL_9 9
#define CLCD_COL_10 10
#define CLCD_COL_11 11
#define CLCD_COL_12 12
#define CLCD_COL_13 13
#define CLCD_COL_14 14
#define CLCD_COL_15 15
#define CLCD_COL_16 16




void CLCD_voidInit(void);
void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidSendCommand(u8 Copy_u8Command);
void CLCD_voidClearScreen(void);
void CLCD_voidSendString(const u8 *Copy_u8PtrString);
void CLCD_voidSetPosition(u8 Copy_u8Row,u8 Copy_u8Col);

void CLCD_voidSendExtraChar(u8 Copy_u8Row ,u8 Copy_u8Col);


void CLCD_voidSendNum(u16 Copy_u16Num);











#endif /* MINE_HAL_CLCD_CLCD_INTERFACE_H_ */
