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
	int Value;
}GraphObject;

struct
{
	GraphObject Objects[64];
	int numberOfObjects;
}theObjects;

//AllObjects theObjects;

void addObjekt(GraphicalObject Type,int xPos,int yPos,int graphValues[16],int returnMin,int returnMax,int steps, int initValue)
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
	theObjects.Objects[theObjects.numberOfObjects].Value = initValue;

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

int limitToArea(int value, int min, int max)
{

	if(value>max)
	{
		value=max;
	}
	if(value<min)
	{
		value=min;
	}


	return value;
}

/*
 * returns value scaled to steps
 */
void extractValue(GraphObject *Obj,int yValue)
{
	int relativeVal;
	int maxY;
	int valRange;

	switch(Obj->Type)
	{
	case SlideControl:
		relativeVal = yValue-Obj->yPos;
		maxY = Obj->graphValues[1];
		valRange = Obj->returnMax;

		Obj->Value = relativeVal*valRange/maxY; //Scales the Y-value to range

		//Obj->Value=Obj->returnMax-Obj->Value+Obj->returnMin;

		//Limits the Value to max and min
		if(Obj->Value>Obj->returnMax)
		{
			Obj->Value=Obj->returnMax;
		}
		if(Obj->Value<Obj->returnMin)
		{
			Obj->Value=Obj->returnMin;
		}

		//Scales the value to step width
		Obj->Value/=Obj->steps;
		Obj->Value*=Obj->steps;


		break;
	}
}

//Named in "startup_stm32f746xx.s"
void TIM1_UP_TIM10_IRQHandler()
{
	TIM10->SR = ~TIM1_UP_TIM10_IRQn; // Stolen from __HAL_TIM_CLEAR_IT()
	HAL_NVIC_ClearPendingIRQ(TIM1_UP_TIM10_IRQn);


	static TS_StateTypeDef TS_State;
	BSP_TS_GetState(&TS_State);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);

	char strin[32];
	sprintf(strin,"Y:%i X:%i",TS_State.touchY[0],TS_State.touchX[0]);
	BSP_LCD_DisplayStringAt(100,100,strin, LEFT_MODE);

	static int touchedObject=-1;
	if(touchedObject!=-1) //If screen is already touched
	{
		if(TS_State.touchDetected>0) //If screen is still touched
		{
			extractValue(&theObjects.Objects[touchedObject],TS_State.touchY[0]);


			char strn[32];
			sprintf(strn,"Val:%i  ",theObjects.Objects[touchedObject].Value);
			BSP_LCD_DisplayStringAt(100,120+(touchedObject*20),strn, LEFT_MODE);


		}else
		{
			touchedObject=-1;
		}

	}else //New Touch
	{

		int count;
		for(count=0;count<theObjects.numberOfObjects;count++)
		{

			if(TS_State.touchY[0]<(theObjects.Objects[count].yPos+theObjects.Objects[count].graphValues[1])
			   &&TS_State.touchY[0]>theObjects.Objects[count].yPos
			   &&TS_State.touchX[0]<(theObjects.Objects[count].xPos+theObjects.Objects[count].graphValues[0])
			   &&TS_State.touchX[0]>theObjects.Objects[count].xPos)
			{
				if(TS_State.touchDetected>0)
				{
					extractValue(&theObjects.Objects[touchedObject],TS_State.touchY[0]);
				}
				char strn[32];
				sprintf(strn,"Val:%i  ",theObjects.Objects[count].Value);
				BSP_LCD_DisplayStringAt(100,120+(count*20),strn, LEFT_MODE);

				touchedObject = count;
				count= theObjects.numberOfObjects;
			}else
			{
				char strn[32];
				sprintf(strn,"Val:%i",theObjects.Objects[count].Value);
				BSP_LCD_DisplayStringAt(100,120+(count*20),strn, LEFT_MODE);
			}
		}
	}


	static int X=100, Y=100,Yvelo=200,s=0,minus=1;

	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_FillCircle(X,Y,15);
	s+=minus;
	Y=s*s/5+100;
	if(Y>=265)
	{
		minus*=-1;
	}
	if(Y<100)
	{
		minus*=-1;
	}

	if(X<=20)
	{
		Yvelo*=-1;
	}
	if(X>=460)
	{
		Yvelo*=-1;
	}
	X+=Yvelo/50;



	BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	BSP_LCD_FillCircle(X,Y,15);
	printAllObjects();


}



