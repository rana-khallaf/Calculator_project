/*
 * KPD_program.c
 *
 *  Created on: Oct 12, 2023
 *      Author: hp
 */
#include<util/delay.h>
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"KPD_config.h"
#include"KPD_interface.h"
#include"KPD_private.h"

void KPD_voidInit(void)
{
	//THE ROWS IN INPUT PULL UP (HIGH PINS)
	DIO_voidConnectPullUp(KPD_PORT,KPD_R0,PIN_VAL_HIGH);
	DIO_voidConnectPullUp(KPD_PORT,KPD_R1,PIN_VAL_HIGH);
	DIO_voidConnectPullUp(KPD_PORT,KPD_R2,PIN_VAL_HIGH);
	DIO_voidConnectPullUp(KPD_PORT,KPD_R3,PIN_VAL_HIGH);

	/* THE COLS IS OUTPUT AND HAVE HIGH VALUE*/
	DIO_voidSetPinDirection(KPD_PORT,KPD_C0,PIN_DIR_OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_C1,PIN_DIR_OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_C2,PIN_DIR_OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_C3,PIN_DIR_OUTPUT);


	DIO_voidSetPinValue(KPD_PORT,KPD_C0,PIN_VAL_HIGH);
	DIO_voidSetPinValue(KPD_PORT,KPD_C1,PIN_VAL_HIGH);
	DIO_voidSetPinValue(KPD_PORT,KPD_C2,PIN_VAL_HIGH);
	DIO_voidSetPinValue(KPD_PORT,KPD_C3,PIN_VAL_HIGH);




}


u8 KPD_u8GetPressed(void)
{
	u8 Local_u8Col;
	u8 Local_u8Row;
	u8 Local_u8Reading;
	u8 Local_u8Key=0;

	u8 KPD_u8Values [MAX_ROW][MAX_COL] = KPD_VALUES;

	for (Local_u8Col =0 ; Local_u8Col <4 ; Local_u8Col++)
	{
		DIO_voidSetPinValue(KPD_PORT,Local_u8Col,PIN_VAL_LOW); // Put GND in each Column

		for (Local_u8Row = 0 ; Local_u8Row <4 ; Local_u8Row++)
		{
			Local_u8Reading = DIO_voidGetPinValue(KPD_PORT,Local_u8Row + 4);
			// to get the values of each switch

			if (Local_u8Reading == PIN_VAL_LOW)
			{
				Local_u8Key = KPD_u8Values [Local_u8Row][Local_u8Col];
				_delay_ms(10);
			}

			while (DIO_voidGetPinValue(KPD_PORT,Local_u8Row +4) == PIN_VAL_LOW)
			{

			}
		}

		DIO_voidSetPinValue(KPD_PORT,Local_u8Col,PIN_VAL_HIGH);
	}
	return Local_u8Key;

}





/*
 * the first one i wrote


u8 KPD_u8GetPressed(void)
{
	u8 LOC_u8Returndata=NOT_PRESSED;
	u8 LOC_u8GetPressed;

	u8 LOC_u8Row;
	u8 LOC_u8Col;


	for(LOC_u8Col=0+KPD_COL_INIT;LOC_u8Col<=KPD_COL_END;LOC_u8Col++)
	{
		DIO_voidSetPinValue(KPD_PORT,LOC_u8Col,PIN_VAL_LOW);




		for(LOC_u8Row=0+KPD_ROW_INIT;LOC_u8Row<=KPD_ROW_END;LOC_u8Row++)
		{
			LOC_u8GetPressed=DIO_voidGetPinValue(KPD_PORT,LOC_u8Row);



			if(PIN_VAL_LOW==LOC_u8GetPressed)
			{
				_delay_ms(50);
				LOC_u8GetPressed=DIO_voidGetPinValue(KPD_PORT,LOC_u8Row);


				if(PIN_VAL_LOW==LOC_u8GetPressed)
				{
					LOC_u8Returndata=KPD_u8Buttons[LOC_u8Row-KPD_ROW_INIT][LOC_u8Col-KPD_COL_INIT];
				}


				LOC_u8GetPressed=DIO_voidGetPinValue(KPD_PORT,LOC_u8Row);
				while(PIN_VAL_LOW==LOC_u8GetPressed)
				{
					LOC_u8GetPressed=DIO_voidGetPinValue(KPD_PORT,LOC_u8Row);

				}

				break;


			    }


			}

		DIO_voidSetPinValue(KPD_PORT,LOC_u8Col,PIN_VAL_HIGH);


	}


return LOC_u8Returndata;

}
*/
