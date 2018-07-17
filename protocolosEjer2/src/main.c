/*
 * Author: Gaston Vallasciani
 * Date: 2018-06-07
 */

/*==================[inclusions]=============================================*/

//#include "rtc.h"   // <= own header (optional)
#include "sapi.h"    // <= sAPI header

#include <string.h>


/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/


/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/


/* FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE RESET. */
int main(void){
	uint8_t dataBluetooth;
	char auxBuff[20];
   /* ------------- INICIALIZACIONES ------------- */

   /* Inicializar la placa */
   boardConfig();
   uartConfig(UART_232,9600);
   uartConfig(UART_USB,9600);
   uartWriteString(UART_232,"Hola mundo APP Inventor!\n\r");
   uartWriteString(UART_USB,"Hola mundo APP Inventor!\n\r");
   gpioWrite(LED1,HIGH);
   delay(1000);
   gpioWrite(LED1,LOW);
   /* ------------- REPETIR POR SIEMPRE ------------- */
   while(1){
	   if (uartReadByte(UART_232,&dataBluetooth)){
		   uint64ToString((dataBluetooth),(auxBuff), 10 );
		   uartWriteString(UART_USB,auxBuff);
		   if(dataBluetooth == 'h'){
			   gpioWrite(LEDB,HIGH);
			   uartWriteString(UART_232,"LEDB Encendido.\n\r");
			   uartWriteString(UART_USB,"LEDB Encendido.\n\r");
		   } else if (dataBluetooth == 'l'){
			   gpioWrite(LEDB,LOW);
			   uartWriteString(UART_232,"LEDB Apagado.\n\r");
			   uartWriteString(UART_USB,"LEDB Apagado.\n\r");
		   }
		   gpioToggle(LEDG);
		   delay(1000);
	   }
   }

   /* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
      por ningun S.O. */
   return 0 ;
}


/*==================[end of file]============================================*/
