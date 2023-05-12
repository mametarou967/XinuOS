/* conf.c (GENERATED FILE; DO NOT EDIT) */

#include <xinu.h>


extern	devcall	ioerr(void);
extern	devcall	ionull(void);

/* Device independent I/O switch */

struct	dentry	devtab[NDEVS] =
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
	  (void *)ttyinit, (void *)ionull, (void *)ionull,
	  (void *)ttyread, (void *)ttywrite, (void *)ioerr,
	  (void *)ttygetc, (void *)ttyputc, (void *)ttycontrol,
	  (void *)0x44e09000, (void *)ttyhandler, 72 },

/* NULLDEV is null */
	{ 1, 0, "NULLDEV",
	  (void *)ionull, (void *)ionull, (void *)ionull,
	  (void *)ionull, (void *)ionull, (void *)ioerr,
	  (void *)ionull, (void *)ionull, (void *)ioerr,
	  (void *)0x0, (void *)ioerr, 0 },

/* NAMESPACE is nam */
	{ 2, 0, "NAMESPACE",
	  (void *)naminit, (void *)namopen, (void *)ioerr,
	  (void *)ioerr, (void *)ioerr, (void *)ioerr,
	  (void *)ioerr, (void *)ioerr, (void *)ioerr,
	  (void *)0x0, (void *)ioerr, 0 },

/* RAM0 is ram */
	{ 3, 0, "RAM0",
	  (void *)raminit, (void *)ramopen, (void *)ramclose,
	  (void *)ramread, (void *)ramwrite, (void *)ioerr,
	  (void *)ioerr, (void *)ioerr, (void *)ioerr,
	  (void *)0x0, (void *)ionull, 0 },

/* GPIO0 is gpio */
	{ 4, 0, "GPIO0",
	  (void *)gpioinit, (void *)ionull, (void *)ionull,
	  (void *)gpioread, (void *)gpiowrite, (void *)ioerr,
	  (void *)ionull, (void *)ionull, (void *)gpiocontrol,
	  (void *)0x44e07000, (void *)gpiohandler, 96 },

/* GPIO1 is gpio */
	{ 5, 1, "GPIO1",
	  (void *)gpioinit, (void *)ionull, (void *)ionull,
	  (void *)gpioread, (void *)gpiowrite, (void *)ioerr,
	  (void *)ionull, (void *)ionull, (void *)gpiocontrol,
	  (void *)0x4804c000, (void *)gpiohandler, 98 },

/* GPIO2 is gpio */
	{ 6, 2, "GPIO2",
	  (void *)gpioinit, (void *)ionull, (void *)ionull,
	  (void *)gpioread, (void *)gpiowrite, (void *)ioerr,
	  (void *)ionull, (void *)ionull, (void *)gpiocontrol,
	  (void *)0x481ac000, (void *)gpiohandler, 32 },

/* GPIO3 is gpio */
	{ 7, 3, "GPIO3",
	  (void *)gpioinit, (void *)ionull, (void *)ionull,
	  (void *)gpioread, (void *)gpiowrite, (void *)ioerr,
	  (void *)ionull, (void *)ionull, (void *)gpiocontrol,
	  (void *)0x481ae000, (void *)gpiohandler, 62 }
};
