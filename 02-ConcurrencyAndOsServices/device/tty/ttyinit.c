/* ttyinit.c - ttyinit */

#include <xinu.h>

struct	ttycblk	ttytab;

/*------------------------------------------------------------------------
 *  ttyinit  -  Initialize buffers and modes for a tty line
 *------------------------------------------------------------------------
 */
devcall	ttyinit(
	)
{
	struct	ttycblk	*typtr;		/* Pointer to ttytab entry	*/
	struct	uart_csreg *uptr;	/* Address of UART's CSRs	*/

	typtr = &ttytab;

	/* Initialize values in the tty control block */

	typtr->tyohead = typtr->tyotail = 	/* Set up output queue	*/
		&typtr->tyobuff[0];		/*    as empty		*/
	typtr->tyocrlf = TRUE;			/* Send CRLF for NEWLINE*/

	/* Initialize the UART */

	uptr = (struct uart_csreg *)0x44e09000;

	/* Set baud rate */
	uptr->lcr = UART_LCR_DLAB;
	uptr->dlm = UART_DLM;
	uptr->dll = UART_DLL;

	uptr->lcr = UART_LCR_8N1;	/* 8 bit char, No Parity, 1 Stop*/
	uptr->fcr = 0x00;		/* Disable FIFO for now		*/

	/* Register the interrupt dispatcher for the tty device */

	// set_evec( devptr->dvirq, (uint32)devptr->dvintr );

	/* Enable interrupts on the device: reset the transmit and	*/
	/*   receive FIFOS, and set the interrupt trigger level		*/

	uptr->fcr = UART_FCR_EFIFO | UART_FCR_RRESET |
			UART_FCR_TRESET | UART_FCR_TRIG2;

	/* UART must be in 16x mode (TI AM335X specific) */

	uptr->mdr1 = UART_MDR1_16X;

	/* Start the device */

	ttykickout(uptr);
	return OK;
}
