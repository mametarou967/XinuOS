/* tty.h */

/* Size constants */

#ifndef	TY_OBUFLEN
#define	TY_OBUFLEN	64		/* Num.	chars in output	queue	*/
#endif

/* Mode constants for input and output modes */

struct	ttycblk	{			/* Tty line control block	*/

	char	*tyohead;		/* Next output char to xmit	*/
	char	*tyotail;		/* Next slot for outgoing char	*/
	char	tyobuff[TY_OBUFLEN];	/* Output buffer		*/
	bool8	tyocrlf;		/* Output CR/LF for LF ?	*/
};
extern	struct	ttycblk	ttytab;

/* Characters with meaning to the tty driver */

#define	TY_NEWLINE	'\n'		/* Newline == line feed		*/
#define	TY_RETURN	'\r'		/* Carriage return character	*/

/* Tty control function codes */
