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
* \fn vLCD_WRITE_STRING(void)
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
*
******************************************************************************
*/
void vLCD_WRITE_STRING(char *str_ptr)
{
	
}

/*****************************************************************************/