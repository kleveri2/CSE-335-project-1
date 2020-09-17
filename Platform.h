/**
 * \file Platform.h
 *
 * \author Junnan Fu
 */
#pragma once
#include <memory>
#include "Solid.h"

using namespace std;
using namespace Gdiplus;
/**
* Class for the platform object
*/
class CPlatform : public CSolid
{
public:
	/**  constructor of the platform
	* \param declaration The declaration being used
	* \param x The X location of an item
	* \param y The Y location of an item
	* \param width the Width of an item
	* \param height the Height of an item
	*/
	CPlatform(std::shared_ptr<CDeclaration> declaration, double x, double y, double width, double height);

private:
};