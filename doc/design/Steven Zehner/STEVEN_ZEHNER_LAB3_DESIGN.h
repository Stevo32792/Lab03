/*****************************************************************************/
/*********************************/
/*Library Instruction Definitions*/
/*********************************/

/*! Instructions for clearing LCD */
#define LCD_CLEAR_INSTRUCTION 	0x01

/*! Instructions for setting LCD on and off */
#define LCD_OFF_INSTRUCTION 	0x0C
#define LCD_ON_INSTRUCTION		0x08

/*! Defines the cursor settings for the LCD */
#define configCURSOR_SHOW		1
#define configCURSOR_BLINK		1

/*****************************************************************************/



/*****************************************************************************/
/*************************************/
/*Library Clear Function Variables*/
/***********************************/

/*! Variable to track the on/off status of the LCD 0-off 1-on*/
uint8_t OnOffStatus;

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



/*****************************************************************************/
/*************************/
/*Library Clear Functions*/
/*************************/

/*!****************************************************************************
*
* \fn vLCD_CLEAR(void)
*
* \brief Function to clear the LCD Display
*
* \details Function is called to clear all data displayed on the LCD. Also
*		   returns the cursor to the home location on the top row. The command
*		   used to clear the display takes 1.53ms to run. Proper time needs
*		   allocated to ensure no commands are sent to the display for that time
*	
* \params[in] nothing
*	
* \returns nothing	
*
* Modification History:
*
* 11/17/2013 - Original Function
*
******************************************************************************
*/
void vLCD_CLEAR(void)
{
	/*! Call write command to send 0x01 command (clear) to the controller */
	/*! Delay 1.53 ms to allow for clear command to run */
}

/*!****************************************************************************
*
* \fn vLCD_CLEAR_TOP(void)
*
* \brief Function to clear the top line of the LCD Display
*
* \details Calls the function to set the cursor to the home position of the top
*		   row, write 24 spaces as a string, then return to the home position
*		   of the top row.
*	
* \params[in] nothing
*	
* \returns nothing	
*
* Modification History:
*
* 11/17/2013 - Original Function
*
******************************************************************************
*/
void vLCD_CLEAR_TOP(void)
{
	/*! Call function to set cursor for top row's home position */
	/*! Call function to write string of 24 spaces to clear the top row */
	/*! Call function to set cursor for top row's home position */
}

/*!****************************************************************************
*
* \fn vLCD_CLEAR_BOTTOM(void)
*
* \brief Function to clear the bottom line of the LCD Display
*
* \details Calls the function to set the cursor to the home position of the
*		   bottom row, write 24 spaces as a string, then return to the home 
*		   position of the bottom row.
*	
* \params[in] nothing
*	
* \returns nothing	
*
* Modification History:
*
* 11/17/2013 - Original Function
*
******************************************************************************
*/
void vLCD_CLEAR_BOTTOM(void)
{
	/*! Call function to set cursor for bottom row's home position */
	/*! Call function to write string of 24 spaces to clear the bottom row */
	/*! Call function to set cursor for bottom row's home position */
}

/*!****************************************************************************
*
* \fn vLCD_ON_OFF(void)
*
* \brief Function to toggle LCD on and off
*
* \details Checks the current status of the LCD. If the LCD is on, toggle it
*		   so it's off. If the LCD is off, turn it on. Uses the vLCD_WRITE
*		   command to send instructions to the LCD.
*	
* \params[in] nothing
*	
* \returns nothing	
*
* Modification History:
*
* 11/18/2013 - Original Function
*
******************************************************************************
*/
void vLCD_CLEAR_BOTTOM(void)
{
	/*! If statements to check status of LCD */
	/*! Toggle LCD */
}
/*****************************************************************************/