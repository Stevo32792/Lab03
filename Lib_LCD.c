/*!****************************************************************************
 *
 * \file Lib_LCD.c
 *
 * \brief File for FreeRTOS LCD implementation
 *
 * \author  
 *
 * \details Contains all functions for two line LCD operation in FreeRTOS
 *			
 *			
 *
 * Modification History:
 * 11/18/2013 - Pulled all Functions in
 * 11/16/2013 - Original File
 *
 ******************************************************************************
 */
 
 
 /* #includes go here */
 
 /*****************************************************************************/
/****************************/
/*Library LCD Initialization*/
/****************************/

/*!****************************************************************************
*
* \fn vLCD_INITIALIZATION(void)
*
* \brief Function to initialize the LDC 
*
* \details Function is called to initialize the LCD into either 
*		   4 bit or 8 bit mode with the following specifications:
*		   DB0 sets blink		  
*		   DB1 sets cursors
*		   DB2 sets display on 
*		   DB3 set to display 2 lines on the LCD
*
* \params[in] none
*
* \returns nothing
*
* Modification History:
*
* 11/17/2013 - Original Function
*
******************************************************************************
*/
void vLCD_INITIALIZATION(void)
{
	/*! Delay 30ms after powering up*/
	/*! Function set*/
	/*! Delay 50us*/
	/*! Set Display on*/
	/*! Delay 50us*/
	/*! Delay 1.53ms*/
	/*! Entry Mode set, increments, no shift*/
}

/*****************************************************************************/
/*************************************/
/*Library LCD Write and Write Command*/
/*************************************/

/*!****************************************************************************
*
* \fn vWRITE_COMMAND_TO_LCD(void)
*
* \brief Function to write commands to the LCD
*
* \details Function is write commands to the LCD using the read/write 
*		   commands and the register select 
*
* \params[in] RS, data
*
* \returns nothing
*
* Modification History:
*
* 11/17/2013 - Original Function
*
******************************************************************************
*/
void vWRITE_COMMAND_TO_LCD(uint8_t RS, uint8_t data)
{
	
}

/*!****************************************************************************
*
* \fn vLCD_WRITE_STRING(char *str_ptr)
*
* \brief Function to write strings to the LCD
*
* \details Function is used to take in a string of characters and display 
*		   the string to the LCD
*
* \params[in] *str_ptr
*
* \returns nothing
*
* Modification History:
*
* 11/17/2013 - Original Function
* 11/23/2013 - Addec Code
*
******************************************************************************
*/
void vLCD_WRITE_STRING(char *str_ptr)
{
	//MIGHT NOT WORK; not sure how the #define magic works
	LCP = LCD_RS;				//write data (RS pin 1; E pin 0; !write pin = 0)
	
	
	while(*str_ptr != '\0')		//move through the string until the end is reached
	{
		/*! If text wrap is enabled */
		#ifdef configTEXT_WRAP
			#if configTEXT_WRAP == 1
		
				/*! If the LCD is at the end of the top line */
				if( xLCD_Get_Length()== 24)
					vLCD_HOME_BOTTOM_LINE(); //Continue on to the bottom line
		
			#endif
		#endif
		LCP = LCP | LCD_E;	//set enable high
		PORTK = *str_ptr++;		//write character to LCD
<<<<<<< HEAD
		vTaskDelay(1);			//at least 30uS needed to display
		LCP = LCP & LCD_E;	//set enable low
		vTaskDelay(1);			//another 30uS delay needed
=======
		DDRK = 0x00;
		while(PORTK == LCD_7) //wait for the busy line
		{
		}
		DDRK = 0xFF;
		LCP = LCP & LCD_E;	//set enable low
		DDRK = 0x00;
		while(PORTK == LCD_7) //wait for the busy line
		{
		}
		DDRK = 0xFF;
>>>>>>> d98effdc46627401b01973e5e73afe5b7aaaa371
	}	
}

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
* 11/24/2013 - Added code to function
*
******************************************************************************
*/
void vLCD_CLEAR(void)
{
	/*! Call write command to send 0x01 command (clear) to the controller */
	vWRITE_COMMAND_TO_LCD(0, LCD_CLEAR_INSTRUCTION);
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
* 11/24/2013 - Added code to function
*
******************************************************************************
*/
void vLCD_CLEAR_TOP(void)
{
	/*! Call function to set cursor for top row's home position */
	vLCD_HOME_TOP_LINE();
	/*! Call function to write string of 24 spaces to clear the top row */
	vLCD_WRITE_STRING("                        ");
	/*! Call function to set cursor for top row's home position */
	vLCD_HOME_TOP_LINE();
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
* 11/24/2013 - Added code to function
*
******************************************************************************
*/
void vLCD_CLEAR_BOTTOM(void)
{
	/*! Call function to set cursor for bottom row's home position */
	vLCD_HOME_BOTTOM_LINE();
	/*! Call function to write string of 24 spaces to clear the bottom row */
	vLCD_WRITE_STRING("                        ");
	/*! Call function to set cursor for bottom row's home position */
	vLCD_HOME_BOTTOM_LINE();
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
* 11/24/2013 - Added code to function
*
******************************************************************************
*/
void vLCD_ON_OFF(void)
{
	uint8_t LCD_Command = 0x00;
	
	/*! Check on/off status of LCD */
	switch (OnOffStatus)
	{
		case 0:
			/*! Set command to turn LCD on */
			LCD_Command = LCD_ON_INSTRUCTION;
		break;
		
		case 1:
			/*! Set command to turn LCD off */
			LCD_Command = LCD_OFF_INSTRUCTION;
		break;
	}
	
	/*! Check cursor show configuration */
	if (configCURSOR_SHOW)
	{
		/*! Set command to show cursor if enabled */
		LCD_Command += CURSOR_SHOW_INSTRUCTION;
	}
	
	/*! Check cursor blink configuration */
	if (configCURSOR_BLINK)
	{
		/*! Set command to blink cursor if enabled */
		LCD_Command += CURSOR_BLINK_INSTRUCTION;
	}
	
	/*! Toggle LCD */
	vWRITE_COMMAND_TO_LCD(0, LCD_Command);
}
/*****************************************************************************/

/*****************************************************************************/
/***************************/
/*Library Length Functions*/
/*************************/

/*!****************************************************************************
 *
 * \fn xGet_Top_Length(void)
 *
 * \brief Function to get the remaining characters on the LCD
 *
 * \details Function is called to calculate the amount of characters
 *			remaining on the LCD.
 *
 *			This allows for tracking the amount of line space available.
 *			
 * \params[in] 	nothing
 *			
 * \returns Number of characters remaining			
 *
 * Modification History:
 *
 * 11/17/2013 - Original Function
 * 11/23/2013 - Added Code
 *
 ******************************************************************************
 */
void xLCD_Get_Length(void)
{
	switch(CURSOR_Y_POSITION)
	{
		/*! If the cursor is on the top line */
		case 0:
			/*!give total available characters(top and bottom line)*/
			return 48 - CURSOR_X_POSITION; 
			break;
			
		/*! If the cursor is on the bottom line */
		case 1:
			/*! Give remaining characters available. */
			return 24 - CURSOR_X_POSITION; 
	}
}

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
 *			Saves current cursor position for text wrapping
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
	register uint8_t DDRAMAddr;
	
	// For each line o the LCD
	switch(y)
	{
		case 0: 
			//for the top line, set the DDRAM address 
			//move a certain number of characters to the right
			DDRAMAddr = LCD_LINE0_DDRAMADDR + x;
		break;
		
		case 1: 
			//for the bottom line, set the DDRAM address 
			//move a certain number of characters to the right
			DDRAMAddr = LCD_LINE1_DDRAMADDR + x;
		break;
		
		default: 
			//default to the top left of the LCD if nothing is specified
			DDRAMAddr = LCD_LINE0_DDRAMADDR+x;
	}
	
	//save current cursor position X
	CURSOR_X_POSITION = x;
	//save current cursor position Y
	CURSOR_Y_POSITION = y;
	
	// send a command to set the data address
	LCDsendCommand(1<<LCD_DDRAM | DDRAMAddr);
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
	LCDsendCommand(1 << LCD_HOME);
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
	vLCD_GO_TO_POSITION(0,1);
}

/*****************************************************************************/
 
 
