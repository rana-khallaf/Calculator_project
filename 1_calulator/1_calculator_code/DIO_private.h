

#ifndef  DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


//THE 3 REG OF PORTA

  #define DDRA   *((volatile u8*)0x3A) 
  #define PORTA  *((volatile u8*)0x3B)
  #define PINA   *((volatile u8*)0x39)
  
  
  //THE 3 REG OF PORTB
  
   #define DDRB   *((volatile u8*)0x37)
   #define PORTB  *((volatile u8*)0x38)
   #define PINB   *((volatile u8*)0x36)
                         

 //	THE 3 REG OF PORTC	
 

   #define DDRC  *((volatile u8*)0x34)
   #define PORTC  *((volatile u8*)0x35)
   #define PINC  *((volatile u8*)0x33)
                         

						 
 //	THE 3 REG OF PORTD
 

   #define DDRD  *((volatile u8*)0x31)
   #define PORTD *((volatile u8*)0x32)
   #define PIND  *((volatile u8*)0x30)
                         

//internal pull up
   #define SFIOR *((volatile u8*)0X50)







#endif/*DIO_PRIVATE_H_*/
