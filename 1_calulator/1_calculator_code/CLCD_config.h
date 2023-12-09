/*
 * CLCD_config.h
 *
 *  Created on: Oct 11, 2023
 *      Author: hp
 */

#ifndef MINE_HAL_CLCD_CLCD_CONFIG_H_
#define MINE_HAL_CLCD_CLCD_CONFIG_H_

//FOR CHOOSEING THE WANTED MODE OF CLCD
//OPTIONS IS 4 OR 8 MODE
#define CLCD_MODE  4




/*THE PORTS USED IN CLCD
  THE OPTIONS
 * DIO_PORTA
 * DIO_PORTB
 * DIO_PORTC
 * DIO_PORTD
 */
#define CLCD_DATA_PORT     DIO_PORTA
// ONLY 3 PINS RS, RW ,EN
#define CLCD_CONTROL_PORT     DIO_PORTC






/*THE USED PINS IN CNTRL PORT
 * THE OPTIONS
 * DIO_PIN0
 * DIO_PIN1
 * DIO_PIN2
 * DIO_PIN3
 * DIO_PIN4
 * DIO_PIN5
 * DIO_PIN6
 * DIO_PIN7
 *
 * */

#define CLCD_RS     DIO_PIN0
#define CLCD_RW     DIO_PIN1
#define CLCD_EN     DIO_PIN2


#endif /* MINE_HAL_CLCD_CLCD_CONFIG_H_ */
