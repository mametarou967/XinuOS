/* rfscomm.c - rfscomm */

#include <xinu.h>

/*------------------------------------------------------------------------
 * rfscomm  -  Handle communication with RFS server (send request and
 *		receive a reply, including sequencing and retries)
 *------------------------------------------------------------------------
 */
int32	rfscomm (
	 struct	rf_msg_hdr *msg,	/* Message to send		*/
	 int32	mlen,			/* Message length		*/
	 struct	rf_msg_hdr *reply,	/* Buffer for reply		*/
	 int32	rlen			/* Size of reply buffer		*/
	)
{
	return SYSERR;
}
