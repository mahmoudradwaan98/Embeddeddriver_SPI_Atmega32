#include "STD_TYPES.h"

#include <util/delay.h>

#include "PORT_interface.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "PORT_interface.h"

/* Master Application */

void main(void)
{
	/* port INIT*/
	PORT_voidInit();
	/* Master INIT*/
	SPI_voidMasterInit();
	/* send data by master */
	while(1){
		
		SPI_u8Transceive(1);
		_delay_ms(10);
	}
	
}

/* Slave Application */

void main(void)
{
	u8 Local_u8ReceivedData;
	/* port INIT*/
	PORT_voidInit();
	/* Slave INIT*/
	SPI_voidSlaveInit();
	/* receive data by slave */
	while(1)
	{
		
		/* pass to SPI_u8Transceive() any garbage value */
		Local_u8ReceivedData = SPI_u8Transceive(10);
		_delay_ms(10);
		if(Local_u8ReceivedData==1)
		{
			LED_ON();
		}
		
	}
	
}