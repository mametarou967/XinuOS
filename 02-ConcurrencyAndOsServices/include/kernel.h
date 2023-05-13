/* kernel.h */

/* General type declarations used throughout the kernel */

typedef	unsigned char	byte;
typedef	unsigned char	uint8;
typedef	int		int32;
typedef	short		int16;
typedef	unsigned int	uint32;
typedef	unsigned short	uint16;
typedef	unsigned long long uint64;

/* Xinu-specific types */

typedef	int16	qid16;		/* queue ID				*/
typedef	int32	did32;		/* device ID				*/
typedef	byte	bool8;		/* Boolean type				*/

/* Function declaration return types */

typedef int32	syscall;	/* system call declaration		*/
typedef int32	devcall;	/* device call declaration		*/

#define local	static		/* Local procedure or variable declar.	*/

/* Boolean constants */

#define FALSE	0		/* Boolean False			*/
#define TRUE	1		/* Boolean True				*/

/* Null pointer, character, and string definintions */

#define NULL	0		/* null pointer for linked lists	*/
#define NULLCH	'\0'		/* null character			*/
#define	NULLSTR	""		/* null string				*/

/* Universal return constants */

#define OK	( 1)		/* normal system call return		*/
#define	SYSERR	(-1)		/* system call failed			*/
#define	EOF	(-2)		/* End-of-file (usually from read)	*/
#define	TIMEOUT	(-3)		/* system call timed out		*/




/* Prototypes of I/O functions used throughout the kernel */

syscall	kprintf(char *fmt, ...);
syscall	kputc(byte);
