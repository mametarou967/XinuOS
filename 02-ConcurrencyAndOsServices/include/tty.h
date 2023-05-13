/* tty.h */

#define	TY_OBMINSP	20		/* Min space in buffer before	*/
					/*   processes awakened to write*/
#define	TY_EBUFLEN	20		/* Size of echo queue		*/

/* Size constants */

#ifndef	Ntty
#define	Ntty		1		/* Number of serial tty lines	*/
#endif
#ifndef	TY_IBUFLEN
#define	TY_IBUFLEN	128		/* Num. chars in input queue	*/
#endif
#ifndef	TY_OBUFLEN
#define	TY_OBUFLEN	64		/* Num.	chars in output	queue	*/
#endif

/* Mode constants for input and output modes */

#define	TY_IMRAW	'R'		/* Raw input mode => no edits	*/
#define	TY_IMCOOKED	'C'		/* Cooked mode => line editing	*/
#define	TY_IMCBREAK	'K'		/* Honor echo, etc, no line edit*/
#define	TY_OMRAW	'R'		/* Raw output mode => no edits	*/

struct	ttycblk	{			/* Tty line control block	*/

	char	*tyohead;		/* Next output char to xmit	*/
	char	*tyotail;		/* Next slot for outgoing char	*/
	char	tyobuff[TY_OBUFLEN];	/* Output buffer		*/
	bool8	tyocrlf;		/* Output CR/LF for LF ?	*/
};
extern	struct	ttycblk	ttytab;

/* Characters with meaning to the tty driver */

#define	TY_BACKSP	'\b'		/* Backspace character		*/
#define	TY_BACKSP2	'\177'		/* Alternate backspace char.	*/
#define	TY_BELL		'\07'		/* Character for audible beep	*/
#define	TY_EOFCH	'\04'		/* Control-D is EOF on input	*/
#define	TY_BLANK	' '		/* Blank			*/
#define	TY_NEWLINE	'\n'		/* Newline == line feed		*/
#define	TY_RETURN	'\r'		/* Carriage return character	*/
#define	TY_STOPCH	'\023'		/* Control-S stops output	*/
#define	TY_STRTCH	'\021'		/* Control-Q restarts output	*/
#define	TY_KILLCH	'\025'		/* Control-U is line kill	*/
#define	TY_UPARROW	'^'		/* Used for control chars (^X)	*/
#define	TY_FULLCH	TY_BELL		/* Char to echo when buffer full*/

/* Tty control function codes */

#define	TC_NEXTC	3		/* Look ahead 1 character	*/
#define	TC_MODER	4		/* Set input mode to raw	*/
#define	TC_MODEC	5		/* Set input mode to cooked	*/
#define	TC_MODEK	6		/* Set input mode to cbreak	*/
#define	TC_ICHARS	8		/* Return number of input chars	*/
#define	TC_ECHO		9		/* Turn on echo			*/
#define	TC_NOECHO	10		/* Turn off echo		*/
