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
/*Library Length Function Prototypes*/
/***********************************/

/*! Function to track length of the top line of the LCD */
void xGet_Top_Length(void);
/*! Function to track length of the bottom line of the LCD */
void xGet_Bottom_Length(void);
/*! Function to get the length of a string passed into it*/
uint8_t xGet_String_Length(string check);

/*****************************************************************************/



/*****************************************************************************/
/***************************/
/*Library Length Functions*/
/*************************/

/*!****************************************************************************
 *
 * \fn xGet_Top_Length(void)
 *
 * \brief Function to get the amount of space used on the top line
 *
 * \details Function is called to calculate the amount of characters used
 *			on the top line of the LCD.
 *
 *			This allows for tracking the amount of line space available.
 *			
 * \params[in] 	nothing
 *			
 * \returns nothing			
 *
 * Modification History:
 *
 * 11/17/2013 - Original Function
 *
 ******************************************************************************
 */
void xGet_Top_Length(void)
{
	//find current cursor position on the top line
	//stores that value into a Length variable
}

/*!****************************************************************************
 *
 * \fn xGet_Bottom_Length(void)
 *
 * \brief Function to get the space available on the bottom line of the LCD.
 *
 * \details Function is called to calculate the amount of characters used
 *			on the top line of the LCD.
 *
 *			This allows for tracking the amount of line space available
 *			
 * \params[in] 	nothing
 *			
 * \returns nothing
 *
 * Modification History:
 *
 * 11/17/2013 - Original Function
 *
 ******************************************************************************
 */
void xGet_Bottom_Length(void)
{
	//find current cursor position on the bottom line
	//stores that value into a Length variable
}

/*!****************************************************************************
 *
 * \fn xGet_String_Length(void)
 *
 * \brief Function to get the length of a string
 *
 * \details Function is called to calculate the amount of characters in a string and return the value.
 *		
 *			This allows for checking string length with available line space before printing.
 *			
 * \params[in] string check - number to find the length of
 *			
 * \returns length			
 *
 * Modification History:
 *
 * 11/15/2013 - Original Function
 *
 ******************************************************************************
 */
uint8_t xGet_String_Length(check)
{
	//calculate length of string
	//return value
}

/*****************************************************************************/