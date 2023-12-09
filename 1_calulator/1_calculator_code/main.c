	/*
	 * main.c
	 *
	 *  Created on: Dec 3, 2023
	 *      Author: hp
	 */
	#include "STD_TYPES.h"
	#include "BIT_MATH.h"
     #include "util/delay.h"
	#include "DIO_interface.h"
	#include "CLCD_interface.h"
	#include "KPD_interface.h"


	u8 kpd_value=0;
	u8 numberofdigit=0;

	u8 pasword[16];
	u8 check_pasword[16];

	u8 counter=0;
	u8 operation;

	u8 first_num[4];
	u8 sec_num[4];




	u8 checker;



	u8 check(u8 password[],u8 check_password[],u8 numberofdigit);
	u16 calc_add( u8 first_num[],u8 sec_num[],u8 i,u8 j);
	u16 calc_sub( u8 first_num[],u8 sec_num[],u8 i,u8 j);
	u16 calc_div( u8 first_num[],u8 sec_num[],u8 i,u8 j);
	u16 calc_multi( u8 first_num[],u8 sec_num[],u8 i,u8 j);




	void main(void)
	{
		//KPD_voidInit();
		DIO_voidSetPortDirection(DIO_PORTB,0b00001111);
		DIO_voidSetPortValue(DIO_PORTB,PORT_VAL_HIGH);

		CLCD_voidInit();


	CLCD_voidSendString("set password");


	//set password
	while(1)
	{


		do{
			kpd_value=KPD_u8GetPressed();

		}while(kpd_value=='\0');
		numberofdigit++;
		if(kpd_value=='&')break;

		CLCD_voidSetPosition(1,numberofdigit-1);
		CLCD_voidSendNum(kpd_value);

		_delay_ms(200);
		CLCD_voidSetPosition(1,numberofdigit-1);
		CLCD_voidSendData('*');
		pasword[numberofdigit]=kpd_value;


	}

	//check password
	while(1)
	{
		CLCD_voidClearScreen();
		_delay_ms(100);
		CLCD_voidSendString("check password");


		kpd_value='\0';
		counter=0;
	// get the password that will be compared with the real password

		while(kpd_value!='&')
		{

			do{
				kpd_value=KPD_u8GetPressed();

			}while(kpd_value=='\0');

			counter++;

			if(kpd_value=='&')break;

			CLCD_voidSetPosition(1,counter-1);
			CLCD_voidSendNum(kpd_value);
			_delay_ms(200);
			CLCD_voidSetPosition(1,counter-1);
			CLCD_voidSendData('*');

		   check_pasword[counter]=kpd_value;


		}

		//check if the password is correct or not
		checker=check(check_pasword,pasword,counter);

		if(checker==(numberofdigit-1))
		{

		//loading to start calculator
			CLCD_voidClearScreen();
			CLCD_voidSendString("loading");
			 for(u8 i=0;i<5;i++)
			 {
				 CLCD_voidSetPosition(1,i);
				 CLCD_voidSendData('.');
				 _delay_ms(100);

			 }
			 CLCD_voidClearScreen();
			 CLCD_voidSendString("calculator");
			 CLCD_voidSetPosition(1,0);
			 CLCD_voidSendString("is ready");
			 _delay_ms(500);
			 CLCD_voidClearScreen();

			 //loop for repeating the operation

			 while(1)
			 {

				 counter=0;
				 operation=0;

	//geting the 1st number
				 while(1)
				 {
				 do {
					 kpd_value=KPD_u8GetPressed();
					 _delay_ms(20);

				 }while(kpd_value=='\0');

				 if(kpd_value=='+'||kpd_value=='-'||kpd_value=='/'||kpd_value=='*')
						 {
					 operation=kpd_value;
					 CLCD_voidSetPosition(0,counter);
					 CLCD_voidSendData(kpd_value);
					 break;

							 }


		 first_num[counter]=kpd_value;
		 counter++;
		 CLCD_voidSetPosition(0,counter-1);
		 CLCD_voidSendNum(kpd_value);

			 }



		u8 counter2=counter+1;
		u8 counter3=0;
		while(1)
		{
				do {
					 kpd_value=KPD_u8GetPressed();
					 _delay_ms(20);

				 }while(kpd_value=='\0');

				if(kpd_value=='=')
				{
					 CLCD_voidSetPosition(0,counter2);
					 CLCD_voidSendData(kpd_value);
					 break;
				}
				sec_num[counter3]=kpd_value;
				counter2++;
				counter3++;
				CLCD_voidSetPosition(0,counter2-1);
				CLCD_voidSendNum(kpd_value);


		}
		switch(operation)
		{

		case'+':
			CLCD_voidSetPosition(0,counter2+1);
		   CLCD_voidSendNum(calc_add(first_num,sec_num,counter,counter3));
			break;

		case'-':
				CLCD_voidSetPosition(0,counter2+1);
			   CLCD_voidSendNum(calc_sub(first_num,sec_num,counter,counter3));
				break;
		case'*':
				CLCD_voidSetPosition(0,counter2+1);
			   CLCD_voidSendNum(calc_multi(first_num,sec_num,counter,counter3));
				break;
		case'/':
				CLCD_voidSetPosition(0,counter2+1);
			   CLCD_voidSendNum(calc_div(first_num,sec_num,counter,counter3));
				break;

		}
		_delay_ms(1000);
		CLCD_voidClearScreen();



		}


		}

		else
		{
			CLCD_voidClearScreen();
			CLCD_voidSendString("wrong password");
			_delay_ms(2000);

		}

	}

	}





	u8 check(u8 password[],u8 check_password[],u8 numberofdigit)
	{
		u8 checker=0;
		for(u8 i=0;i<numberofdigit-1;i++)
		{
			if( password[i]==check_password[i])
			{
				checker++;
			}

		}

	return checker;
	}


	u16 calc_add( u8 first_num[],u8 sec_num[],u8 i,u8 j)
	{
		u16 num1=first_num[0];
		u16 num2=sec_num[0];

		for(u8 counter=1;counter<i;counter++)
		{
			num1=num1*10+first_num[counter];


		}

		for(u8 counter=1;counter<j;counter++)
			{
				num2=num2*10+sec_num[counter];


			}

	return(num1+num2);
	}



	u16 calc_sub( u8 first_num[],u8 sec_num[],u8 i,u8 j)
	{
		u16 num1=first_num[0];
		u16 num2=sec_num[0];

		for(u8 counter=1;counter<i;counter++)
		{
			num1=num1*10+first_num[counter];


		}

		for(u8 counter=1;counter<j;counter++)
			{
				num2=num2*10+sec_num[counter];


			}

	return(num1-num2);
	}



	u16 calc_multi( u8 first_num[],u8 sec_num[],u8 i,u8 j)
	{
		u16 num1=first_num[0];
		u16 num2=sec_num[0];

		for(u8 counter=1;counter<i;counter++)
		{
			num1=num1*10+first_num[counter];


		}

		for(u8 counter=1;counter<j;counter++)
			{
				num2=num2*10+sec_num[counter];


			}

	return (num1*num2);
	}




	u16 calc_div( u8 first_num[],u8 sec_num[],u8 i,u8 j)
	{
		u16 num1=first_num[0];
		u16 num2=sec_num[0];

		for(u8 counter=1;counter<i;counter++)
		{
			num1=num1*10+first_num[counter];


		}

		for(u8 counter=1;counter<j;counter++)
			{
				num2=num2*10+sec_num[counter];


			}

	return (num1/num2);
	}




