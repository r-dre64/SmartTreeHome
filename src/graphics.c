/*
 * graphics.c
 *
 *  Created on: 02.10.2016
 *      Author: Ruven
 */
#include "graphics.h"
#include "setup.h"
#include <stm32746g_discovery_lcd.h>
#include <stdio.h>
#include "stm32746g_discovery_ts.h"



typedef struct
{
	GraphicalObject Type;
	int xPos;
	int yPos;
	int graphValues[16];
	int returnMin;
	int returnMax;
	int steps;
}GraphObject;

struct
{
	GraphObject Objects[64];
	int numberOfObjects;
}theObjects;

//AllObjects theObjects;

void addObjekt(GraphicalObject Type,int xPos,int yPos,int graphValues[16],int returnMin,int returnMax,int steps)
{
	static int firstInit=0;
	if(firstInit==0)
	{
		theObjects.numberOfObjects =0;
		firstInit=1;
	}

	/*values:
	 * 0: SlideControl
	 * Width, Height
	 * 1: CheckButton
	 * no Parameter yet
	 * 2: Tabs
	 * no Parameter yet
	 * 3: Button
	 * Width, Height
	 */
	int numOfGraphVals[8]={2,0,0,2};

	theObjects.Objects[theObjects.numberOfObjects].Type=Type;
	theObjects.Objects[theObjects.numberOfObjects].xPos=xPos;
	theObjects.Objects[theObjects.numberOfObjects].yPos=yPos;
	theObjects.Objects[theObjects.numberOfObjects].returnMax=returnMax;
	theObjects.Objects[theObjects.numberOfObjects].returnMin=returnMin;
	theObjects.Objects[theObjects.numberOfObjects].steps=steps;
	int count;
	for(count=0;count<numOfGraphVals[(int)Type];count++)
	{
		theObjects.Objects[theObjects.numberOfObjects].graphValues[count]=graphValues[count];
	}
	theObjects.numberOfObjects++;
}

void printAllObjects()
{
	int count;
	for(count=0;count<theObjects.numberOfObjects;count++)
	{
		switch(theObjects.Objects[count].Type)
		{
		case Tabs:

			break;
		case SlideControl:
			BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
			BSP_LCD_DrawRect(theObjects.Objects[count].xPos,theObjects.Objects[count].yPos,theObjects.Objects[count].graphValues[0],theObjects.Objects[count].graphValues[1]);
			break;
		case CheckButton:

			break;
		case Button:

			break;
		}
	}

}

//Named in "startup_stm32f746xx.s"
void TIM1_UP_TIM10_IRQHandler()
{
	TIM10->SR = ~TIM1_UP_TIM10_IRQn; // Stolen from __HAL_TIM_CLEAR_IT()
	HAL_NVIC_ClearPendingIRQ(TIM1_UP_TIM10_IRQn);


	TS_StateTypeDef TS_State;
	BSP_TS_GetState(&TS_State);

	static int y=100,x=10;

	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_FillCircle(y,100,15);
	if(y<=100)
	{
		x=10;
	}
	if(y>=400)
	{
		x=-10;
	}
	y+=x;



		BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
		BSP_LCD_FillCircle(y,100,15);



}



