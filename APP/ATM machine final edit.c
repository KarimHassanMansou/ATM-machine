


#include <util/delay.h>
#include <string.h>
#include <math.h>
#include "Gpio.h"
#include "LED.h"
#include "LCD.h"
#include "sevensegment.h"
#include "KEYPAD.h"
#include "bank Database.h"


/*
int number_one = 0;
int number_two = 0;
int res;
*/


int flag = -1;
char cash_num[30];

uchar8 user_password[6];

uchar8 money_decimals[2];
uchar8 money_hundreds[3];
uchar8 money_thusends[4];
uchar8 money_ten_thusends[5];

char *endPtr;

int money_decimals_num;
int money_hundreds_num;

int money_thusends_num;
int money_thusends_number[4];

unsigned int money_ten_thusends_num;
unsigned int money_ten_thusends_number[5];

int temp_password;


int array_to_num(int arr[],int n)
{
	char str[6][3];
	int i;
    char number[13] = {'\n'};

 for(i=0;i<n;i++)
 {
	sprintf(str[i],"%d",arr[i]); 
 }
  
 for(i=0;i<n;i++)
 {
	strcat(number,str[i]); 
 }
 
 i = atoi(number);
 
 return i;
 
} 


int intTochar(int digit)
{
	char charValue = digit + '0';
	
	return charValue;
}



int main(void)
{
    
	int i;
	
	struct customer customers[100]; //from customer 1 to customer 100;
	
	customers[0].cash = 5000000;
	customers[0].id = 125649;
	
	customers[1].cash = 5000;
	customers[1].id = 133466;
	
	customers[2].cash = 5000;
	customers[2].id = 121346;
	
	customers[3].cash = 5000;
	customers[3].id = 111456;
	
	customers[4].cash = 5000;
	customers[4].id = 125561;
	
	customers[5].cash = 5000;
	customers[5].id = 132466;
	
	customers[6].cash = 5000;
	customers[6].id = 133458;
	
	customers[7].cash = 5000;
	customers[7].id = 113476;
	
	customers[8].cash = 5000;
	customers[8].id = 193496;
	
	customers[9].cash = 5000;
	customers[9].id = 123400;
	
	customers[10].cash = 70000;
	customers[10].id = 123410;
	
	customers[11].cash = 5000;
	customers[11].id = 103400;
	
	customers[12].cash = 5000;
	customers[12].id = 123450;
	
	customers[13].cash = 5000;
	customers[13].id = 120400;
	
	customers[14].cash = 5000;
	customers[14].id = 113450;
	
	customers[15].cash = 5000;
	customers[15].id = 123420;
	
	customers[16].cash = 5000;
	customers[16].id = 163402;
	
	customers[17].cash = 5000;
	customers[17].id = 723500;
	
	customers[18].cash = 5000;
	customers[18].id = 523500;
	
	customers[19].cash = 7500;
	customers[19].id = 483410;
	
	customers[20].cash = 5000000;
	customers[20].id = 126549;
	
	customers[21].cash = 5000;
	customers[21].id = 134366;
	
	customers[22].cash = 5000;
	customers[22].id = 120046;
	
	customers[23].cash = 5000;
	customers[23].id = 114156;
	
	customers[24].cash = 5000;
	customers[24].id = 120561;
	
	customers[25].cash = 5000;
	customers[25].id = 134266;
	
	customers[26].cash = 5000;
	customers[26].id = 134358;
	
	customers[27].cash = 5000;
	customers[27].id = 102276;
	
	customers[28].cash = 5000;
	customers[28].id = 194306;
	
	customers[29].cash = 5000;
	customers[29].id = 114300;
	
	customers[30].cash = 70000;
	customers[30].id = 124310;
	
	customers[31].cash = 5000;
	customers[31].id = 104300;
	
	customers[32].cash = 5000;
	customers[32].id = 125550;
	
	customers[33].cash = 5000;
	customers[33].id = 190410;
	
	customers[34].cash = 5000;
	customers[34].id = 184350;
	
	customers[35].cash = 5000;
	customers[35].id = 174320;
	
	customers[36].cash = 5000;
	customers[36].id = 104302;
	
	customers[37].cash = 5000;
	customers[37].id = 725300;
	
	customers[38].cash = 5000;
	customers[38].id = 525300;
	
	customers[39].cash = 7500;
	customers[39].id = 489310;
	
	customers[40].cash = 5000000;
	customers[40].id = 135694;
	
	customers[41].cash = 5000;
	customers[41].id = 313466;
	
	customers[42].cash = 5000;
	customers[42].id = 121364;
	
	customers[43].cash = 5000;
	customers[43].id = 101465;
	
	customers[44].cash = 5000;
	customers[44].id = 125516;
	
	customers[45].cash = 5000;
	customers[45].id = 136469;
	
	customers[46].cash = 5000;
	customers[46].id = 133485;
	
	customers[47].cash = 5000;
	customers[47].id = 113467;
	
	customers[48].cash = 5000;
	customers[48].id = 193469;
	
	customers[49].cash = 5000;
	customers[49].id = 193444;
	
	customers[50].cash = 70000;
	customers[50].id = 123401;
	
	customers[51].cash = 5000;
	customers[51].id = 103402;
	
	customers[52].cash = 5000;
	customers[52].id = 123405;
	
	customers[53].cash = 5000;
	customers[53].id = 120434;
	
	customers[54].cash = 5000;
	customers[54].id = 173405;
	
	customers[55].cash = 5000;
	customers[55].id = 123402;
	
	customers[56].cash = 5000;
	customers[56].id = 162402;
	
	customers[57].cash = 5000;
	customers[57].id = 723555;
	
	customers[58].cash = 5000;
	customers[58].id = 523556;
	
	customers[59].cash = 7500;
	customers[59].id = 483401;
	
	customers[60].cash = 5000000;
	customers[60].id = 195644;
	
	customers[61].cash = 5000;
	customers[61].id = 313466;
	
	customers[62].cash = 5000;
	customers[62].id = 211346;
	
	customers[63].cash = 5000;
	customers[63].id = 100456;
	
	customers[64].cash = 5000;
	customers[64].id = 215561;
	
	customers[65].cash = 5000;
	customers[65].id = 312466;
	
	customers[66].cash = 5000;
	customers[66].id = 313458;
	
	customers[67].cash = 5000;
	customers[67].id = 193476;
	
	customers[68].cash = 5000;
	customers[68].id = 913496;
	
	customers[69].cash = 5000;
	customers[69].id = 213400;
	
	customers[70].cash = 70000;
	customers[70].id = 213410;
	
	customers[71].cash = 5000;
	customers[71].id = 114400;
	
	customers[72].cash = 5000;
	customers[72].id = 213450;
	
	customers[73].cash = 5000;
	customers[73].id = 210400;
	
	customers[74].cash = 5000;
	customers[74].id = 133450;
	
	customers[75].cash = 5000;
	customers[75].id = 213420;
	
	customers[76].cash = 5000;
	customers[76].id = 613402;
	
	customers[77].cash = 5000;
	customers[77].id = 273500;
	
	customers[78].cash = 5000;
	customers[78].id = 253500;
	
	customers[79].cash = 7500;
	customers[79].id = 843410;
	
	customers[80].cash = 5000000;
	customers[80].id = 225649;
	
	customers[81].cash = 5000;
	customers[81].id = 333466;
	
	customers[82].cash = 5000;
	customers[82].id = 221346;
	
	customers[83].cash = 5000;
	customers[83].id = 101450;
	
	customers[84].cash = 5000;
	customers[84].id = 125560;
	
	customers[85].cash = 5000;
	customers[85].id = 132460;
	
	customers[86].cash = 5000;
	customers[86].id = 133450;
	
	customers[87].cash = 5000;
	customers[87].id = 113470;
	
	customers[88].cash = 5000;
	customers[88].id = 193490;
	
	customers[89].cash = 5000;
	customers[89].id = 123496;
	
	customers[90].cash = 70000;
	customers[90].id = 123419;
	
	customers[91].cash = 5000;
	customers[91].id = 103455;
	
	customers[92].cash = 5000;
	customers[92].id = 123457;
	
	customers[93].cash = 5000;
	customers[93].id = 120477;
	
	customers[94].cash = 5000;
	customers[94].id = 113488;
	
	customers[95].cash = 5000;
	customers[95].id = 123422;
	
	customers[96].cash = 5000;
	customers[96].id = 163466;
	
	customers[97].cash = 5000;
	customers[97].id = 723599;
	
	customers[98].cash = 5000;
	customers[98].id = 523544;
	
	customers[99].cash = 7500;
	customers[99].id = 483411;
	
	
	
	uchar8 key;
	uchar8 key2;//pull  deposit  cash
	uchar8 key3;//10 , 100 , 1000
	
	uchar8 key4;//cash back and any button
	
	//uchar8 original_password[6] = {'1' , '9' , '0' , '7' , '*' , '#'}; : security system
	
	
	LCD_INIT();
	KEYPAD_INIT();
	
	initialize_pin(GPIO_B , 6 , INPUT);
	
	initialize_pin(GPIO_D , 0 , OUTPUT);//LED
	initialize_pin(GPIO_D , 3 , OUTPUT);//LED
	
	initialize_pin(GPIO_D , 6 , OUTPUT);//DC motor
	initialize_pin(GPIO_D , 7 , OUTPUT);//DC motor
     
	while(1)
	{
		
	 _delay_ms(5000);
     LCD_WRITE_STRING(" Enter your card");
	 _delay_ms(50000);
	 
	 LCD_CLEAR();
	 _delay_ms(300);
	 
	jump4://from wrong password state
	 
	 _delay_ms(5000);
	 LCD_WRITE_STRING("Enter six words");
	 LCD_WRITE_COMMAND(0xC0);
	 LCD_WRITE_STRING("Password:");
	 	 
	 for (i=0 ; i<6 ; i++)
	 {
		 user_password[i] = GET_PRESSED();
		 LCD_WRITE_DATA(user_password[i]);
	 }
	 
	 temp_password = atoi(user_password);//convert from string to integer
	 
		 _delay_ms(6000);
		 LCD_CLEAR();
		
		for (i=0 ; i<100 ; i++)
		{
			if (temp_password == customers[i].id)
			{
				flag = i;
			}
		
		}	
		
			
		 if (flag != -1)//(string_compare(original_password , user_password)) == 0 : security system
		 {
			 
			jump:
			
			 LCD_CLEAR();
			 _delay_ms(300);
			 
			 LED_ON(GPIO_D , 0);
			 
			 LCD_CLEAR();
			 _delay_ms(300);
		     
			 LCD_WRITE_COMMAND(0x0C);
			  
			 LCD_WRITE_STRING("1.Drawing 3.Cash");
			 LCD_WRITE_COMMAND(0xC0);
			 LCD_WRITE_STRING("2.Deposit 4.Exit");
			 
			 key2 = GET_PRESSED();
			 
			 if (key2 == keypad_array[0][0])//withdraw
			 {
				 
				 LCD_CLEAR();
				 _delay_ms(300);
				 
				jump3:
				 
				 LCD_WRITE_STRING("1.(10) 3.(1000)");
				 LCD_WRITE_COMMAND(0xC0);
				 LCD_WRITE_STRING("2.(100)4.(10000)");
				 
				
				 key3 = GET_PRESSED();
				 
				 if (key3 == '1')
				 {
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					  
					 LCD_WRITE_COMMAND(0x0F);
					 
					enter:
					 
					 LCD_WRITE_STRING("Enter a number:");
					 LCD_WRITE_COMMAND(0xC0);
					 
					 for (i=0 ; i<2 ; i++)
					 {
						 money_decimals[i] = GET_PRESSED();
						 LCD_WRITE_DATA(money_decimals[i]);
						 
					 } 
					 
					 for (i=0 ; i<2 ; i++)
					 {
						 
						 if (strcmp(money_decimals[i] , '*') == 0 || strcmp(money_decimals[i] , '#') == 0)
						 {
							 _delay_ms(4000);
							 LCD_CLEAR();
							 _delay_ms(300);
							 
							 LCD_WRITE_STRING("Wrong number");
							  LCD_WRITE_COMMAND(0xC0);
							 LCD_WRITE_STRING("Please try Again");
							 
							 LCD_WRITE_COMMAND(0x0C);
							 _delay_ms(10000);
							 
							 LCD_CLEAR();
							 _delay_ms(300);
							 
							 LCD_WRITE_COMMAND(0x0F);
							 
							 goto enter;
						 }
						 
					 }
					 
					 key3 = GET_PRESSED();
					 
					 if (key3 == '*')
					 {
						 LCD_CLEAR();
						 _delay_ms(300);
						 
						 goto jump3;
					 }
					 else if (key3 == 'c')
					 {
						 goto next1;
					 }
					 
					 next1:
					 
					 money_decimals_num = atoi(money_decimals);//convert from string to number
					 
					 if (money_decimals_num > customers[flag].cash)
					 {
						 LCD_CLEAR();
						 _delay_ms(300);
						 
						 LCD_WRITE_STRING("Your cash is not");
						 LCD_WRITE_COMMAND(0xC0);
						 LCD_WRITE_STRING("Enough");
						 
						 LCD_WRITE_COMMAND(0x0C);
						 
						 _delay_ms(15000);
						 LCD_CLEAR();
						 _delay_ms(300);
						 
						 LCD_WRITE_COMMAND(0x0F);
						 
						 goto enter;
						 
						 
					 }
					 else
					 {
						  customers[flag].cash = customers[flag].cash - money_decimals_num;
					 }
					 
					  
					 LCD_CLEAR();
					 _delay_ms(300);
					 
					 LCD_WRITE_COMMAND(0X0C);
					 
					 LCD_WRITE_STRING("Wait for money");
					 _delay_ms(30000);
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					 
					 LCD_WRITE_STRING("Draw the money");
					 LCD_WRITE_COMMAND(0xC0);
					 LCD_WRITE_STRING("in 10 seconds");
					 
					 io_write_pin(GPIO_D , 6 , HIGH);
					 
					 for (i=0 ; i<10 ; i++)
					 {
						 _delay_ms(3500);
						 LED_OFF(GPIO_D , 0);
						 _delay_ms(3500);
						 LED_ON(GPIO_D , 0);
					 }
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					 io_write_pin(GPIO_D , 6 , LOW);
					 
					 LCD_WRITE_COMMAND(0x0C);
					 LCD_WRITE_STRING("Please wait...");
					 
					 LED_OFF(GPIO_D , 0);
					 LED_ON(GPIO_D , 3);
					 
					 _delay_ms(40000);
					 LED_OFF(GPIO_D , 3);
					 LCD_CLEAR();
					 _delay_ms(300);
					 
					 LCD_WRITE_STRING("1.back    2.exit");
					 key3 = GET_PRESSED();
					  
					  if (key3 == '1')
					  {
						  LCD_CLEAR();
						  _delay_ms(300);
						  
						  goto jump;
					  }
					  else if (key3 == '2')
					  {
						  goto next11;
					  }
					  
					  next11:
					  
					 LCD_CLEAR();
					 _delay_ms(300);
					 
					 LCD_WRITE_STRING("Pick up the card");
					 _delay_ms(40000);
					 LCD_CLEAR();
					 _delay_ms(300);
					  
							 
				 }
				 else if (key3 == '2')
				 {
					  
					 LCD_CLEAR();
					 _delay_ms(300);
					  
					 LCD_WRITE_COMMAND(0X0F);
					 
					enter2:
					 
					 LCD_WRITE_STRING("Enter a number:");
					 LCD_WRITE_COMMAND(0xC0);
					 
			
					 for (i=0 ; i<3 ; i++)
					 {
						 money_hundreds[i] = GET_PRESSED();
						 LCD_WRITE_DATA(money_hundreds[i]);
					 }
					 
					 for (i=0 ; i<3 ; i++)
					 {
						 
						 if (strcmp(money_hundreds[i] , '*') == 0 || strcmp(money_hundreds[i] , '#') == 0)
						 {
							 _delay_ms(4000);
							 LCD_CLEAR();
							 _delay_ms(300);
							 
							 LCD_WRITE_STRING("Wrong number");
							 LCD_WRITE_COMMAND(0xC0);
							 LCD_WRITE_STRING("Please try Again");
							 
							 LCD_WRITE_COMMAND(0x0C);
							 _delay_ms(10000);
							 
							 LCD_CLEAR();
							 _delay_ms(300);
							 
							 LCD_WRITE_COMMAND(0x0F);
							 
							 goto enter2;
						 }
						 
					 }
					 
					 
					  key3 = GET_PRESSED();
					  
					  if (key3 == '*')
					  {
						  LCD_CLEAR();
						  _delay_ms(300);
						  
						  goto jump3;
					  }
					  else if (key3 == '#')
					  {
						  goto next2;
					  }
					  
					  next2:
					 
					 
					 money_hundreds_num = atoi(money_hundreds);
					 
					 if (money_hundreds_num > customers[flag].cash)
					 {
						 LCD_CLEAR();
						 _delay_ms(300);
						 
						 LCD_WRITE_STRING("Your cash is not");
						 LCD_WRITE_COMMAND(0xC0);
						 LCD_WRITE_STRING("Enough");
						 
						 LCD_WRITE_COMMAND(0x0C);
						 
						 _delay_ms(15000);
						 LCD_CLEAR();
						 _delay_ms(300);
						 
						 LCD_WRITE_COMMAND(0x0F);
						 
						 goto enter2;
						 
						 
					 }
					 else
					 {
						 customers[flag].cash = customers[flag].cash - money_hundreds_num;
					 }
					 
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					 
					 LCD_WRITE_COMMAND(0X0C);
					 
					 LCD_WRITE_STRING("Wait for money");
					 _delay_ms(30000);
					  
					 LCD_CLEAR();
					 _delay_ms(300);
					 
					 LCD_WRITE_STRING("Draw the money");
					 LCD_WRITE_COMMAND(0xC0);
					 LCD_WRITE_STRING("in 10 seconds");
					 
					 io_write_pin(GPIO_D , 6 , HIGH);
					 
					 for (i=0 ; i<10 ; i++)
					 {
						  _delay_ms(3500);
						  LED_OFF(GPIO_D , 0);
						  _delay_ms(3500);
						  LED_ON(GPIO_D , 0);
					 }
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					 io_write_pin(GPIO_D , 6 , LOW);
					 
					 LCD_WRITE_COMMAND(0x0C);
					 LCD_WRITE_STRING("Please wait...");
					 
					 LED_OFF(GPIO_D , 0);
					 LED_ON(GPIO_D , 3);
					 
					 _delay_ms(40000);
					 LED_OFF(GPIO_D , 3);
					 LCD_CLEAR();
					 _delay_ms(300);
					 
					  LCD_WRITE_STRING("1.back    2.exit");
					  key3 = GET_PRESSED();
					  
					  if (key3 == '1')
					  {
						  LCD_CLEAR();
						  _delay_ms(300);
						  
						  goto jump;
					  }
					  else if (key3 == '2')
					  {
						  goto next12;
					  }
					  
					  next12:
					  
					  LCD_CLEAR();
					  _delay_ms(300);
					 
					 LCD_WRITE_STRING("Pick up the card");
					 _delay_ms(40000);
					 LCD_CLEAR();
					 _delay_ms(300);
					  
					  
					 
				 }
				 else if (key3 == '3')
				 {
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					  
					 LCD_WRITE_COMMAND(0X0F);
					  
					enter3:
					  
					 LCD_WRITE_STRING("Enter a number:");
					 LCD_WRITE_COMMAND(0xC0);
					 
					 
					 for (i=0 ; i<4 ; i++)
					 {
						 money_thusends[i] = GET_PRESSED();
						 LCD_WRITE_DATA(money_thusends[i]);
					 }
					 
					 for (i=0 ; i<4 ; i++)
					 {
						 
						 if (strcmp(money_thusends[i] , '*') == 0 || strcmp(money_thusends[i] , '#') == 0)
						 {
							 _delay_ms(4000);
							 LCD_CLEAR();
							 _delay_ms(300);
							 
							 LCD_WRITE_STRING("Wrong number");
							 LCD_WRITE_COMMAND(0xC0);
							 LCD_WRITE_STRING("Please try Again");
							 
							 LCD_WRITE_COMMAND(0x0C);
							 _delay_ms(10000);
							 
							 LCD_CLEAR();
							 _delay_ms(300);
							 
							 LCD_WRITE_COMMAND(0x0F);
							 
							 goto enter3;
						 }
						 
					 }
					 
					 
					  key3 = GET_PRESSED();
					  
					  if (key3 == '*')
					  {
						  LCD_CLEAR();
						  _delay_ms(300);
						  
						  goto jump3;
					  }
					  else if (key3 == '#')
					  {
						  goto next3;
					  }
					  
					 next3:
					 
					 for (i=0 ; i<4 ; i++)
					 {
						 money_thusends_number[i] = charToint(money_thusends[i]);
					 }
					 
					 money_thusends_num = array_to_num(money_thusends_number , 4);
					 
					 if (money_thusends_num > customers[flag].cash)
					 {
						 LCD_CLEAR();
						 _delay_ms(300);
						 
						 LCD_WRITE_STRING("Your cash is not");
						 LCD_WRITE_COMMAND(0xC0);
						 LCD_WRITE_STRING("Enough");
						 
						 LCD_WRITE_COMMAND(0x0C);
						 
						 _delay_ms(15000);
						 LCD_CLEAR();
						 _delay_ms(300);
						 
						 LCD_WRITE_COMMAND(0x0F);
						 
						 goto enter3;
						 
						 
					 }
					 else
					 {
						 customers[flag].cash = customers[flag].cash - money_thusends_num;
					 }
					 
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					 
					 LCD_WRITE_COMMAND(0X0C);
					 
					 LCD_WRITE_STRING("Wait for money");
					 _delay_ms(30000);
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					 
					 LCD_WRITE_STRING("Draw the money");
					 LCD_WRITE_COMMAND(0xC0);
					 LCD_WRITE_STRING("in 10 seconds");
					 
					 io_write_pin(GPIO_D , 6 , HIGH);
					 
					 for (i=0 ; i<10 ; i++)
					 {
						 _delay_ms(3500);
						 LED_OFF(GPIO_D , 0);
						 _delay_ms(3500);
						 LED_ON(GPIO_D , 0);
					 }
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					 io_write_pin(GPIO_D , 6 , LOW);
					 
					 LCD_WRITE_COMMAND(0x0C);
					 LCD_WRITE_STRING("Please wait...");
					 
					 LED_OFF(GPIO_D , 0);
					 LED_ON(GPIO_D , 3);
					 
					 _delay_ms(40000);
					 LED_OFF(GPIO_D , 3);
					 LCD_CLEAR();
					 _delay_ms(300);
					  
					 LCD_WRITE_STRING("1.back    2.exit");
					 key3 = GET_PRESSED();
					 
					 if (key3 == '1')
					 {
						 LCD_CLEAR();
						 _delay_ms(300);
						 
						 goto jump;
					 }
					 else if (key3 == '2')
					 {
						 goto next13;
					 }
					 
					 next13:
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					  
					 LCD_WRITE_STRING("Pick up the card");
					 _delay_ms(40000);
					 LCD_CLEAR();
					 _delay_ms(300);
					   
					   
					 
				 }
				 else if (key3 == '4')
				 {
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					 
					 LCD_WRITE_COMMAND(0X0F);
					 
					enter4:
					 
					 LCD_WRITE_STRING("Enter a number:");
					 LCD_WRITE_COMMAND(0xC0);
					 
					 for (i=0 ; i<5 ; i++)
					 {
						 money_ten_thusends[i] = GET_PRESSED();
						 LCD_WRITE_DATA(money_ten_thusends[i]);
					 }
					 
					 for (i=0 ; i<5 ; i++)
					 {
						 
						 if (strcmp(money_ten_thusends[i] , '*') == 0 || strcmp(money_ten_thusends[i] , '#') == 0)
						 {
							 _delay_ms(4000);
							 LCD_CLEAR();
							 _delay_ms(300);
							 
							 LCD_WRITE_STRING("Wrong number");
							 LCD_WRITE_COMMAND(0xC0);
							 LCD_WRITE_STRING("Please try Again");
							 
							 LCD_WRITE_COMMAND(0x0C);
							 _delay_ms(10000);
							 
							 LCD_CLEAR();
							 _delay_ms(300);
							 
							 LCD_WRITE_COMMAND(0x0F);
							 
							 goto enter4;
						 }
						 
					 }
					 
					 
					  key3 = GET_PRESSED();
					  
					  if (key3 == '*')
					  {
						  LCD_CLEAR();
						  _delay_ms(300);
						  
						  goto jump3;
					  }
					  else if (key3 == '#')
					  {
						  goto next4;
					  }
					  
					next4:
					
					for (i=0 ; i<5 ; i++)
					{
						money_ten_thusends_number[i] = charToint(money_ten_thusends[i]);
					}    
					
					money_ten_thusends_num = array_to_num(money_ten_thusends_number , 5);                     
				    
					 
					if (money_ten_thusends_num > customers[flag].cash)
					{
						LCD_CLEAR();
						_delay_ms(300);
						
						LCD_WRITE_STRING("Your cash is not");
						LCD_WRITE_COMMAND(0xC0);
						LCD_WRITE_STRING("Enough");
						
						LCD_WRITE_COMMAND(0x0C);
						
						_delay_ms(15000);
						LCD_CLEAR();
						_delay_ms(300);
						
						LCD_WRITE_COMMAND(0x0F);
						
						goto enter4;
						
						
					}
					else
					{
					    customers[flag].cash = customers[flag].cash - money_ten_thusends_num;
					}
					
					
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					 
					 LCD_WRITE_COMMAND(0X0C);
					 
					 LCD_WRITE_STRING("Wait for money");
					 _delay_ms(30000);
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					 
					 LCD_WRITE_STRING("Draw the money");
					 LCD_WRITE_COMMAND(0xC0);
					 LCD_WRITE_STRING("in 10 seconds");
					 
					 io_write_pin(GPIO_D , 6 , HIGH);
					 
					 for (i=0 ; i<10 ; i++)
					 {
						 _delay_ms(3500);
						 LED_OFF(GPIO_D , 0);
						 _delay_ms(3500);
						 LED_ON(GPIO_D , 0);
					 }
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					 io_write_pin(GPIO_D , 6 , LOW);
					 
					 LCD_WRITE_COMMAND(0x0C);
					 LCD_WRITE_STRING("Please wait...");
					 
					 LED_OFF(GPIO_D , 0);
					 LED_ON(GPIO_D , 3);
					 
					 _delay_ms(40000);
					 LED_OFF(GPIO_D , 3);
					 LCD_CLEAR();
					 _delay_ms(300);
					 
					 LCD_WRITE_STRING("1.back    2.exit");
					 key3 = GET_PRESSED();
					 
					 if (key3 == '1')
					 {
						 LCD_CLEAR();
						 _delay_ms(300);
						 
						 goto jump;
					 }
					 else if (key3 == '2')
					 {
						 goto next14;
					 }
					 
					 next14:
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					  
					 LCD_WRITE_STRING("Pick up the card");
					 _delay_ms(40000);
					 LCD_CLEAR();
					 _delay_ms(300);
					   
					 
					 
				 }
				 else if (key3 == '5' || key3 == '6' || key3 == '7' || key3 == '8' || key3 == '9' || key3 == '0' || key3 == '#')
				 {
					 LCD_CLEAR();
					 _delay_ms(300);
					  
					 goto jump3;
				 }
				 else if (key3 == '*')
				 {
					 goto jump;
				 }
				  
			 }
			 
			 
			 
			 else if (key2 == '2')//Deposit
			 {
				 
				 LCD_CLEAR();
				 _delay_ms(300);
				 
				jump2:
				 
				 LCD_WRITE_STRING("1.(10) 3.(1000)");
				 LCD_WRITE_COMMAND(0xC0);
				 LCD_WRITE_STRING("2.(100)4.(10000)");
				 
				
				 key3 = GET_PRESSED();
				 
				 if (key3 == '1')
				 {
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					 
					 LCD_WRITE_COMMAND(0X0F);
					 
					enter6:
					 
					 LCD_WRITE_STRING("Enter a number:");
					 LCD_WRITE_COMMAND(0xC0);
					 
					 for (i=0 ; i<2 ; i++)
					 {
						 money_decimals[i] = GET_PRESSED();
						 LCD_WRITE_DATA(money_decimals[i]);
					 }
					 
					 for (i=0 ; i<2 ; i++)
					 {
						 
						 if (strcmp(money_decimals[i] , '*') == 0 || strcmp(money_decimals[i] , '#') == 0)
						 {
							 _delay_ms(4000);
							 LCD_CLEAR();
							 _delay_ms(300);
							 
							 LCD_WRITE_STRING("Wrong number");
							 LCD_WRITE_COMMAND(0xC0);
							 LCD_WRITE_STRING("Please try Again");
							 
							 LCD_WRITE_COMMAND(0x0C);
							 _delay_ms(10000);
							 
							 LCD_CLEAR();
							 _delay_ms(300);
							 
							 LCD_WRITE_COMMAND(0x0F);
							 
							 goto enter6;
						 }
						 
					 }
					 
					 
					  key3 = GET_PRESSED();
					  
					  if (key3 == '*')
					  {
						  LCD_CLEAR();
						  _delay_ms(300);
						  
						  goto jump2;
					  }
					  else if (key3 == '#')
					  {
						  goto next5;
					  }
					  
					  next5:
					 
					 money_decimals_num = atoi(money_decimals);
					 
					 customers[flag].cash = customers[flag].cash + money_decimals_num;
					
					 LCD_CLEAR();
					 _delay_ms(300);
					 
					 LCD_WRITE_COMMAND(0X0C);
					 
					 LCD_WRITE_STRING("Deposit money");
					 LCD_WRITE_COMMAND(0xC0);
					 LCD_WRITE_STRING("in 10 seconds");
					 
					 io_write_pin(GPIO_D , 7 , HIGH);
					 
					 for (i=0 ; i<10 ; i++)
					 {
						 _delay_ms(3500);
						 LED_OFF(GPIO_D , 0);
						 _delay_ms(3500);
						 LED_ON(GPIO_D , 0);
					 }
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					 io_write_pin(GPIO_D , 7 , LOW);
					 
					 LCD_WRITE_COMMAND(0x0C);
					 LCD_WRITE_STRING("Please wait...");
					 
					 LED_OFF(GPIO_D , 0);
					 LED_ON(GPIO_D , 3);
					 
					 _delay_ms(40000);
					 LED_OFF(GPIO_D , 3);
					 LCD_CLEAR();
					 _delay_ms(300);
				     
					 LCD_WRITE_STRING("1.back    2.exit");
					 key3 = GET_PRESSED();
					 
					 if (key3 == '1')
					 {
						 LCD_CLEAR();
						 _delay_ms(300);
						 
						 goto jump;
					 }
					 else if (key3 == '2')
					 {
						 goto next15;
					 }
					 
					 next15:
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					 
					 LCD_WRITE_STRING("Pick up the card");
					 _delay_ms(40000);
					 LCD_CLEAR();
					 _delay_ms(300);
					  
					  
					 
				 }
				 else if (key3 == '2')
				 {
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					  
					 LCD_WRITE_COMMAND(0X0F);
					 
					enter7:
					 
					 LCD_WRITE_STRING("Enter a number:");
					 LCD_WRITE_COMMAND(0xC0);
					 
					 for (i=0 ; i<3 ; i++)
					 {
						 money_hundreds[i] = GET_PRESSED();
						 LCD_WRITE_DATA(money_hundreds[i]);
					 }
					 
					 for (i=0 ; i<3 ; i++)
					 {
						 
						 if (strcmp(money_hundreds[i] , '*') == 0 || strcmp(money_hundreds[i] , '#') == 0)
						 {
							 _delay_ms(4000);
							 LCD_CLEAR();
							 _delay_ms(300);
							 
							 LCD_WRITE_STRING("Wrong number");
							 LCD_WRITE_COMMAND(0xC0);
							 LCD_WRITE_STRING("Please try Again");
							 
							 LCD_WRITE_COMMAND(0x0C);
							 _delay_ms(10000);
							 
							 LCD_CLEAR();
							 _delay_ms(300);
							 
							 LCD_WRITE_COMMAND(0x0F);
							 
							 goto enter7;
						 }
						 
					 }
					 
					 
					 key3 = GET_PRESSED();
					 
					 if (key3 == '*')
					 {
						 LCD_CLEAR();
						 _delay_ms(300);
						 
						 goto jump2;
					 }
					 else if (key3 == '#')
					 {
						 goto next6;
					 }
					 
					 next6:
					 
					 money_hundreds_num = atoi(money_hundreds);
					 
					 customers[flag].cash = customers[flag].cash + money_hundreds_num;
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					 
					 LCD_WRITE_COMMAND(0X0C);
					 
					 LCD_WRITE_STRING("Deposit money");
					 LCD_WRITE_COMMAND(0xC0);
					 LCD_WRITE_STRING("in 10 seconds");
					 
					 io_write_pin(GPIO_D , 7 , HIGH);
					 
					 for (i=0 ; i<10 ; i++)
					 {
						  _delay_ms(3500);
						  LED_OFF(GPIO_D , 0);
						  _delay_ms(3500);
						  LED_ON(GPIO_D , 0);
					 }
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					 io_write_pin(GPIO_D , 7 , LOW);
					 
					 
					 LCD_WRITE_COMMAND(0x0C);
					 LCD_WRITE_STRING("Please wait...");
					 
					 LED_OFF(GPIO_D , 0);
					 LED_ON(GPIO_D , 3);
					 
					 _delay_ms(40000);
					 LED_OFF(GPIO_D , 3);
					 LCD_CLEAR();
					 _delay_ms(300);
					  
					 LCD_WRITE_STRING("1.back    2.exit");
					 key3 = GET_PRESSED();
					 
					 if (key3 == '1')
					 {
						 LCD_CLEAR();
						 _delay_ms(300);
						 
						 goto jump;
					 }
					 else if (key3 == '2')
					 {
						 goto next16;
					 }
					 
					 next16:
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					  
					 LCD_WRITE_STRING("Pick up the card");
					 _delay_ms(40000);
					 LCD_CLEAR();
					 _delay_ms(300);
					   
					  
					 
				 }
				 else if (key3 == '3')
				 {
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					  
					 LCD_WRITE_COMMAND(0X0F);
					 
					enter8:
					 
					 LCD_WRITE_STRING("Enter a number:");
					 LCD_WRITE_COMMAND(0xC0);
					 
					 for (i=0 ; i<4 ; i++)
					 {
						 money_thusends[i] = GET_PRESSED();
						 LCD_WRITE_DATA(money_thusends[i]);
					 }
					 
					 for (i=0 ; i<4 ; i++)
					 {
						 
						 if (strcmp(money_thusends[i] , '*') == 0 || strcmp(money_thusends[i] , '#') == 0)
						 {
							 _delay_ms(4000);
							 LCD_CLEAR();
							 _delay_ms(300);
							 
							 LCD_WRITE_STRING("Wrong number");
							 LCD_WRITE_COMMAND(0xC0);
							 LCD_WRITE_STRING("Please try Again");
							 
							 LCD_WRITE_COMMAND(0x0C);
							 _delay_ms(10000);
							 
							 LCD_CLEAR();
							 _delay_ms(300);
							 
							 LCD_WRITE_COMMAND(0x0F);
							 
							 goto enter8;
						 }
						 
					 }
					 
					 
					key3 = GET_PRESSED();
					
					if (key3 == '*')
					{
						LCD_CLEAR();
						_delay_ms(300);
						
						goto jump2;
					}
					else if (key3 == '#')
					{
						goto next7;
					}
					
					next7:
					 
					  for (i=0 ; i<4 ; i++)
					  {
						  money_thusends_number[i] = charToint(money_thusends[i]);
					  }
					  
					  money_thusends_num = array_to_num(money_thusends_number , 4);
					 
					 customers[flag].cash = customers[flag].cash + money_thusends_num;
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					 
					 LCD_WRITE_COMMAND(0X0C);
					 
					 LCD_WRITE_STRING("Deposit money");
					 LCD_WRITE_COMMAND(0xC0);
					 LCD_WRITE_STRING("in 10 seconds");
					 
					 io_write_pin(GPIO_D , 7 , HIGH);
					 
					 for (i=0 ; i<10 ; i++)
					 {
						  _delay_ms(3500);
						  LED_OFF(GPIO_D , 0);
						  _delay_ms(3500);
						  LED_ON(GPIO_D , 0);
					 }
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					 io_write_pin(GPIO_D , 7 , LOW);
					 
					 LCD_WRITE_COMMAND(0x0C);
					 LCD_WRITE_STRING("Please wait...");
					 
					 LED_OFF(GPIO_D , 0);
					 LED_ON(GPIO_D , 3);
					 
					 _delay_ms(40000);
					 LED_OFF(GPIO_D , 3);
					 LCD_CLEAR();
					 _delay_ms(300);
					 
				     LCD_WRITE_STRING("1.back    2.exit");
				     key3 = GET_PRESSED();
				     
				     if (key3 == '1')
				     {
					     LCD_CLEAR();
					     _delay_ms(300);
					     
					     goto jump;
				     }
				     else if (key3 == '2')
				     {
					     goto next17;
				     }
				     
				     next17:
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					  
					 LCD_WRITE_STRING("Pick up the card");
					 _delay_ms(40000);
					 LCD_CLEAR();
					 _delay_ms(300);
					 
					  
				 }
				 else if (key3 == '4')
				 {
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					 
					 LCD_WRITE_COMMAND(0X0F);
					
					enter9:
					
					 LCD_WRITE_STRING("Enter a number:");
					 LCD_WRITE_COMMAND(0xC0);
					
					 for (i=0 ; i<5 ; i++)
					 {
						 money_ten_thusends[i] = GET_PRESSED();
						 LCD_WRITE_DATA(money_ten_thusends[i]);
					 }
					 
					 for (i=0 ; i<5 ; i++)
					 {
						 
						 if (strcmp(money_ten_thusends[i] , '*') == 0 || strcmp(money_ten_thusends[i] , '#') == 0)
						 {
							 _delay_ms(4000);
							 LCD_CLEAR();
							 _delay_ms(300);
							 
							 LCD_WRITE_STRING("Wrong number");
							 LCD_WRITE_COMMAND(0xC0);
							 LCD_WRITE_STRING("Please try Again");
							 
							 LCD_WRITE_COMMAND(0x0C);
							 _delay_ms(10000);
							 
							 LCD_CLEAR();
							 _delay_ms(300);
							 
							 LCD_WRITE_COMMAND(0x0F);
							 
							 goto enter9;
						 }
						 
					 }
					 
					 
					key3 = GET_PRESSED();
					
					if (key3 == '*')
					{
						LCD_CLEAR();
						_delay_ms(300);
						
						goto jump2;
					}
					else if (key3 == '#')
					{
						goto next8;
					}
					
					next8:
					
					 for (i=0 ; i<5 ; i++)
					 {
						 money_ten_thusends_number[i] = charToint(money_ten_thusends[i]);
					 }
					 
					 money_ten_thusends_num = array_to_num(money_ten_thusends_number , 5);
					 
					 customers[flag].cash = customers[flag].cash + money_ten_thusends_num;
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					 
					 LCD_WRITE_COMMAND(0X0C);
					 
					 LCD_WRITE_STRING("Deposit money");
					 LCD_WRITE_COMMAND(0xC0);
					 LCD_WRITE_STRING("in 10 seconds");
					 
					 io_write_pin(GPIO_D , 7 , HIGH);
					 
					 for (i=0 ; i<10 ; i++)
					 {
						 _delay_ms(3500);
						 LED_OFF(GPIO_D , 0);
						 _delay_ms(3500);
						 LED_ON(GPIO_D , 0);
					 }
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					 io_write_pin(GPIO_D , 7 , LOW);
					 
					 LCD_WRITE_COMMAND(0x0C);
					 LCD_WRITE_STRING("Please wait...");
					 
					 LED_OFF(GPIO_D , 0);
					 LED_ON(GPIO_D , 3);
					 
					 _delay_ms(40000);
					 LED_OFF(GPIO_D , 3);
					 LCD_CLEAR();
					 _delay_ms(300);
					  
					 LCD_WRITE_STRING("1.back    2.exit");
					 key3 = GET_PRESSED();
					 
					 if (key3 == '1')
					 {
						 LCD_CLEAR();
						 _delay_ms(300);
						 
						 goto jump;
					 }
					 else if (key3 == '2')
					 {
						 goto next18;
					 }
					 
					 next18:
					 
					 LCD_CLEAR();
					 _delay_ms(300);
					 
					 LCD_WRITE_STRING("Pick up the card");
					 _delay_ms(40000);
					 LCD_CLEAR();
					 _delay_ms(300);
					  
					 
				 }
				 else if (key3 == '5' || key3 == '6' || key3 == '7' || key3 == '8' || key3 == '9' || key3 == '0' || key3 == '#')
				 {
					 LCD_CLEAR();
					 _delay_ms(300);
					  
					 goto jump2;
				 }
				 else if (key3 == '*')
				 {
					 goto jump;
				 }
				  

			 }
			 
			 
			 else if (key2 == '3')//cash
			 {
				 cash:
				  
				  LCD_CLEAR();
				  _delay_ms(300);
				  
				  LCD_WRITE_STRING("your cash:");
				  LCD_WRITE_COMMAND(0xC0);
				  sprintf(cash_num, "%ld", customers[flag].cash);
				  
				  LCD_WRITE_STRING(cash_num);
				  LCD_WRITE_STRING("$");
				  
				  key4 = GET_PRESSED();
				  
				   if (key4 == '*')
				   {
					   goto jump;
				   }
				   else if (key4 == '1' || key4 == '2' || key4 == '3' || key4 == '4' || key4 == '5' || key4 == '6' || key4 == '7' ||
				            key4 == '8' || key4 == '9' || key4 == '0' || key4 == '#')
				   {
					   goto cash;
				   }
				  
				  _delay_ms(50000);
				  LCD_CLEAR();
				  _delay_ms(300);
				  
				  LED_OFF(GPIO_D , 0);
				  
				  LCD_WRITE_STRING("Please wait...");
				  _delay_ms(40000);
				  LCD_CLEAR();
				  _delay_ms(300);
				  
				   LCD_WRITE_STRING("1.back    2.exit");
				   key3 = GET_PRESSED();
				   
				   if (key3 == '1')
				   {
					   LCD_CLEAR();
					   _delay_ms(300);
					   
					   goto jump;
				   }
				   else if (key3 == '2')
				   {
					   goto next19;
				   }
				   
				   next19:
				   
				   LCD_CLEAR();
				   _delay_ms(300);
				   
				  LCD_WRITE_STRING("Pick up the card");
				  _delay_ms(40000);
				  LCD_CLEAR();
				  _delay_ms(300);
				
			 }
			 else if (key2 == '4')
			 {
				  LED_OFF(GPIO_D , 0);
				  
				  LCD_CLEAR();
				  _delay_ms(300);
				  
				  LCD_WRITE_STRING("Pick up the card");
				  _delay_ms(40000);
				  LCD_CLEAR();
				  _delay_ms(300);
			 }
			 else if (key2 == '5' || key2 == '6' || key2 == '7' || key2 == '8' || key2 == '9' || key2 == '0' || key2 == '#' ||  key2 == '*')
			 {
				 goto jump;
			 }
			
			flag = -1;
			LCD_WRITE_COMMAND(0x0F);
			
		 } 
		 else if(flag == -1)
		 {
			 LED_ON(GPIO_D , 3);
			 
			 LCD_CLEAR();
			 _delay_ms(300);
			 
			 LCD_WRITE_STRING("Wrong Password");
			 LCD_WRITE_COMMAND(0xC0);
			 LCD_WRITE_STRING("Please try again");
			 
			  if (GET_PRESSED() == '*')
			  {
				  LCD_CLEAR();
				  _delay_ms(300);
				  
				  LED_OFF(GPIO_D , 3);
				  
				  goto jump4;
			  }
			 
			 _delay_ms(10000);
			 LED_OFF(GPIO_D , 3);
			 
			 LCD_CLEAR();
			 _delay_ms(300);
			 
			 LCD_WRITE_COMMAND(0x0C);
			 LCD_WRITE_STRING("Please wait...");
			 _delay_ms(40000);
			 LCD_CLEAR();
			 _delay_ms(300);
			  
			 LCD_WRITE_STRING("Pick up the card");
			 _delay_ms(40000);
			 LCD_CLEAR();
			 _delay_ms(300);
			  
			
		 }
		
		LCD_WRITE_COMMAND(0x0F);
		 
  }	
	
		  //HOURES(); : digital clock
	 
}

