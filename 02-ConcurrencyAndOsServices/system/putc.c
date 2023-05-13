/* putc.c - putc */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  putc  -  Send one character of data (byte) to a device
 *------------------------------------------------------------------------
 */
syscall	putc(
	  char		ch		/* Character to send		*/
	)
{
	int32		retval;		/* Value to return to caller	*/

	retval = ttyputc(ch);
	return retval;
}
