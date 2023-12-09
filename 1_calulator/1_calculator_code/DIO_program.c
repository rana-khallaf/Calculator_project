			#include"STD_TYPES.h"
			#include "BIT_MATH.h"
			#include "DIO_config.h"
			#include "DIO_interface.h"
			#include "DIO_private.h"

			void DIO_voidSetPortDirection(u8 Copy_u8PORT,u8 Copy_u8DIRECTION)
			{
				if(DIO_PORTD>=Copy_u8PORT)
				{
					switch(Copy_u8PORT)
					{
					case DIO_PORTA: DDRA=Copy_u8DIRECTION;break;
					case DIO_PORTB: DDRB=Copy_u8DIRECTION;break;
					case DIO_PORTC: DDRC=Copy_u8DIRECTION;break;
					case DIO_PORTD: DDRD=Copy_u8DIRECTION;break;

					}


				}

			}




			void DIO_voidSetPortValue(u8 Copy_u8PORT,u8 Copy_u8VALUE)
			{
				if((DIO_PORTD>=Copy_u8PORT)&&(255>=Copy_u8VALUE||PORT_VAL_HIGH==Copy_u8VALUE||PORT_VAL_LOW==Copy_u8VALUE))
					{
						switch(Copy_u8PORT)
						{
						case DIO_PORTA: PORTA= Copy_u8VALUE;break;
						case DIO_PORTB: PORTB= Copy_u8VALUE;break;
						case DIO_PORTC: PORTC= Copy_u8VALUE;break;
						case DIO_PORTD: PORTD= Copy_u8VALUE;break;

						}

					}

			}



			void DIO_voidTogglePortValue(u8 Copy_u8PORT)
			{
				if(DIO_PORTD>=Copy_u8PORT)
				{
					switch(Copy_u8PORT)
					{
					case DIO_PORTA: PORTA=~PORTA;break;
					case DIO_PORTB: PORTB=~PORTB;break;
					case DIO_PORTC: PORTC=~PORTC;break;
					case DIO_PORTD: PORTD=~PORTD;break;


					}



				}

			}


			void DIO_voidClearPortValue(u8 Copy_u8PORT)
			{

				if(DIO_PORTD>=Copy_u8PORT)
						{
							switch(Copy_u8PORT)
							{
							case DIO_PORTA: PORTA=PORT_VAL_LOW;break;
							case DIO_PORTB: PORTB=PORT_VAL_LOW;break;
							case DIO_PORTC: PORTC=PORT_VAL_LOW;break;
							case DIO_PORTD: PORTD=PORT_VAL_LOW;break;


							}



						}


			}



			/*************************************************************PIN FUNCTIONS****************************************************************/


			void DIO_voidSetPinDirection(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8DIRECTION)
			{
				if((DIO_PORTD>=Copy_u8PORT)&&(DIO_PIN7>=Copy_u8PIN))
				{
					if(PIN_DIR_INPUT==Copy_u8DIRECTION)
					{
						switch(Copy_u8PORT)
						{
						case DIO_PORTA:CLR_BIT(DDRA,Copy_u8PIN);break;
						case DIO_PORTB:CLR_BIT(DDRB,Copy_u8PIN);break;
						case DIO_PORTC:CLR_BIT(DDRC,Copy_u8PIN);break;
						case DIO_PORTD:CLR_BIT(DDRD,Copy_u8PIN);break;

						}

					}

					else if(PIN_DIR_OUTPUT==Copy_u8DIRECTION)
					{
						switch(Copy_u8PORT)
									{
									case DIO_PORTA:SET_BIT(DDRA,Copy_u8PIN);break;
									case DIO_PORTB:SET_BIT(DDRB,Copy_u8PIN);break;
									case DIO_PORTC:SET_BIT(DDRC,Copy_u8PIN);break;
									case DIO_PORTD:SET_BIT(DDRD,Copy_u8PIN);break;

									}

					}

				}



			}





			void DIO_voidSetPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8VALUE)
			{

			if(DIO_PORTD>=Copy_u8PORT&&DIO_PIN7>=Copy_u8PIN&&(255<=Copy_u8VALUE||PIN_VAL_HIGH==Copy_u8VALUE||PIN_VAL_LOW==Copy_u8VALUE))
			{
				if(PIN_VAL_HIGH==Copy_u8VALUE)
				{
					switch(Copy_u8PORT)
											{
											case DIO_PORTA:SET_BIT(PORTA,Copy_u8PIN);break;
											case DIO_PORTB:SET_BIT(PORTB,Copy_u8PIN);break;
											case DIO_PORTC:SET_BIT(PORTC,Copy_u8PIN);break;
											case DIO_PORTD:SET_BIT(PORTD,Copy_u8PIN);break;

											}


				}

				else if(PIN_VAL_LOW==Copy_u8VALUE)
				{
					switch(Copy_u8PORT)
								{
								case DIO_PORTA:CLR_BIT(PORTA,Copy_u8PIN);break;
								case DIO_PORTB:CLR_BIT(PORTB,Copy_u8PIN);break;
								case DIO_PORTC:CLR_BIT(PORTC,Copy_u8PIN);break;
								case DIO_PORTD:CLR_BIT(PORTD,Copy_u8PIN);break;

								}

				}

				}


			}









			u8 DIO_voidGetPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN)
			{
			  u8 LOC_u8RESULT=0;
			  if((DIO_PORTD>=Copy_u8PORT)&&(DIO_PIN7>=Copy_u8PIN))
			  {


				  switch(Copy_u8PORT)

				  {
					case DIO_PORTA:LOC_u8RESULT=GET_BIT(PINA,Copy_u8PIN);break;
					case DIO_PORTB:LOC_u8RESULT=GET_BIT(PINB,Copy_u8PIN);break;
					case DIO_PORTC:LOC_u8RESULT=GET_BIT(PINC,Copy_u8PIN);break;
					case DIO_PORTD:LOC_u8RESULT=GET_BIT(PIND,Copy_u8PIN);break;


				  }


				}
			  return LOC_u8RESULT;


			}



			void DIO_voidTogglePinValue(u8 Copy_u8PORT,u8 Copy_u8PIN)
			{
				if((DIO_PORTD>=Copy_u8PORT)&&(DIO_PIN7>=Copy_u8PIN))
				  {
					switch(Copy_u8PORT)
							{
							case DIO_PORTA:TOG_BIT(PORTA, Copy_u8PIN) ;break;
							case DIO_PORTB:TOG_BIT(PORTB, Copy_u8PIN) ;break;
							case DIO_PORTC:TOG_BIT(PORTC, Copy_u8PIN) ;break;
							case DIO_PORTD:TOG_BIT(PORTD, Copy_u8PIN) ;break;


							}



				  }








			}



			void DIO_voidClearPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN)
			{

				 if((DIO_PORTD>=Copy_u8PORT)&&(DIO_PIN7>=Copy_u8PIN))
					  {

					 switch(Copy_u8PORT)
					{
						case DIO_PORTA:CLR_BIT(PORTA,Copy_u8PIN);break;
						case DIO_PORTB:CLR_BIT(PORTB,Copy_u8PIN);break;
						case DIO_PORTC:CLR_BIT(PORTC,Copy_u8PIN);break;
						case DIO_PORTD:CLR_BIT(PORTD,Copy_u8PIN);break;

						}


					  }


			}





			void DIO_voidConnectPullUp(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8ConnectPullUp)
			{
				if((DIO_PORTD>=Copy_u8PORT)&&(DIO_PIN7>=Copy_u8PIN))
				{
					switch(Copy_u8PORT)
					{
					case DIO_PORTA:
						if(Copy_u8ConnectPullUp==PIN_VAL_HIGH)
						{
							SET_BIT(PORTA,Copy_u8PIN);
							CLR_BIT(DDRA,Copy_u8PIN);
							CLR_BIT(SFIOR,PUD);
						}
						else
						{
							CLR_BIT(PORTA,Copy_u8PIN);


						}
						break;



		             case DIO_PORTB:
						if(Copy_u8ConnectPullUp==PIN_VAL_HIGH)
						{
							SET_BIT(PORTB,Copy_u8PIN);
							CLR_BIT(DDRB,Copy_u8PIN);
							CLR_BIT(SFIOR,PUD);
						}
						else
						{
							CLR_BIT(PORTB,Copy_u8PIN);


						}
						break;

		             case DIO_PORTC:
						if(Copy_u8ConnectPullUp==PIN_VAL_HIGH)
						{
							SET_BIT(PORTC,Copy_u8PIN);
							CLR_BIT(DDRC,Copy_u8PIN);
							CLR_BIT(SFIOR,PUD);
						}
						else
						{
							CLR_BIT(PORTC,Copy_u8PIN);


						}
						break;

		             case DIO_PORTD:
						if(Copy_u8ConnectPullUp==PIN_VAL_HIGH)
						{
							SET_BIT(PORTD,Copy_u8PIN);
							CLR_BIT(DDRD,Copy_u8PIN);
							CLR_BIT(SFIOR,PUD);
						}
						else
						{
							CLR_BIT(PORTD,Copy_u8PIN);


						}
						break;




					}



				}



			}

