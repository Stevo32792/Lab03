/*!****************************************************************************
 *
 * \file Lib_LCD.h
 *
 * \brief Header file for FreeRTOS LCD implementation 
 *
 * \author  
 *
 * \details Contains all definitions and function prototypes for LCD 
 *			operation within FreeRTOS			
 *			
 *
 * Modification History:
 * 11/18/2013 - Pulled all definitions and prototypes in
 * 11/16/2013 - Original File
 *
 ******************************************************************************
 */
 
#ifndef Lib_LCD_H
#define Lib_LCD_H
 
 /* #includes go here */
 
/*****************************************************************************/
/*************************************/
/*Library Length Function Variables*/
/***********************************/

/*! Variable to track the characters used on the bottom line of the LCD*/
uint8_t BottomLength;
/*! Variable to track the characters used on the top line of the LCD*/
uint8_t Top_Length;

/*****************************************************************************/

/*****************************************************************************/
/*************************************/
/*Library Clear Function Variables*/
/***********************************/

/*! Variable to track the on/off status of the LCD 0-off 1-on*/
uint8_t OnOffStatus;

/*****************************************************************************/
 
/*****************************************************************************/
/**************************/
/*Library Port Definitions*/
/**************************/

/*! 
 *	These definitions allow for specific port pins on the LCD to be written
 *	or read independently from each other.
 *	
 *	This allows for commands to be send and for easier direct control 
 *		of the LCD	
 */

/*! define MCU pin connected to LCD RS */
#define LCD_RS	0 	
/*! define MCU pin connected to LCD R/W */
#define LCD_RW	1 	
/*! define MCU pin connected to LCD E */
#define LCD_E	2
/*! define MCU pin connected to LCD D0 */	
#define LCD_D0	0	
/*! define MCU pin connected to LCD D1 */
#define LCD_D1	1	
/*! define MCU pin connected to LCD D2 */
#define LCD_D2	2	
/*! define MCU pin connected to LCD D3 */
#define LCD_D3	3	
/*! define MCU pin connected to LCD D4 */
#define LCD_D4	4
/*! define MCU pin connected to LCD D5 */	
#define LCD_D5	5	
/*! define MCU pin connected to LCD D6 */
#define LCD_D6	6	
/*! define MCU pin connected to LCD D7 */
#define LCD_D7	7	
/*! define MCU port connected to LCD data pins */
#define LDP PORTK	
/*! define MCU port connected to LCD control pins */
#define LCP PORTK	
/*! define MCU register for port connected to LCD data pins */
#define LDDR DDRK	
/*! define MCU register for port connected to LCD control pins */
#define LCDR DDRCK	

/*****************************************************************************/

/*****************************************************************************/
/*********************************/
/*Library Instruction Definitions*/
/*********************************/

/*! 
 *	These definitions allow for specific commands to be written to the LCD
 *	 
 *	Using the port definitions these commands can be run at any time, and
 *		independently from each other.
 */

/*! DB0: clear display */
#define LCD_CLR             0
/*! return to top home position	*/
#define LCD_HOME_TOP_LINE      1	
/*! return to top home position	*/
#define LCD_HOME_BOTTOM_LINE   2
/*! DB6: set CG RAM address */
#define LCD_CGRAM              6	
/*! DB7: set DD RAM address */
#define LCD_DDRAM              7	

// reading:
	/*! DB7: LCD is busy */
	#define LCD_BUSY            7	
	/*! visible lines */
	#define LCD_LINES			2	
	/*! line length (in characters) */
	#define LCD_LINE_LENGTH		24	

// cursor position to DDRAM mapping
#define LCD_LINE0_DDRAMADDR		0x00
#define LCD_LINE1_DDRAMADDR		0x40

/*! Instructions for clearing LCD */
#define LCD_CLEAR_INSTRUCTION 	0x01

/*! Instructions for setting LCD on and off */
#define LCD_OFF_INSTRUCTION 	0x0C
#define LCD_ON_INSTRUCTION		0x08

/*! Defines the cursor settings for the LCD */
#define configCURSOR_SHOW		1
#define configCURSOR_BLINK		1
/*! Text writing settings for the LCD */
#define configTEXT_WRAP			1

/*****************************************************************************/

/*****************************************************************************/
/****************************************/
/*Library Initialize Function Prototypes*/
/****************************************/

/*! Function to Initialize an LCD Display */
void vLCD_INITIALIZATION(void);
/*! Function to Write commands to an LCD */
void vWRITE_COMMAND_TO_LCD(uint8_t RS, uint8_t data);
/*! Functions to write strings to an LCD */
void vLCD_WRITE_STRING(char *str_ptr);

/*****************************************************************************/
 
/*****************************************************************************/
/**********************************/
/*Library Home Function Prototypes*/
/**********************************/

/*! Function To go directly to a set of X,Y coordinates on the LCD */
void vLCD_GO_TO_Position(uint8_t, uint8_t);
/*! Function to go to home position on the top line of the LCD*/
void vLCD_HOME_TOP_LINE(void);
/*! Function to go to home position on the top line of the LCD*/
void vLCD_HOME_BOTTOM_LINE(void);

/*****************************************************************************/

/*****************************************************************************/
/*************************************/
/*Library Length Function Prototypes*/
/***********************************/

/*! Function to track remaining characters on the LCD */
uint8_t xLCD_Get_Length()

/*****************************************************************************/

/*****************************************************************************/
/***********************************/
/*Library Clear Function Prototypes*/
/***********************************/

/*! Function to clear the entire display */
void vLCD_CLEAR(void);
/*! Function to clear the top row of the display */
void vLCD_CLEAR_TOP(void);
/*! Function to clear the bottom row of the display */
void vLCD_CLEAR_BOTTOM(void);
/*! Toggles LCD Display on and off */
void vLCD_ON_OFF(void);

/*****************************************************************************/
 
 #endif 
