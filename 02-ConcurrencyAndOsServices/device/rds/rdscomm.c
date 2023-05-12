/* rdscomm.c - rdscomm */

#include <xinu.h>

/*------------------------------------------------------------------------
 * rdscomm  -  send a request message to the remote disk server and
 *		 a reply, handling sequence numbers and retries
 *------------------------------------------------------------------------
 */
status	rdscomm (
	  struct rd_msg_hdr *msg,	/* Message to send		*/
	  int32		    mlen,	/* Message length		*/
	  struct rd_msg_hdr *reply,	/* Buffer for reply		*/
	  int32		    rlen,	/* Size of reply buffer		*/
	  struct rdscblk    *rdptr	/* Ptr to device control block	*/
	)
{
	kprintf("Timeout on exchange with remote disk server\n\r");
	return TIMEOUT;
}
