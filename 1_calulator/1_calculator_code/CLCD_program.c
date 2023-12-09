/*
 * CLCD_program.c
 *
 *  Created on: Oct 11, 2023
 *      Author: hp
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"CLCD_config.h"
#include"CLCD_interface.h"
#include"CLCD_private.h"
#include "CLCD_extrachar.h"
#include <util/delay.h>


void CLCD_voidInit(void)
{
//#if CLCD_MODE==8
	_delay_ms(45);
	DIO_voidSetPortDirection(CLCD_DATA_PORT,PORT_DIR_OUTPUT);
	DIO_voidSetPinDirection(CLCD_CONTROL_PORT,CLCD_RS,PIN_DIR_OUTPUT);
	DIO_voidSetPinDirection(CLCD_CONTROL_PORT,CLCD_RW,PIN_DIR_OUTPUT);
	DIO_voidSetPinDirection(CLCD_CONTROL_PORT,CLCD_EN,PIN_DIR_OUTPUT);

	//to return the cursor to his first pos in first line
	CLCD_voidSendCommand(Lcd_Home);
	_delay_ms(1);

	CLCD_voidSendCommand(EIGHT_BITS);
	_delay_ms(1);

	CLCD_voidSendCommand(Lcd_DisplayOn_CursorOff);
	_delay_ms(1);

	CLCD_voidClearScreen();

	CLCD_voidSendCommand(Lcd_EntryMode);
	_delay_ms(1);


//#elif CLCD_MODE==4
//#endif


}



void CLCD_voidSendData(u8 Copy_u8Data)
{

//#if CLCD_MODE==8
DIO_voidSetPortValue(CLCD_DATA_PORT,Copy_u8Data);
DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RS,PIN_VAL_HIGH);
DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RW,PIN_VAL_LOW);

CLCD_voidSendFallingEdge();

//#elif CLCD_MODE==4

//#endif
_delay_ms(1);



}



void CLCD_voidSendCommand(u8 Copy_u8Command)
{
//#if CLCD_MODE==8
DIO_voidSetPortValue(CLCD_DATA_PORT,Copy_u8Command);
DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RS,PIN_VAL_LOW);
DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RW,PIN_VAL_LOW);

CLCD_voidSendFallingEdge();

//#elif CLCD_MODE==4

//#endif
_delay_ms(1);

	}

void CLCD_voidSendString(const u8 *Copy_u8PtrString)
{
	u8 LOC_u8Iterator=0;

	while(Copy_u8PtrString[LOC_u8Iterator]!='\0')
	{
		CLCD_voidSendData(Copy_u8PtrString[LOC_u8Iterator]);
		LOC_u8Iterator++;

	}

}


/* another code of set pos function
void CLCD_voidSetPosition(u8 Copy_u8Row,u8 Copy_u8Col)
{
	u8 LOC_u8data;

	if(2<Copy_u8Row||1>Copy_u8Row||16<Copy_u8Col||1>Copy_u8Col)
	{
		LOC_u8data=Lcd_SetCursor;
	}

	else if(Copy_u8Row==CLCD_ROW_1)
	{

		LOC_u8data=(Lcd_SetCursor)+(Copy_u8Col-1);

	}
	else if(Copy_u8Row==CLCD_ROW_2)
		{

			LOC_u8data=((Lcd_SetCursor)+64)+(Copy_u8Col-1);

		}

	CLCD_voidSendCommand(LOC_u8data);
	_delay_ms(1);



}


*/


void CLCD_voidSetPosition(u8 Copy_u8X, u8 Copy_u8Y)
{
	u8 Local_u8Position = 0;
	if (Copy_u8X ==0)
	{
		Local_u8Position=Copy_u8Y;
	}
	else if (Copy_u8X ==1)
	{
		Local_u8Position = Copy_u8Y +0x40;
	}

	CLCD_voidSendCommand(Local_u8Position+Lcd_SetCursor); // Set DDRAM Address
}










void CLCD_voidClearScreen(void)
{
	CLCD_voidSendCommand(Lcd_Clear);
	_delay_ms(10); //MORE THAN 1,53ms

}



static void CLCD_voidSendFallingEdge(void)
{
	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_EN,PIN_VAL_HIGH);
    _delay_ms(1);


	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_EN,PIN_VAL_LOW);
    _delay_ms(1);


}






void CLCD_voidSendExtraChar(u8 Copy_u8Row ,u8 Copy_u8Col)
{
	u8 lOC_u8Iterator=0;


	CLCD_voidSendCommand(Lcd_CGRAM);



	for(lOC_u8Iterator=0;lOC_u8Iterator<(sizeof(CLCD_u8ExtraChar)/sizeof(CLCD_u8ExtraChar[0]));lOC_u8Iterator++)
	{
		CLCD_voidSendData(CLCD_u8ExtraChar[lOC_u8Iterator]);



	}

	CLCD_voidSetPosition(Copy_u8Row,Copy_u8Col);

	for(lOC_u8Iterator=0;lOC_u8Iterator<8;lOC_u8Iterator++)
	{
		CLCD_voidSendData(lOC_u8Iterator);

	}





}



/*********************************************************************************************************/

void CLCD_voidSendNum(u16 Copy_u16Num)
{
	u8 Local_u8Arr[10];
	u8 Local_u8Iterator1=0,Local_u8Iterator2;
	if(Copy_u16Num==0)
	{
		CLCD_voidSendData('0');
	}
	else
	{
		while(Copy_u16Num)
		{
			Local_u8Arr[Local_u8Iterator1]=Copy_u16Num%10 + '0';
			Copy_u16Num/=10;
			Local_u8Iterator1++;
		}
	}
	for(Local_u8Iterator2=Local_u8Iterator1;Local_u8Iterator2>0;Local_u8Iterator2--)
	{
		CLCD_voidSendData(Local_u8Arr[Local_u8Iterator2-1]);
	}

}
