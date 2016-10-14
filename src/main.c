/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include "setup.h"
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "graphics.h"
			

int main(void)
{

	setup();
	int graphValues[16]={30,150};
	addObjekt(SlideControl,310,30,graphValues,0,100,1,0);
	addObjekt(SlideControl,350,10,graphValues,0,150,3,0);
	printAllObjects();

	while(1);
	/*
	 * Tim... Interrupt Cycle
	 */
}
