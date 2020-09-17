/**
 * \file Door.cpp
 *
 * \author Junnan Fu
 */
#include "pch.h"
#include "Door.h"
using namespace std;

/**  constructor of the door
* \param declaration The declaration being used
* \param x The X location of an item
* \param y The Y location of an item
* \param width the Width of an item
* \param height the Height of an item
*/
CDoor::CDoor(std::shared_ptr<CDeclaration> declaration, double x, double y, double width, double height) : CItem(declaration, x, y)
{
	/// Door cannot be standed by Gnome
	SetCanBeStanded(false);
	/// Door cannot stop Gnome to move forward and jump
	SetCanStop(false);

	SetWidth(width);
	SetHeight(height);
}

/**
*  Destructor
*/
CDoor::~CDoor()
{
}