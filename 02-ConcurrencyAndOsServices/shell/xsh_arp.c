/* xsh_arp.c - xsh_arp */

#include <xinu.h>
#include <stdio.h>
#include <string.h>

static	void	arp_dmp();
/*------------------------------------------------------------------------
 * xsh_arp - display the current ARP cache for an interface
 *------------------------------------------------------------------------
 */
shellcmd xsh_arp(int nargs, char *args[])
{
	/* For argument '--help', emit help about the 'arp' command	*/

	if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) {
		printf("Use: %s\n\n", args[0]);
		printf("Description:\n");
		printf("\tDisplays information from the ARP cache\n");
		printf("Options:\n");
		printf("\t--help\t display this help and exit\n");
		return 0;
	}

	/* Dump the Entire ARP cache */
	printf("\n");
	arp_dmp();

	return 0;
}


/*------------------------------------------------------------------------
 * arp_dmp - dump the ARP cache
 *------------------------------------------------------------------------
 */
static	void arp_dmp ()
{
	return;
}
