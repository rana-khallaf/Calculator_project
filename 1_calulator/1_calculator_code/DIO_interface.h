



#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

// PORTS DEFINATION
 #define DIO_PORTA 0
 #define DIO_PORTB 1
 #define DIO_PORTC 2
 #define DIO_PORTD 3
 
 //PINS DEFINATION
 
   #define DIO_PIN0  0
   #define DIO_PIN1  1
   #define DIO_PIN2  2
   #define DIO_PIN3  3
   #define DIO_PIN4  4
   #define DIO_PIN5  5
   #define DIO_PIN6  6
   #define DIO_PIN7  7
   
   //PORT DIRECTIONS
      #define PORT_DIR_OUTPUT 0xff
      #define PORT_DIR_INPUT  0x00
	  
   //PORT VALUE OPTIONS
     #define PORT_VAL_HIGH  0xff
     #define PORT_VAL_LOW   0x00
 
 
 
  
   //PIN DIRECTIONS
      #define PIN_DIR_OUTPUT  1
      #define PIN_DIR_INPUT  0
	  
   //PIN VALUE OPTIONS
     #define PIN_VAL_HIGH  1
     #define PIN_VAL_LOW   0

	//pull up
	#define PUD    2


//IO PORTS
void DIO_voidSetPortDirection(u8 Copy_u8PORT,u8 Copy_u8DIRECTION);
void DIO_voidSetPortValue(u8 Copy_u8PORT,u8 Copy_u8VALUE);
//u8 DIO_voidGetPortValue(u8 Copy_u8PORT);
void DIO_voidTogglePortValue(u8 Copy_u8PORT);
void DIO_voidClearPortValue(u8 Copy_u8PORT);


//IO PINS
void DIO_voidSetPinDirection(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8DIRECTION);
void DIO_voidSetPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8VALUE);
u8 DIO_voidGetPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN);
void DIO_voidTogglePinValue(u8 Copy_u8PORT,u8 Copy_u8PIN);
void DIO_voidClearPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN);



//PULL UP
void DIO_voidConnectPullUp(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8ConnectPullUp);



	 

	 
 
 
 
 
 
#endif /*DIO_INTERFACE_H_*/
