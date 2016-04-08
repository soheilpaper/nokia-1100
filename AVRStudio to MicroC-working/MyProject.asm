
_nlcd_Init:

;MyProject.c,195 :: 		void nlcd_Init(void)
;MyProject.c,198 :: 		DDR_LCD |= (1<<SCLK_LCD_PIN)|(1<<SDA_LCD_PIN)|(1<<CS_LCD_PIN)|(1<<RST_LCD_PIN);
	PUSH       R2
	PUSH       R3
	IN         R16, DDRC+0
	ORI        R16, 240
	OUT        DDRC+0, R16
;MyProject.c,200 :: 		CS_LCD_RESET;
	IN         R16, PORTC+0
	ANDI       R16, 191
	OUT        PORTC+0, R16
;MyProject.c,201 :: 		RST_LCD_RESET;
	ANDI       R16, 127
	OUT        PORTC+0, R16
;MyProject.c,203 :: 		_delay_ms(5);            // Waiting for at least 5ms to install the generator (less than 5 ms can be broken)
	LDI        R17, 52
	LDI        R16, 242
L_nlcd_Init0:
	DEC        R16
	BRNE       L_nlcd_Init0
	DEC        R17
	BRNE       L_nlcd_Init0
	NOP
;MyProject.c,205 :: 		RST_LCD_SET;
	IN         R27, PORTC+0
	SBR        R27, 128
	OUT        PORTC+0, R27
;MyProject.c,207 :: 		nlcd_SendByte(CMD_LCD_MODE,0xE2); // *** SOFTWARE RESET
	LDI        R27, 226
	MOV        R3, R27
	CLR        R2
	CALL       _nlcd_SendByte+0
;MyProject.c,209 :: 		nlcd_SendByte(CMD_LCD_MODE,0x3A); // *** Use internal oscillator
	LDI        R27, 58
	MOV        R3, R27
	CLR        R2
	CALL       _nlcd_SendByte+0
;MyProject.c,210 :: 		nlcd_SendByte(CMD_LCD_MODE,0xEF); // *** FRAME FREQUENCY:
	LDI        R27, 239
	MOV        R3, R27
	CLR        R2
	CALL       _nlcd_SendByte+0
;MyProject.c,211 :: 		nlcd_SendByte(CMD_LCD_MODE,0x04); // *** 80Hz
	LDI        R27, 4
	MOV        R3, R27
	CLR        R2
	CALL       _nlcd_SendByte+0
;MyProject.c,212 :: 		nlcd_SendByte(CMD_LCD_MODE,0xD0); // *** 1:65 divider
	LDI        R27, 208
	MOV        R3, R27
	CLR        R2
	CALL       _nlcd_SendByte+0
;MyProject.c,214 :: 		nlcd_SendByte(CMD_LCD_MODE,0x20); // Write to the register Vop
	LDI        R27, 32
	MOV        R3, R27
	CLR        R2
	CALL       _nlcd_SendByte+0
;MyProject.c,215 :: 		nlcd_SendByte(CMD_LCD_MODE,0x90);
	LDI        R27, 144
	MOV        R3, R27
	CLR        R2
	CALL       _nlcd_SendByte+0
;MyProject.c,217 :: 		nlcd_SendByte(CMD_LCD_MODE,0xA4); // all on/normal display
	LDI        R27, 164
	MOV        R3, R27
	CLR        R2
	CALL       _nlcd_SendByte+0
;MyProject.c,219 :: 		nlcd_SendByte(CMD_LCD_MODE,0x2F); // Power control set(charge pump on/off)
	LDI        R27, 47
	MOV        R3, R27
	CLR        R2
	CALL       _nlcd_SendByte+0
;MyProject.c,222 :: 		nlcd_SendByte(CMD_LCD_MODE,0x40); // set start row address = 0
	LDI        R27, 64
	MOV        R3, R27
	CLR        R2
	CALL       _nlcd_SendByte+0
;MyProject.c,223 :: 		nlcd_SendByte(CMD_LCD_MODE,0xB0); // Set the Y-address = 0
	LDI        R27, 176
	MOV        R3, R27
	CLR        R2
	CALL       _nlcd_SendByte+0
;MyProject.c,224 :: 		nlcd_SendByte(CMD_LCD_MODE,0x10); // Set the X-address, 3-bit older
	LDI        R27, 16
	MOV        R3, R27
	CLR        R2
	CALL       _nlcd_SendByte+0
;MyProject.c,225 :: 		nlcd_SendByte(CMD_LCD_MODE,0x0);  // Set the X-address, the lower 4 bits
	CLR        R3
	CLR        R2
	CALL       _nlcd_SendByte+0
;MyProject.c,231 :: 		nlcd_SendByte(CMD_LCD_MODE,0xAC); // set initial row (R0) of the display
	LDI        R27, 172
	MOV        R3, R27
	CLR        R2
	CALL       _nlcd_SendByte+0
;MyProject.c,232 :: 		nlcd_SendByte(CMD_LCD_MODE,0x07);
	LDI        R27, 7
	MOV        R3, R27
	CLR        R2
	CALL       _nlcd_SendByte+0
;MyProject.c,236 :: 		nlcd_SendByte(CMD_LCD_MODE,0xAF); // Display on / off
	LDI        R27, 175
	MOV        R3, R27
	CLR        R2
	CALL       _nlcd_SendByte+0
;MyProject.c,238 :: 		nlcd_Clear(); // clear LCD
	CALL       _nlcd_Clear+0
;MyProject.c,239 :: 		}
L_end_nlcd_Init:
	POP        R3
	POP        R2
	RET
; end of _nlcd_Init

_nlcd_Clear:

;MyProject.c,243 :: 		void nlcd_Clear(void)
;MyProject.c,246 :: 		nlcd_SendByte(CMD_LCD_MODE,0x40); // Y = 0
	PUSH       R2
	PUSH       R3
	LDI        R27, 64
	MOV        R3, R27
	CLR        R2
	CALL       _nlcd_SendByte+0
;MyProject.c,247 :: 		nlcd_SendByte(CMD_LCD_MODE,0xB0);
	LDI        R27, 176
	MOV        R3, R27
	CLR        R2
	CALL       _nlcd_SendByte+0
;MyProject.c,248 :: 		nlcd_SendByte(CMD_LCD_MODE,0x10); // X = 0
	LDI        R27, 16
	MOV        R3, R27
	CLR        R2
	CALL       _nlcd_SendByte+0
;MyProject.c,249 :: 		nlcd_SendByte(CMD_LCD_MODE,0x00);
	CLR        R3
	CLR        R2
	CALL       _nlcd_SendByte+0
;MyProject.c,252 :: 		for(i=0;i<864;i++) nlcd_SendByte(DATA_LCD_MODE,0x00);
; i start address is: 18 (R18)
	LDI        R18, 0
	LDI        R19, 0
; i end address is: 18 (R18)
L_nlcd_Clear2:
; i start address is: 18 (R18)
	CPI        R19, 3
	BRNE       L__nlcd_Clear32
	CPI        R18, 96
L__nlcd_Clear32:
	BRLO       L__nlcd_Clear33
	JMP        L_nlcd_Clear3
L__nlcd_Clear33:
	PUSH       R19
	PUSH       R18
	CLR        R3
	LDI        R27, 1
	MOV        R2, R27
	CALL       _nlcd_SendByte+0
	POP        R18
	POP        R19
	MOVW       R16, R18
	SUBI       R16, 255
	SBCI       R17, 255
	MOVW       R18, R16
; i end address is: 18 (R18)
	JMP        L_nlcd_Clear2
L_nlcd_Clear3:
;MyProject.c,256 :: 		}
L_end_nlcd_Clear:
	POP        R3
	POP        R2
	RET
; end of _nlcd_Clear

_nlcd_SendByte:

;MyProject.c,264 :: 		void nlcd_SendByte(char mode,unsigned char c)
;MyProject.c,267 :: 		CS_LCD_RESET;
	IN         R16, PORTC+0
	ANDI       R16, 191
	OUT        PORTC+0, R16
;MyProject.c,268 :: 		SCLK_LCD_RESET;
	ANDI       R16, 239
	OUT        PORTC+0, R16
;MyProject.c,270 :: 		if(mode) SDA_LCD_SET;
	TST        R2
	BRNE       L__nlcd_SendByte35
	JMP        L_nlcd_SendByte5
L__nlcd_SendByte35:
	IN         R27, PORTC+0
	SBR        R27, 32
	OUT        PORTC+0, R27
	JMP        L_nlcd_SendByte6
L_nlcd_SendByte5:
;MyProject.c,271 :: 		else         SDA_LCD_RESET;
	IN         R16, PORTC+0
	ANDI       R16, 223
	OUT        PORTC+0, R16
L_nlcd_SendByte6:
;MyProject.c,273 :: 		SCLK_LCD_SET;
	IN         R16, PORTC+0
	ORI        R16, 16
	OUT        PORTC+0, R16
;MyProject.c,275 :: 		for(i=0;i<8;i++)
; i start address is: 17 (R17)
	LDI        R17, 0
; i end address is: 17 (R17)
L_nlcd_SendByte7:
; i start address is: 17 (R17)
	CPI        R17, 8
	BRLO       L__nlcd_SendByte36
	JMP        L_nlcd_SendByte8
L__nlcd_SendByte36:
;MyProject.c,277 :: 		SCLK_LCD_RESET;
	IN         R16, PORTC+0
	ANDI       R16, 239
	OUT        PORTC+0, R16
;MyProject.c,279 :: 		if(c & 0x80) SDA_LCD_SET;
	BST        R3, 7
	BRTS       L__nlcd_SendByte37
	JMP        L_nlcd_SendByte10
L__nlcd_SendByte37:
	IN         R16, PORTC+0
	ORI        R16, 32
	OUT        PORTC+0, R16
	JMP        L_nlcd_SendByte11
L_nlcd_SendByte10:
;MyProject.c,280 :: 		else             SDA_LCD_RESET;
	IN         R16, PORTC+0
	ANDI       R16, 223
	OUT        PORTC+0, R16
L_nlcd_SendByte11:
;MyProject.c,282 :: 		SCLK_LCD_SET;
	IN         R16, PORTC+0
	ORI        R16, 16
	OUT        PORTC+0, R16
;MyProject.c,283 :: 		c <<= 1;
	MOV        R16, R3
	LSL        R16
	MOV        R3, R16
;MyProject.c,285 :: 		_delay_us(NLCD_MIN_DELAY);        // ***** !!!!! 270 - Minimum delay at which the work my LCD-controller
	PUSH       R17
	LDI        R17, 3
	LDI        R16, 205
L_nlcd_SendByte12:
	DEC        R16
	BRNE       L_nlcd_SendByte12
	DEC        R17
	BRNE       L_nlcd_SendByte12
	NOP
	NOP
	POP        R17
;MyProject.c,275 :: 		for(i=0;i<8;i++)
	MOV        R16, R17
	SUBI       R16, 255
	MOV        R17, R16
;MyProject.c,286 :: 		}
; i end address is: 17 (R17)
	JMP        L_nlcd_SendByte7
L_nlcd_SendByte8:
;MyProject.c,288 :: 		CS_LCD_SET;
	IN         R16, PORTC+0
	ORI        R16, 64
	OUT        PORTC+0, R16
;MyProject.c,289 :: 		}
L_end_nlcd_SendByte:
	RET
; end of _nlcd_SendByte

_nlcd_Putc:

;MyProject.c,294 :: 		void nlcd_Putc(unsigned char c)
;MyProject.c,297 :: 		if (c>127) c=c-64;         // We transfer Cyrillic characters encoded at the beginning of the second CP1251
	PUSH       R3
	LDI        R16, 127
	CP         R16, R2
	BRLO       L__nlcd_Putc39
	JMP        L_nlcd_Putc14
L__nlcd_Putc39:
	MOV        R16, R2
	SUBI       R16, 64
	MOV        R2, R16
L_nlcd_Putc14:
;MyProject.c,300 :: 		for (i = 0; i < 5; i++ )
; i start address is: 20 (R20)
	LDI        R20, 0
; i end address is: 20 (R20)
L_nlcd_Putc15:
; i start address is: 20 (R20)
	CPI        R20, 5
	BRLO       L__nlcd_Putc40
	JMP        L_nlcd_Putc16
L__nlcd_Putc40:
;MyProject.c,302 :: 		nlcd_SendByte(DATA_LCD_MODE,pgm_read_byte(&(nlcd_Font[c-32][i])));
	MOV        R16, R2
	LDI        R17, 0
	SUBI       R16, 32
	SBCI       R17, 0
	PUSH       R20
	LDI        R20, 5
	LDI        R21, 0
	CALL       _HWMul_16x16+0
	POP        R20
	LDI        R18, #lo_addr(_nlcd_Font+0)
	LDI        R19, hi_addr(_nlcd_Font+0)
	ADD        R16, R18
	ADC        R17, R19
	MOV        R30, R20
	LDI        R31, 0
	ADD        R30, R16
	ADC        R31, R17
	LPM        R16, Z
	PUSH       R2
	MOV        R3, R16
	LDI        R27, 1
	MOV        R2, R27
	CALL       _nlcd_SendByte+0
	POP        R2
;MyProject.c,300 :: 		for (i = 0; i < 5; i++ )
	MOV        R16, R20
	SUBI       R16, 255
	MOV        R20, R16
;MyProject.c,303 :: 		}
; i end address is: 20 (R20)
	JMP        L_nlcd_Putc15
L_nlcd_Putc16:
;MyProject.c,305 :: 		nlcd_SendByte(DATA_LCD_MODE,0x00); // The gap between characters in the horizontal 1 pixel
	PUSH       R2
	CLR        R3
	LDI        R27, 1
	MOV        R2, R27
	CALL       _nlcd_SendByte+0
	POP        R2
;MyProject.c,306 :: 		}
L_end_nlcd_Putc:
	POP        R3
	RET
; end of _nlcd_Putc

_nlcd_PutcWide:

;MyProject.c,311 :: 		void nlcd_PutcWide(unsigned char c)
;MyProject.c,314 :: 		if (c>127) c=c-64;         // We transfer Cyrillic characters encoded at the beginning of the second CP1251
	PUSH       R3
	LDI        R16, 127
	CP         R16, R2
	BRLO       L__nlcd_PutcWide42
	JMP        L_nlcd_PutcWide18
L__nlcd_PutcWide42:
	MOV        R16, R2
	SUBI       R16, 64
	MOV        R2, R16
L_nlcd_PutcWide18:
;MyProject.c,317 :: 		for (i = 0; i < 5; i++ )
; i start address is: 20 (R20)
	LDI        R20, 0
; i end address is: 20 (R20)
L_nlcd_PutcWide19:
; i start address is: 20 (R20)
	CPI        R20, 5
	BRLO       L__nlcd_PutcWide43
	JMP        L_nlcd_PutcWide20
L__nlcd_PutcWide43:
;MyProject.c,320 :: 		glyph= pgm_read_byte(&(nlcd_Font[c-32][i]));
	MOV        R16, R2
	LDI        R17, 0
	SUBI       R16, 32
	SBCI       R17, 0
	PUSH       R20
	LDI        R20, 5
	LDI        R21, 0
	CALL       _HWMul_16x16+0
	POP        R20
	LDI        R18, #lo_addr(_nlcd_Font+0)
	LDI        R19, hi_addr(_nlcd_Font+0)
	ADD        R16, R18
	ADC        R17, R19
	MOV        R30, R20
	LDI        R31, 0
	ADD        R30, R16
	ADC        R31, R17
	LPM        R16, Z
; glyph start address is: 17 (R17)
	MOV        R17, R16
;MyProject.c,321 :: 		nlcd_SendByte(DATA_LCD_MODE,glyph);
	PUSH       R17
	PUSH       R2
	MOV        R3, R16
	LDI        R27, 1
	MOV        R2, R27
	CALL       _nlcd_SendByte+0
	POP        R2
	POP        R17
;MyProject.c,322 :: 		nlcd_SendByte(DATA_LCD_MODE,glyph);
	PUSH       R2
; glyph end address is: 17 (R17)
	MOV        R3, R17
	LDI        R27, 1
	MOV        R2, R27
	CALL       _nlcd_SendByte+0
	POP        R2
;MyProject.c,317 :: 		for (i = 0; i < 5; i++ )
	MOV        R16, R20
	SUBI       R16, 255
	MOV        R20, R16
;MyProject.c,323 :: 		}
; i end address is: 20 (R20)
	JMP        L_nlcd_PutcWide19
L_nlcd_PutcWide20:
;MyProject.c,325 :: 		nlcd_SendByte(DATA_LCD_MODE,0x00); // The gap between characters in the horizontal 1 pixel
	PUSH       R2
	CLR        R3
	LDI        R27, 1
	MOV        R2, R27
	CALL       _nlcd_SendByte+0
	POP        R2
;MyProject.c,327 :: 		}
L_end_nlcd_PutcWide:
	POP        R3
	RET
; end of _nlcd_PutcWide

_nlcd_Print:

;MyProject.c,333 :: 		void nlcd_Print(char * message)
;MyProject.c,335 :: 		while (*message) /// End of line marked zero
L_nlcd_Print22:
	MOVW       R30, R2
	LD         R16, Z
	TST        R16
	BRNE       L__nlcd_Print45
	JMP        L_nlcd_Print23
L__nlcd_Print45:
;MyProject.c,337 :: 		nlcd_Putc(*message++);
	MOVW       R30, R2
	LD         R16, Z
	PUSH       R3
	PUSH       R2
	MOV        R2, R16
	CALL       _nlcd_Putc+0
	POP        R2
	POP        R3
	MOVW       R16, R2
	SUBI       R16, 255
	SBCI       R17, 255
	MOVW       R2, R16
;MyProject.c,338 :: 		}
	JMP        L_nlcd_Print22
L_nlcd_Print23:
;MyProject.c,339 :: 		}
L_end_nlcd_Print:
	RET
; end of _nlcd_Print

_nlcd_PrintF:

;MyProject.c,345 :: 		void nlcd_PrintF(unsigned char * message)
;MyProject.c,354 :: 		}
L_nlcd_PrintF25:
;MyProject.c,355 :: 		}
L_end_nlcd_PrintF:
	RET
; end of _nlcd_PrintF

_nlcd_PrintWide:

;MyProject.c,362 :: 		void nlcd_PrintWide(unsigned char * message)
;MyProject.c,364 :: 		while (*message) nlcd_PutcWide(*message++);  // ????? ?????? ????????? ?????
L_nlcd_PrintWide26:
	MOVW       R30, R2
	LD         R16, Z
	TST        R16
	BRNE       L__nlcd_PrintWide48
	JMP        L_nlcd_PrintWide27
L__nlcd_PrintWide48:
	MOVW       R30, R2
	LD         R16, Z
	PUSH       R3
	PUSH       R2
	MOV        R2, R16
	CALL       _nlcd_PutcWide+0
	POP        R2
	POP        R3
	MOVW       R16, R2
	SUBI       R16, 255
	SBCI       R17, 255
	MOVW       R2, R16
	JMP        L_nlcd_PrintWide26
L_nlcd_PrintWide27:
;MyProject.c,365 :: 		}
L_end_nlcd_PrintWide:
	RET
; end of _nlcd_PrintWide

_nlcd_GotoXY:

;MyProject.c,372 :: 		void nlcd_GotoXY(char x,char y)
;MyProject.c,374 :: 		x=x*6;        // ????????? ?? ?????????? ? ???????? ? ??????????? ? ???????????
	PUSH       R2
	PUSH       R3
	LDI        R16, 6
	MUL        R2, R16
	MOV        R16, R0
	MOV        R2, R16
;MyProject.c,375 :: 		nlcd_SendByte(CMD_LCD_MODE,(0xB0|(y&0x0F)));      // ????????? ?????? ?? Y: 0100 yyyy
	MOV        R16, R3
	ANDI       R16, 15
	ORI        R16, 176
	PUSH       R2
	MOV        R3, R16
	CLR        R2
	CALL       _nlcd_SendByte+0
	POP        R2
;MyProject.c,376 :: 		nlcd_SendByte(CMD_LCD_MODE,(0x00|(x&0x0F)));      // ????????? ?????? ?? X: 0000 xxxx - ???? (x3 x2 x1 x0)
	MOV        R16, R2
	ANDI       R16, 15
	PUSH       R2
	MOV        R3, R16
	CLR        R2
	CALL       _nlcd_SendByte+0
	POP        R2
;MyProject.c,377 :: 		nlcd_SendByte(CMD_LCD_MODE,(0x10|((x>>4)&0x07))); // ????????? ?????? ?? X: 0010 0xxx - ???? (x6 x5 x4)
	MOV        R16, R2
	LSR        R16
	LSR        R16
	LSR        R16
	LSR        R16
	ANDI       R16, 7
	ORI        R16, 16
	MOV        R3, R16
	CLR        R2
	CALL       _nlcd_SendByte+0
;MyProject.c,379 :: 		}
L_end_nlcd_GotoXY:
	POP        R3
	POP        R2
	RET
; end of _nlcd_GotoXY

_nlcd_Inverse:

;MyProject.c,384 :: 		void nlcd_Inverse(unsigned char mode)
;MyProject.c,386 :: 		if (mode) nlcd_SendByte(CMD_LCD_MODE,0xA6);
	PUSH       R2
	PUSH       R3
	TST        R2
	BRNE       L__nlcd_Inverse51
	JMP        L_nlcd_Inverse28
L__nlcd_Inverse51:
	LDI        R27, 166
	MOV        R3, R27
	CLR        R2
	CALL       _nlcd_SendByte+0
	JMP        L_nlcd_Inverse29
L_nlcd_Inverse28:
;MyProject.c,387 :: 		else nlcd_SendByte(CMD_LCD_MODE,0xA7);
	LDI        R27, 167
	MOV        R3, R27
	CLR        R2
	CALL       _nlcd_SendByte+0
L_nlcd_Inverse29:
;MyProject.c,388 :: 		}
L_end_nlcd_Inverse:
	POP        R3
	POP        R2
	RET
; end of _nlcd_Inverse

_main:
	LDI        R27, 255
	OUT        SPL+0, R27
	LDI        R27, 0
	OUT        SPL+1, R27

;MyProject.c,390 :: 		int main (void){
;MyProject.c,391 :: 		nlcd_Init();
	PUSH       R2
	PUSH       R3
	CALL       _nlcd_Init+0
;MyProject.c,392 :: 		nlcd_Print("this is a test");
	LDI        R27, #lo_addr(?lstr1_MyProject+0)
	MOV        R2, R27
	LDI        R27, hi_addr(?lstr1_MyProject+0)
	MOV        R3, R27
	CALL       _nlcd_Print+0
;MyProject.c,393 :: 		nlcd_GotoXY(22,22);
	LDI        R27, 22
	MOV        R3, R27
	LDI        R27, 22
	MOV        R2, R27
	CALL       _nlcd_GotoXY+0
;MyProject.c,394 :: 		nlcd_Print("Www.Elasa.ir");
	LDI        R27, #lo_addr(?lstr2_MyProject+0)
	MOV        R2, R27
	LDI        R27, hi_addr(?lstr2_MyProject+0)
	MOV        R3, R27
	CALL       _nlcd_Print+0
;MyProject.c,396 :: 		nlcd_GotoXY(33,33);
	LDI        R27, 33
	MOV        R3, R27
	LDI        R27, 33
	MOV        R2, R27
	CALL       _nlcd_GotoXY+0
;MyProject.c,399 :: 		}
L_end_main:
	POP        R3
	POP        R2
L__main_end_loop:
	JMP        L__main_end_loop
; end of _main
