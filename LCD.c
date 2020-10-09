#include <REGX52.H>

void command(unsigned char value);  // Function prototype
void display(unsigned char *v);         // Function prototype
void delay( unsigned int y);               // Function prototype

sbit rs=P3^0;	                //  Lcd Control  signals
sbit rw=P3^1;
sbit en=P3^2;

#define output P1                 //  Lcd data line


/*********** Main Function *************/
void main()
{

  command(0x38);
  command(0x01);
  command(0x06);
  command(0x0e);
  command(0x80);
  display(" Vivek & Pulkit  ");
  command(0xc0);
  display( "   DE & MC   ");


  while(1);

}
/***********End Main  Function ************/

/************* lcd command function ***********/
  void command (unsigned char value)
  {

	 output=value;
     rs=0;
	 rw=0;
	 en=1;
	 delay(20);		 //
	 en=0;
	}
/***********end command function  **************/


/************ lcd display function ***********/
void display( unsigned char *v)

{
	 while(*v)
	 {
	 	output=*v++;
     	rs=1;
	 	rw=0;
	 	en=1;
	 	delay(20);
	 	en=0;
	}
}
/************ end display function *************/

/************delay function *************/
void delay ( unsigned int y)
{
  	unsigned int i,j;
		for(i=0;i<y;i++)
		{
			for(j=0;j<1275;j++);
		}
}		  // end delay function

/*************** end delay function **********/
