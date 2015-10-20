
// ----------------------------------------------------------------------------

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"


/* HAL Drivers Includes ------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm32f4xx_hal_rcc.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_tim.h"
#include "system_stm32f4xx.h"


/*MX Cube*/
#include "stm32f4xx_it.h"

/* Personal Includes ---------------------------------------------------------*/
#include "Timer.h"


/************************************/
/************ PROTOYPES *************/
/************************************/
/*LOOK AT THIS BITCHH*/

/*Handler de la s�quence d'interruptiton du timer 4*/
//void TIM4_IRQHandler(void);

/*Global Variables*/


/*******MAIN********/
int main( ){ /*Enlev� les arguments  "int arc, char **argv", ne servent pas dans l'application*/


	uint32_t j,i,k = 0;
	/*Initialize the system*/
	SystemInit() ;

	SystemClock_Config();
	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_MspInit();


	TM_LEDS_Init();
	TM_TIMER_PWM_Init(DUTYCYCLE_BIT_1);
	Ini_Interrupt_TIM4();

	/*Code pas ex�cut�. Pourquoi ?*/
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);


	while(1){
	  i = NVIC_GetPendingIRQ(TIM4_IRQn);
	  k = NVIC_GetActive(TIM4_IRQn);
	}

	return EXIT_SUCCESS;
}







