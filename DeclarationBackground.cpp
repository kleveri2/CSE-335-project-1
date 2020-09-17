/**
 * \file DeclarationBackground.cpp
 *
 * \author Noah Little
 */

#include "pch.h"
#include "DeclarationBackground.h"

/** Constructor for platform declarations with multiple images
* \param id The id of an item
* \param filename The file being read from
*/
CDeclarationBackground::CDeclarationBackground(const std::wstring id, const std::wstring filename) : CDeclaration(id, filename)
{
	mHeight = GetImage()->GetHeight();
	mWidth = GetImage()->GetWidth();
}

/** The drawing of a platform
* \param graphics the CChildview being written on
* \param x The X location of an item
* \param y The Y location of an item
* \param width the Width of an item
* \param height the Height of an item
*/
void CDeclarationBackground::OnDraw(Gdiplus::Graphics* graphics, double x, double y, double width, double height)
{

	graphics->DrawImage(GetImage().get(),
		int(x - (mWidth / 2)),
		int(y - (mHeight / 2)),
		int(mWidth + 1),
		int(mHeight));
}