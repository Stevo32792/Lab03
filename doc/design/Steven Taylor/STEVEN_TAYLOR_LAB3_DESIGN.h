/*****************************************************************************/
/*******************************/
/*Library Operation Definitions*/
/*******************************/

/*! 
 * Defines library operation
 * When set to'1' allows for operation with a 4bit LCD
 *		when set to '0' library runs in 8bit mode
 */	
#define configUSE_4_BIT_MODE 0

/*! 
 * Enables text wrapping from first line to next line
 * 	when set to '1', any string that is longer than LCD
 *		display length, text will be continued on 
 *		the next line. When set to '0' string length error
 *		message will be displayed
 */	
#define configUSE_TEXT_WRAPPING 0
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
/************************/
/*Library Home Functions*/
/************************/

/*!****************************************************************************
 *
 * \fn vLCD_GO_TO_Position(uint8_t, uint8_t)
 *
 * \brief Function to directly control LCD cursor Position
 *
 * \details Function is called to move the LCD cursor to a specific location 
 *				on the LCD.
 *
 *			Allows for direct control of where data can be written, rather
 *				than only from the beginning of a line
 *			
 * \params[in] 	Character, Row 	
 *			
 * \returns nothing			
 *
 * Modification History:
 *
 * 11/15/2013 - Original Function
 *
 ******************************************************************************
 */
void vLCD_GO_TO_POSITION(uint8_t x, uint8_t y)
{
	//save the current position
	
	// For each line o the LCD
	switch(y)
	{
		case 0: 
			//for the top line, set the DDRAM address 
			//move a certain number of characters to the right
		break;
		
		case 1: 
			//for the bottom line, set the DDRAM address 
			//move a certain number of characters to the right
		break;
		
		default: 
			//default to the top left of the LCD if nothing is specified
	}
	
	// send a command to set the data address
	
}

/*!****************************************************************************
 *
 * \fn vLCD_HOME_TOP_LINE(void)
 *
 * \brief Function to return to home position on the top line of the LCD
 *
 * \details Function is called to return the cursor to the first position
 *				on the top line of the LCD.
 *			
 *			This allows for the the top line to be ready to write 
 *				independently from the bottom line.
 *			
 * \params[in] none		
 *			
 * \returns nothing			
 *
 * Modification History:
 *
 * 11/15/2013 - Original Function
 *
 ******************************************************************************
 */
void vLCD_HOME_TOP_LINE(void)
{
	//move cursor to the top left position of the LCD
}

/*!****************************************************************************
 *
 * \fn vLCD_HOME_BOTTOM_LINE(void)
 *
 * \brief Function to return to home position on the bottom line of the LCD
 *
 * \details Function is called to return the cursor to the first position
 *				on the bottom line of the LCD.
 *			
 *			This allows for the the bottom line to be ready to write 
 *				independently from the top line.
 *			
 * \params[in] none		
 *			
 * \returns nothing			
 *
 * Modification History:
 *
 * 11/15/2013 - Original Function
 *
 ******************************************************************************
 */
void vLCD_HOME_BOTTOM_LINE(void)
{
	//move the cursor to the bottom left position on the LCD
}

/*****************************************************************************/