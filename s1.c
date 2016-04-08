//***************************************************************************
//  File........: nokia1100_lcd_lib.c
//  Author(s)...: Chiper
//  URL(s)......: http://digitalchip.ru/
//  Device(s)...: ATMega...
//  Compiler....: AVR-GCC
//  Description.: ??????? LCD-??????????? ?? Nokia1100
//  Data........: 21.02.12
//  Version.....: 1.1 
//***************************************************************************
//  Notice: All control contacts LCD-controller must be connected to
// The same port on the microcontroller
// ************************************************ ***************************
//***************************************************************************

#include "app_config.h"
#include "nokia1100_lcd_lib.h"
#include "nokia1100_lcd_font.h"	// ?????????? ????? (????? ???????? ? ??????????? ??????)

//******************************************************************************
// Initialize the controller
void nlcd_Init(void)
{	
	// Initialize the port to output for use with LCD-controller
	DDR_LCD |= (1<<SCLK_LCD_PIN)|(1<<SDA_LCD_PIN)|(1<<CS_LCD_PIN)|(1<<RST_LCD_PIN);

	CS_LCD_RESET;
	RST_LCD_RESET;

	_delay_ms(5);            // Waiting for at least 5ms to install the generator (less than 5 ms can be broken)

	RST_LCD_SET;

	nlcd_SendByte(CMD_LCD_MODE,0xE2); // *** SOFTWARE RESET 

	nlcd_SendByte(CMD_LCD_MODE,0x3A); // *** Use internal oscillator
	nlcd_SendByte(CMD_LCD_MODE,0xEF); // *** FRAME FREQUENCY:
	nlcd_SendByte(CMD_LCD_MODE,0x04); // *** 80Hz
	nlcd_SendByte(CMD_LCD_MODE,0xD0); // *** 1:65 divider
	
	nlcd_SendByte(CMD_LCD_MODE,0x20); // Write to the register Vop
	nlcd_SendByte(CMD_LCD_MODE,0x90);

	nlcd_SendByte(CMD_LCD_MODE,0xA4); // all on/normal display

	nlcd_SendByte(CMD_LCD_MODE,0x2F); // Power control set(charge pump on/off)
									  // Defines the contrast

	nlcd_SendByte(CMD_LCD_MODE,0x40); // set start row address = 0
	nlcd_SendByte(CMD_LCD_MODE,0xB0); // Set the Y-address = 0
	nlcd_SendByte(CMD_LCD_MODE,0x10); // Set the X-address, 3-bit older
	nlcd_SendByte(CMD_LCD_MODE,0x0);  // Set the X-address, the lower 4 bits

	//nlcd_SendByte(CMD_LCD_MODE,0xC8); // mirror Y axis (about X axis)
	//nlcd_SendByte(CMD_LCD_MODE,0xA1); // Invert the screen horizontally


	nlcd_SendByte(CMD_LCD_MODE,0xAC); // set initial row (R0) of the display
	nlcd_SendByte(CMD_LCD_MODE,0x07);

	//nlcd_SendByte(CMD_LCD_MODE,0xF9); //

	nlcd_SendByte(CMD_LCD_MODE,0xAF); // Display on / off

	nlcd_Clear(); // clear LCD
}

//******************************************************************************
// Clear the screen
void nlcd_Clear(void)
{
	unsigned int i;
	nlcd_SendByte(CMD_LCD_MODE,0x40); // Y = 0
	nlcd_SendByte(CMD_LCD_MODE,0xB0);
	nlcd_SendByte(CMD_LCD_MODE,0x10); // X = 0
	nlcd_SendByte(CMD_LCD_MODE,0x00);
	//nlcd_SendByte(CMD_LCD_MODE,0xAE); // disable display;
	
	for(i=0;i<864;i++) nlcd_SendByte(DATA_LCD_MODE,0x00);
	
	//nlcd_SendByte(CMD_LCD_MODE,0x07);
	//nlcd_SendByte(CMD_LCD_MODE,0xAF); // enable display;
}


// ************************************************ ******************************
// Byte is transmitted (command or data) to the LCD-controller
// Mode: CMD_LCD_MODE - pass command
// DATA_LCD_MODE - transfer data
// C: the value of the transmitted bytes
void nlcd_SendByte(char mode,unsigned char c)
{
	unsigned char i;
    CS_LCD_RESET;
    SCLK_LCD_RESET;
   
    if(mode) SDA_LCD_SET;
	 else	 SDA_LCD_RESET;
    
    SCLK_LCD_SET;

    for(i=0;i<8;i++)
    {
    	SCLK_LCD_RESET;

        if(c & 0x80) SDA_LCD_SET;
         else	     SDA_LCD_RESET;

        SCLK_LCD_SET;
        c <<= 1;
        
		_delay_us(NLCD_MIN_DELAY);	// ***** !!!!! 270 - Minimum delay at which the work my LCD-controller
    }

    CS_LCD_SET;
}

// ************************************************ ******************************
// Display the symbol on the LCD-controller in the current place
// C: character code
void nlcd_Putc(unsigned char c)
{
	unsigned char i;
	if (c>127) c=c-64; 	// We transfer Cyrillic characters encoded at the beginning of the second CP1251
						// Half of the table ASCII (starting with the code 0x80)
	
	for (i = 0; i < 5; i++ )
	{
    	nlcd_SendByte(DATA_LCD_MODE,pgm_read_byte(&(nlcd_Font[c-32][i])));
    }
    
	nlcd_SendByte(DATA_LCD_MODE,0x00); // The gap between characters in the horizontal 1 pixel
}

// ************************************************ ******************************
// Display a wide character LCD-screen NOKIA 1100 in the current place
// C: character code
void nlcd_PutcWide(unsigned char c)
{
	unsigned char i;
	if (c>127) c=c-64; 	// We transfer Cyrillic characters encoded at the beginning of the second CP1251
						// Half of the table ASCII (starting with the code 0x80)

	for (i = 0; i < 5; i++ )
	{
		unsigned char glyph = pgm_read_byte(&(nlcd_Font[c-32][i]));
	   	nlcd_SendByte(DATA_LCD_MODE,glyph);
	   	nlcd_SendByte(DATA_LCD_MODE,glyph);
    }
    
	nlcd_SendByte(DATA_LCD_MODE,0x00); // The gap between characters in the horizontal 1 pixel
//	nlcd_SendByte(DATA_LCD_MODE,0x00); // You can make two lines
}

// ************************************************ ******************************
// Display the string of characters on the LCD-controller in the current location. If the line comes out
// Of the screen in the current line, the balance is transferred to the next line.
// Message: a pointer to a character string. 0x00 - a sign of the end of the line.
void nlcd_Print(char * message)
{
	while (*message) /// End of line marked zero
	{ 
    	nlcd_Putc(*message++);
    }
}

// ************************************************ ******************************
// Display the string of characters on the LCD-controller in the current location of the program memory.
// If the string is out of the screen in the current line, the balance is transferred to the next line.
// Message: a pointer to a string in program memory. 0x00 - a sign of the end of the line.
void nlcd_PrintF(unsigned char * message)
{
	unsigned char data;
	while (data=pgm_read_byte(message), data)
	{ 
    	nlcd_Putc(data);
		message++;
    }
}

// ************************************************ ******************************
// Display the string of characters double width on the LCD-screen NOKIA 1100 in the current place
// Of RAM. If the line is outside the screen in the current row, then the residue was
// On the next line.
// Message: a pointer to a string in program memory. 0x00 - a sign of the end of the line.
void nlcd_PrintWide(unsigned char * message)
{
	while (*message) nlcd_PutcWide(*message++);  // ????? ?????? ????????? ?????
}

// ************************************************ ******************************
// Set the cursor to the desired position. Counting starts at the top
// Left. 16 character horizontally, vertically - 8
// X: 0..15
// Y: 0..7
void nlcd_GotoXY(char x,char y)
{
	x=x*6;	// ????????? ?? ?????????? ? ???????? ? ??????????? ? ???????????
	nlcd_SendByte(CMD_LCD_MODE,(0xB0|(y&0x0F)));      // ????????? ?????? ?? Y: 0100 yyyy         
    nlcd_SendByte(CMD_LCD_MODE,(0x00|(x&0x0F)));      // ????????? ?????? ?? X: 0000 xxxx - ???? (x3 x2 x1 x0)
    nlcd_SendByte(CMD_LCD_MODE,(0x10|((x>>4)&0x07))); // ????????? ?????? ?? X: 0010 0xxx - ???? (x6 x5 x4)

}

// ************************************************ ******************************
// Ustanavlivaer inversion mode the whole screen. A screen is not changed, only the inverted
// Mode: INV_MODE_ON or INV_MODE_OFF
void nlcd_Inverse(unsigned char mode)
{
	if (mode) nlcd_SendByte(CMD_LCD_MODE,0xA6);
	 else nlcd_SendByte(CMD_LCD_MODE,0xA7);
}

int main (void){
nlcd_Init();
nlcd_Print("sss");
nlcd_GotoXY(22,22);
nlcd_Print("Www.Elasa.ir");
nlcd_GotoXY(11,11);
nlcd_Print("Www.Elasa.ir");
//nlcd_PrintWide("Www.Elasa.ir");

//nlcd_PrintF('testttttttt');
//nlcd_Clear();
}
