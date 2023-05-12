/* rdsopen.c - rdsopen */

#include <xinu.h>

/*------------------------------------------------------------------------
 * rdsopen  -  Open a remote disk device and specify an ID to use
 *------------------------------------------------------------------------
 */

devcall	rdsopen (
	 struct	dentry	*devptr,	/* Entry in device switch table	*/
	 char	*diskid,		/* Disk ID to use		*/
	 char	*mode			/* Unused for a remote disk	*/
	)
{
	return SYSERR;
}
