/**
 * \file Solid.cpp
 *
 * \author Junnan Fu
 */
#include "pch.h"
#include "Solid.h"

using namespace std;

/** Constructor
*\param declaration The solid declaration being used
* \param x The x coordinate of the solid
* \param y The y coordinate of the solid
*/
CSolid::CSolid(std::shared_ptr<CDeclaration> declaration, double x, double y) : CItem(declaration, x, y) // ????????  Game or level not sure
{
	/// Solid can be standed by Gnome
	SetCanBeStanded(true);
	/// Solid can stop Gnome to move forward and jump
	SetCanStop(true);
}

/**
*  Destructor
*/
CSolid::~CSolid()
{
}