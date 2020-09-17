/**
 * \file DeclarationWall.cpp
 *
 * \author Noah Little
 */

#include "pch.h"
#include "DeclarationWall.h"

/** Constructor for platform declarations with multiple images
* \param id The id of an item
* \param filename The file being read from
*/
CDeclarationWall::CDeclarationWall(const std::wstring id, const std::wstring filename) : CDeclaration(id, filename)
{
}

/** The drawing of an item
* \param graphics the CChildview being written on
* \param x The X location of an item
* \param y The Y location of an item
* \param width the Width of an item
* \param height the Height of an item
*/
void CDeclarationWall::OnDraw(Gdiplus::Graphics* graphics, double x, double y, double width, double height)
{
	auto imageHeight = GetImage()->GetHeight();
	auto imageWidth = GetImage()->GetWidth();

	double mCurrentWallY = y - (height / 2);

	while (mCurrentWallY < (y + (height / 2)))
	{
		graphics->DrawImage(GetImage().get(),
			int(x - (imageWidth / 2)),
			int(mCurrentWallY),
			32,
			32 + 1);

		mCurrentWallY += imageHeight;
	}
}