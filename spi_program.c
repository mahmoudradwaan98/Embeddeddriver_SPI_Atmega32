/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan        **********************/
/****************    Layer     : MCAL                  *********************/
/****************    SWC       : SPI                   ********************/
/****************    version   : 1.0                   *******************/
/************************************************************************/
/***********************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "SPI_config.h"
#include "SPI_private.h"
#include "SPI_interface.h"
#include "SPI_register.h"

void SPI_voidMasterInit(void)
{
	/* SPI Enable */
	SET_BIT(SPCR,SPCR_SPE);
	/* Master INIT */
	SET_BIT(SPCR,SPCR_MSTR);
	/*CLK rate init for Master only (Fosc : divie by 16)*/
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
}
void SPI_voidSlaveInit(void)
{
	/* SPI Enable */
	SET_BIT(SPCR,SPCR_SPE);
	/* Slave INIT */
	CLR_BIT(SPCR,SPCR_MSTR);
	
}
u8 SPI_u8Transceive(u8 copy_u8Data)
{
	/* start the data */
	SPDR = copy_u8Data;
	/* polling (busy waiting) untill transfer is complete */
	while(GET_BIT(SPCR,SPSR_SPIF)==0);
	/* Get the exchange data */
	return SPDR;
}

	
