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

unsigned char const   x_text=0;
const unsigned char   y_text=0;

//***************************************************************************
// ?????? ????????: 5x8. ????????????? ??? ????????????? ??????????? ???????
 unsigned char const nlcd_Font[][5]={
        {0x00, 0x00, 0x00, 0x00, 0x00},// (space)
        {0x00, 0x00, 0x5F, 0x00, 0x00},// !
        {0x00, 0x07, 0x00, 0x07, 0x00},// "
        {0x14, 0x7F, 0x14, 0x7F, 0x14},// #
        {0x24, 0x2A, 0x7F, 0x2A, 0x12},// $
        {0x23, 0x13, 0x08, 0x64, 0x62},// %
        {0x36, 0x49, 0x55, 0x22, 0x50},// &
        {0x00, 0x05, 0x03, 0x00, 0x00},// '
        {0x00, 0x1C, 0x22, 0x41, 0x00},// (
        {0x00, 0x41, 0x22, 0x1C, 0x00},// )
        {0x08, 0x2A, 0x1C, 0x2A, 0x08},// *
        {0x08, 0x08, 0x3E, 0x08, 0x08},// +
        {0x00, 0x50, 0x30, 0x00, 0x00},// ,
        {0x08, 0x08, 0x08, 0x08, 0x08},// -
        {0x00, 0x30, 0x30, 0x00, 0x00},// .
        {0x20, 0x10, 0x08, 0x04, 0x02},// /
        {0x3E, 0x51, 0x49, 0x45, 0x3E},// 0
        {0x00, 0x42, 0x7F, 0x40, 0x00},// 1
        {0x42, 0x61, 0x51, 0x49, 0x46},// 2
        {0x21, 0x41, 0x45, 0x4B, 0x31},// 3
        {0x18, 0x14, 0x12, 0x7F, 0x10},// 4
        {0x27, 0x45, 0x45, 0x45, 0x39},// 5
        {0x3C, 0x4A, 0x49, 0x49, 0x30},// 6
        {0x01, 0x71, 0x09, 0x05, 0x03},// 7
        {0x36, 0x49, 0x49, 0x49, 0x36},// 8
        {0x06, 0x49, 0x49, 0x29, 0x1E},// 9
        {0x00, 0x36, 0x36, 0x00, 0x00},// :
        {0x00, 0x56, 0x36, 0x00, 0x00},// ;
        {0x00, 0x08, 0x14, 0x22, 0x41},// <
        {0x14, 0x14, 0x14, 0x14, 0x14},// =
        {0x41, 0x22, 0x14, 0x08, 0x00},// >
        {0x02, 0x01, 0x51, 0x09, 0x06},// ?
        {0x32, 0x49, 0x79, 0x41, 0x3E},// @
        {0x7E, 0x11, 0x11, 0x11, 0x7E},// A
        {0x7F, 0x49, 0x49, 0x49, 0x36},// B
        {0x3E, 0x41, 0x41, 0x41, 0x22},// C
        {0x7F, 0x41, 0x41, 0x22, 0x1C},// D
        {0x7F, 0x49, 0x49, 0x49, 0x41},// E
        {0x7F, 0x09, 0x09, 0x01, 0x01},// F
        {0x3E, 0x41, 0x41, 0x51, 0x32},// G
        {0x7F, 0x08, 0x08, 0x08, 0x7F},// H
        {0x00, 0x41, 0x7F, 0x41, 0x00},// I
        {0x20, 0x40, 0x41, 0x3F, 0x01},// J
        {0x7F, 0x08, 0x14, 0x22, 0x41},// K
        {0x7F, 0x40, 0x40, 0x40, 0x40},// L
        {0x7F, 0x02, 0x04, 0x02, 0x7F},// M
        {0x7F, 0x04, 0x08, 0x10, 0x7F},// N
        {0x3E, 0x41, 0x41, 0x41, 0x3E},// O
        {0x7F, 0x09, 0x09, 0x09, 0x06},// P
        {0x3E, 0x41, 0x51, 0x21, 0x5E},// Q
        {0x7F, 0x09, 0x19, 0x29, 0x46},// R
        {0x46, 0x49, 0x49, 0x49, 0x31},// S
        {0x01, 0x01, 0x7F, 0x01, 0x01},// T
        {0x3F, 0x40, 0x40, 0x40, 0x3F},// U
        {0x1F, 0x20, 0x40, 0x20, 0x1F},// V
        {0x7F, 0x20, 0x18, 0x20, 0x7F},// W
        {0x63, 0x14, 0x08, 0x14, 0x63},// X
        {0x03, 0x04, 0x78, 0x04, 0x03},// Y
        {0x61, 0x51, 0x49, 0x45, 0x43},// Z
        {0x00, 0x00, 0x7F, 0x41, 0x41},// [
        {0x02, 0x04, 0x08, 0x10, 0x20},// "\"
        {0x41, 0x41, 0x7F, 0x00, 0x00},// ]
        {0x04, 0x02, 0x01, 0x02, 0x04},// ^
        {0x40, 0x40, 0x40, 0x40, 0x40},// _
        {0x00, 0x01, 0x02, 0x04, 0x00},// `
        {0x20, 0x54, 0x54, 0x54, 0x78},// a
        {0x7F, 0x48, 0x44, 0x44, 0x38},// b
        {0x38, 0x44, 0x44, 0x44, 0x20},// c
        {0x38, 0x44, 0x44, 0x48, 0x7F},// d
        {0x38, 0x54, 0x54, 0x54, 0x18},// e
        {0x08, 0x7E, 0x09, 0x01, 0x02},// f
        {0x08, 0x14, 0x54, 0x54, 0x3C},// g
        {0x7F, 0x08, 0x04, 0x04, 0x78},// h
        {0x00, 0x44, 0x7D, 0x40, 0x00},// i
        {0x20, 0x40, 0x44, 0x3D, 0x00},// j
        {0x00, 0x7F, 0x10, 0x28, 0x44},// k
        {0x00, 0x41, 0x7F, 0x40, 0x00},// l
        {0x7C, 0x04, 0x18, 0x04, 0x78},// m
        {0x7C, 0x08, 0x04, 0x04, 0x78},// n
        {0x38, 0x44, 0x44, 0x44, 0x38},// o
        {0x7C, 0x14, 0x14, 0x14, 0x08},// p
        {0x08, 0x14, 0x14, 0x18, 0x7C},// q
        {0x7C, 0x08, 0x04, 0x04, 0x08},// r
        {0x48, 0x54, 0x54, 0x54, 0x20},// s
        {0x04, 0x3F, 0x44, 0x40, 0x20},// t
        {0x3C, 0x40, 0x40, 0x20, 0x7C},// u
        {0x1C, 0x20, 0x40, 0x20, 0x1C},// v
        {0x3C, 0x40, 0x30, 0x40, 0x3C},// w
        {0x44, 0x28, 0x10, 0x28, 0x44},// x
        {0x0C, 0x50, 0x50, 0x50, 0x3C},// y
        {0x44, 0x64, 0x54, 0x4C, 0x44},// z
        {0x00, 0x08, 0x36, 0x41, 0x00},// {
        {0x00, 0x00, 0x7F, 0x00, 0x00},// |
        {0x00, 0x41, 0x36, 0x08, 0x00},// }
        {0x02, 0x01, 0x02, 0x04, 0x02},// ~
        {0x08, 0x1C, 0x2A, 0x08, 0x08} // <-
#ifdef FULL_CHARSET
,         //???????? ????????????? ????????? 866 ?? ??????? "?", ????? - ??????????????

        { 0x7E, 0x11, 0x11, 0x11, 0x7E },  // ?
        { 0x7F, 0x49, 0x49, 0x49, 0x33 },  // ?
        { 0x7F, 0x49, 0x49, 0x49, 0x36 },  // ?
        { 0x7F, 0x01, 0x01, 0x01, 0x03 },  // ?
        { 0xE0, 0x51, 0x4F, 0x41, 0xFF },  // ?
        { 0x7F, 0x49, 0x49, 0x49, 0x49 },  // ?
        { 0x77, 0x08, 0x7F, 0x08, 0x77 },  // ?
        { 0x49, 0x49, 0x49, 0x49, 0x36 },  // ?
        { 0x7F, 0x10, 0x08, 0x04, 0x7F },  // ?
        { 0x7C, 0x21, 0x12, 0x09, 0x7C },  // ?
        { 0x7F, 0x08, 0x14, 0x22, 0x41 },  // ?
        { 0x20, 0x41, 0x3F, 0x01, 0x7F },  // ?
        { 0x7F, 0x02, 0x0C, 0x02, 0x7F },  // ?
        { 0x7F, 0x08, 0x08, 0x08, 0x7F },  // ?
        { 0x3E, 0x41, 0x41, 0x41, 0x3E },  // ?
        { 0x7F, 0x01, 0x01, 0x01, 0x7F },  // ?
        { 0x7F, 0x09, 0x09, 0x09, 0x06 },  // ?
        { 0x3E, 0x41, 0x41, 0x41, 0x22 },  // ?
        { 0x01, 0x01, 0x7F, 0x01, 0x01 },  // ?
        { 0x27, 0x48, 0x48, 0x48, 0x3F },  // ?
        { 0x1C, 0x22, 0x7F, 0x22, 0x1C },  // ?
        { 0x63, 0x14, 0x08, 0x14, 0x63 },  // ?
        { 0x7F, 0x40, 0x40, 0x40, 0xFF },  // ?
        { 0x07, 0x08, 0x08, 0x08, 0x7F },  // ?
        { 0x7F, 0x40, 0x7F, 0x40, 0x7F },  // ?
        { 0x7F, 0x40, 0x7F, 0x40, 0xFF },  // ?
        { 0x01, 0x7F, 0x48, 0x48, 0x30 },  // ?
        { 0x7F, 0x48, 0x30, 0x00, 0x7F },  // ?
        { 0x7F, 0x48, 0x48, 0x30, 0x00 },  // ?
        { 0x22, 0x41, 0x49, 0x49, 0x3E },  // ?
        { 0x7F, 0x08, 0x3E, 0x41, 0x3E },  // ?
        { 0x46, 0x29, 0x19, 0x09, 0x7F },  // ?
        { 0x20, 0x54, 0x54, 0x54, 0x78 },  // ?
        { 0x3C, 0x4A, 0x4A, 0x49, 0x31 },  // ?
        { 0x7C, 0x54, 0x54, 0x28, 0x00 },  // ?
        { 0x7C, 0x04, 0x04, 0x04, 0x0C },  // ?
        { 0xE0, 0x54, 0x4C, 0x44, 0xFC },  // ?
        { 0x38, 0x54, 0x54, 0x54, 0x08 },  // ?
        { 0x6C, 0x10, 0x7C, 0x10, 0x6C },  // ?
        { 0x44, 0x44, 0x54, 0x54, 0x28 },  // ?
        { 0x7C, 0x20, 0x10, 0x08, 0x7C },  // ?
        { 0x78, 0x42, 0x24, 0x12, 0x78 },  // ?
        { 0x7C, 0x10, 0x28, 0x44, 0x00 },  // ?
        { 0x20, 0x44, 0x3C, 0x04, 0x7C },  // ?
        { 0x7C, 0x08, 0x10, 0x08, 0x7C },  // ?
        { 0x7C, 0x10, 0x10, 0x10, 0x7C },  // ?
        { 0x38, 0x44, 0x44, 0x44, 0x38 },  // ?
        { 0x7C, 0x04, 0x04, 0x04, 0x7C },  // ?
        { 0x7C, 0x14, 0x14, 0x14, 0x08 },  // ?
        { 0x38, 0x44, 0x44, 0x44, 0x44 },  // ?
        { 0x04, 0x04, 0x7C, 0x04, 0x04 },  // ?
        { 0x0C, 0x50, 0x50, 0x50, 0x3C },  // ?
        { 0x18, 0x24, 0x7E, 0x24, 0x18 },  // ?
        { 0x44, 0x28, 0x10, 0x28, 0x44 },  // ?
        { 0x7C, 0x40, 0x40, 0x40, 0xFC },  // ?
        { 0x0C, 0x10, 0x10, 0x10, 0x7C },  // ?
        { 0x7C, 0x40, 0x7C, 0x40, 0x7C },  // ?
        { 0x7C, 0x40, 0x7C, 0x40, 0xFC },  // ?
        { 0x04, 0x7C, 0x50, 0x50, 0x20 },  // ?
        { 0x7C, 0x50, 0x20, 0x00, 0x7C },  // ?
        { 0x7C, 0x50, 0x50, 0x20, 0x00 },  // ?
        { 0x28, 0x44, 0x54, 0x54, 0x38 },  // ?
        { 0x7C, 0x10, 0x38, 0x44, 0x38 },  // ?
        { 0x08, 0x54, 0x34, 0x14, 0x7C }   // ?

#endif  /* FULL_CHARSET */
};

#include "app_config.h"
#include "nokia1100_lcd_lib.h"
//#include "nokia1100_lcd_font.h"        // ?????????? ????? (????? ???????? ? ??????????? ??????)

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
         else         SDA_LCD_RESET;

    SCLK_LCD_SET;

    for(i=0;i<8;i++)
    {
            SCLK_LCD_RESET;

        if(c & 0x80) SDA_LCD_SET;
         else             SDA_LCD_RESET;

        SCLK_LCD_SET;
        c <<= 1;

                _delay_us(NLCD_MIN_DELAY);        // ***** !!!!! 270 - Minimum delay at which the work my LCD-controller
    }

    CS_LCD_SET;
}

// ************************************************ ******************************
// Display the symbol on the LCD-controller in the current place
// C: character code
void nlcd_Putc(unsigned char c)
{
        unsigned char i;
        if (c>127) c=c-64;         // We transfer Cyrillic characters encoded at the beginning of the second CP1251
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
        if (c>127) c=c-64;         // We transfer Cyrillic characters encoded at the beginning of the second CP1251
                                                // Half of the table ASCII (starting with the code 0x80)

        for (i = 0; i < 5; i++ )
        {
                unsigned char glyph;
                 glyph= pgm_read_byte(&(nlcd_Font[c-32][i]));
                   nlcd_SendByte(DATA_LCD_MODE,glyph);
                   nlcd_SendByte(DATA_LCD_MODE,glyph);
    }

        nlcd_SendByte(DATA_LCD_MODE,0x00); // The gap between characters in the horizontal 1 pixel
//        nlcd_SendByte(DATA_LCD_MODE,0x00); // You can make two lines
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
         unsigned char const data_1;
//        while (data_=pgm_read_byte(message), data_)
//         data_1=pgm_read_byte(message);
        while (data_1)
        {
            nlcd_Putc(data_1);
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
        x=x*6;        // ????????? ?? ?????????? ? ???????? ? ??????????? ? ???????????
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
nlcd_Print("this is a test");
nlcd_GotoXY(22,22);
nlcd_Print("Www.Elasa.ir");
//nlcd_PrintWide("Www.Elasa.ir");
nlcd_GotoXY(33,33);
//nlcd_PrintF('testttttttt');
//nlcd_Clear();
}