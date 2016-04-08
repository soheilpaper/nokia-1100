//-----------------------------------------------------------------------------
// Copyright:      RAD Electronic Co. LTD,
// Author:         Sh. Nourbakhsh Rad
// Remarks:        
// known Problems: none
// Version:        1.0.0
// Description:    Sh. Nourbakhs Rad, useful definitions!!! ...........
//								 
//-----------------------------------------------------------------------------

#ifndef _SHN_UTILS_H_
	#define _SHN_UTILS_H_


	static const unsigned char	 									BitMASKn[8] = {
																										0b00000001, 				//1
																										0b00000010, 				//2
																										0b00000100, 				//3
																										0b00001000, 				//4
																										0b00010000, 				//5
																										0b00100000, 				//6
																										0b01000000, 				//7
																										0b10000000	 				//8
																										};
                                    			
	static const unsigned char	 									BitMASKb[8] = {
																										0b11111110, 				//1
																										0b11111101, 				//2
																										0b11111011, 				//3
																										0b11110111, 				//4
																										0b11101111, 				//5
																										0b11011111, 				//6
																										0b10111111, 				//7
																										0b01111111	 				//8
																										};

	//----------------------------------------------------------------
	static const unsigned char	 									ByteMASKn[9] = {
																										0b00000000, 				//0
																										0b00000001, 				//1
																										0b00000011, 				//2
																										0b00000111, 				//3
																										0b00001111, 				//4
																										0b00011111, 				//5
																										0b00111111, 				//6
																										0b01111111, 				//7
																										0b11111111	 				//8
																										};

	static const unsigned char	 									ByteMASKb[9] = {
																										0b11111111, 				//0
																										0b11111110, 				//1
																										0b11111100, 				//2
																										0b11111000, 				//3
																										0b11110000, 				//4
																										0b11100000, 				//5
																										0b11000000, 				//6
																										0b10000000, 				//7
																										0b00000000	 				//8
																										};
	//----------------------------------------------------------------
	#define BVn(pin) 		           	                  BitMASKn[pin]
	#define BVb(pin) 		           	                  BitMASKb[pin]

	#define SetBit(port, pin)      	                  (port |= BitMASKn[pin])
	#define ClrBit(port, pin)  		                    (port &= BitMASKb[pin])
	#define InvBit(port, pin)  		                    (port ^= BitMASKn[pin])

	#define OutByte(port, data)												(port = data)
	#define InByte(port)															(port)

	#define BitIsSet(port, pin)		        						(port & BitMASKn[pin])
	#define Loop_BitIsSet(port, pin)    					  	{while(!BitIsSet(port, pin));}

	#define byteMASKn(byt, msk)												(byt &= ByteMASKn[msk])
	#define byteMASKb(byt, msk)												(byt &= ByteMASKb[msk])
	
	//----------------------------------------------------------------
  #define _rol(x) 																	((x & 0x80) ? ((x << 1) | 0x01) : (x << 1))
  #define _ror(x)																		((x & 0x01) ? ((x >> 1) | 0x80) : (x >> 1))

	//----------------------------------------------------------------
	#define True																			1
	#define False																			0
	
	#define ON																				1
	#define OFF																				0
	
	#define HIGH																			1
	#define LOW																				0
	
#endif	//_SHN_UTILS_H_
