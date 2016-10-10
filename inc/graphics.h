/*
 * graphics.h
 *
 *  Created on: 02.10.2016
 *      Author: Ruven
 */

#ifndef GRAPHICS_H_
#define GRAPHICS_H_

typedef enum
{
	SlideControl=0,
	CheckButton=1,
	Tabs=2,
	Button=3
}GraphicalObject;

void addObjekt(GraphicalObject Type,int xPos,int yPos,int graphValues[16],int returnMin,int returnMax,int steps);
void printAllObjects();

#endif /* GRAPHICS_H_ */
