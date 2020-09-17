/**
 * \file DeclarationWall.h
 *
 * \author Noah Little
 *
 * 
 */

#pragma once
#include "Declaration.h"

/**
* Class for the wall declaration
*/
class CDeclarationWall :
	public CDeclaration
{
public:

	CDeclarationWall(const std::wstring id, const std::wstring filename);

	virtual void OnDraw(Gdiplus::Graphics* graphics, double x, double y, double width, double height) override;
};
