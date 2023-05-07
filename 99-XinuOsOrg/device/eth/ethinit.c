/* ethinit.c - ethinit, eth_phy_read, eth_phy_write */

#include <xinu.h>

struct	eth_a_csreg eth_a_regs;

struct	ethcblk ethertab[1];

/*-----------------------------------------------------------------------
 * eth_phy_read - read a PHY register
 *-----------------------------------------------------------------------
 */
int32	eth_phy_read (
		volatile struct	eth_a_mdio *mdio,/* MDIO CSR pointer	*/
		byte	regadr,	/* PHY Register number	*/
		byte	phyadr,	/* PHY address		*/
		uint32	*value	/* Pointer to value 	*/
	)
{

	/* Ethernet PHY has only 32 registers */

	if(regadr > 31) {
		return SYSERR;
	}

	/* Only 32 possible PHY addresses */

	if(phyadr > 31) {
		return SYSERR;
	}

	/* Wait for the previous access to complete */

	while( (mdio->useraccess0 & ETH_AM335X_MDIOUA_GO) != 0 );

	/* Start the access */

	mdio->useraccess0 = (ETH_AM335X_MDIOUA_GO) |
			    (regadr << 21) |
			    (phyadr << 16);

	/* Wait until the access is complete */

	while( (mdio->useraccess0 & ETH_AM335X_MDIOUA_GO) != 0 );

	/* Check if the access was successful */

	if( (mdio->useraccess0 & ETH_AM335X_MDIOUA_ACK) == 0 ) {
		return SYSERR;
	}

	/* Copy the value read */

	(*value) = mdio->useraccess0 & ETH_AM335X_MDIOUA_DM;

	return OK;
}

/*-----------------------------------------------------------------------
 * eth_phy_write - write a PHY register
 *-----------------------------------------------------------------------
 */
int32	eth_phy_write (
		volatile struct	eth_a_mdio *mdio, /* MDIO CSR pointer	*/
		byte	regadr,	/* PHY register number	*/
		byte	phyadr,	/* PHY address		*/
		uint32	value	/* Value to be written	*/
	)
{

	/* There are only 32 PHY registers */

	if(regadr > 31) {
		return SYSERR;
	}

	/* There are only 32 possible PHY addresses */

	if(phyadr > 31) {
		return SYSERR;
	}

	/* Wait for the previous access to complete */

	while( (mdio->useraccess0 & ETH_AM335X_MDIOUA_GO) != 0);

	/* Start the access */

	mdio->useraccess0 = ETH_AM335X_MDIOUA_GO |
			    ETH_AM335X_MDIOUA_WR |
			    (regadr << 21) |
			    (phyadr << 16) |
			    (value & 0xffff);

	/* Wait for the access to complete */

	while( (mdio->useraccess0 & ETH_AM335X_MDIOUA_GO) != 0);

	return OK;
}

/*-----------------------------------------------------------------------
 * eth_phy_reset - Reset an Ethernet PHY
 *-----------------------------------------------------------------------
 */
int32	eth_phy_reset (
		volatile struct	eth_a_mdio *mdio, /* MDIO CSR pointer	*/
		byte	phyadr			  /* PHY Address	*/
	)
{
	uint32	phyreg;	/* Variable to hold ETH PHY register value	*/
	int32	retries;/* Number of retries				*/
	int32	retval;	/* Return value of functions called here	*/

	/* Read the PHY Control Register */

	retval = eth_phy_read(mdio, ETH_PHY_CTLREG, phyadr, &phyreg);
	if(retval == SYSERR) {
		return SYSERR;
	}

	/* Set the Reset bit and write the register */

	phyreg |= ETH_PHY_CTLREG_RESET;
	eth_phy_write(mdio, ETH_PHY_CTLREG, phyadr, phyreg);

	/* Check if Reset operation is complete */

	for(retries = 0; retries < 10; retries++) {
		if(eth_phy_read(mdio, ETH_PHY_CTLREG, phyadr, &phyreg) == SYSERR) {
			return SYSERR;
		}
		if((phyreg & ETH_PHY_CTLREG_RESET) == 0) {
			break;
		}
		else {
			retries++;
			DELAY(ETH_AM335X_INIT_DELAY);
			continue;
		}
	}
	if(retries >= 3) {
		return SYSERR;
	}

	/* Check if the Link is established */

	for(retries = 0; retries < 10; retries++) {
		if(eth_phy_read(mdio, ETH_PHY_STATREG, phyadr, &phyreg) == SYSERR) {
			return SYSERR;
		}
		if(phyreg & ETH_PHY_STATREG_LINK) {
			break;
		}
		else {
			retries++;
			DELAY(ETH_AM335X_INIT_DELAY);
			continue;
		}
	}
	if(retries >= 3) {
		return SYSERR;
	}

	return OK;
}

/*-----------------------------------------------------------------------
 * ethinit - initialize the TI AM335X ethernet hardware
 *-----------------------------------------------------------------------
 */
int32	ethinit	(
		struct	dentry *devptr
	)
{
	return OK;
}
