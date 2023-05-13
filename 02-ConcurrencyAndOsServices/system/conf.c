/* conf.c (GENERATED FILE; DO NOT EDIT) */

#include <xinu.h>


// extern	devcall	ioerr(void);
// extern	devcall	ionull(void);

/* Device independent I/O switch */

struct	dentry	devtab[1] =
{
/**
 * Format of entries is:
 * dev-number, minor-number, dev-name,
 * init, open, close,
 * read, write, seek,
 * getc, putc, control,
 * dev-csr-address, intr-handler, irq
 */

/* CONSOLE is tty */
	{ 0, 0, "CONSOLE",
	  (void *)ttyinit, (void *)NULL, (void *)NULL,
	  (void *)ttyread, (void *)ttywrite, (void *)NULL,
	  (void *)ttygetc, (void *)ttyputc, (void *)ttycontrol,
	  (void *)0x44e09000, (void *)ttyhandler, 72 }
};
