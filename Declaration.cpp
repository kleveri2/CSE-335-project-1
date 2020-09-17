/**
 * \file Declaration.cpp
 *
 * \author Noah Little
 */

#include "pch.h"
#include "Declaration.h"

/** Constructor for declarations with a single image and money value
* \param id The id of an item
* \param filename The image file
* \param value the value of an item
*/
CDeclaration::CDeclaration(const std::wstring id, const std::wstring filename, int value)
{
	mID = id;
	mValue = 0;

	std::wstring imagefile;
	imagefile = L"images/" + filename;

	mImage = shared_ptr<Bitmap>(Bitmap::FromFile(imagefile.c_str()));
	if (mImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}


	mValue = value;

	mHeight = mImage->GetHeight();
	mWidth = mImage->GetWidth();
}


CDeclaration::~CDeclaration()
{

}

/** The drawing of an item
* \param graphics the CChildview being written on
* \param x The X location of an item
* \param y The Y location of an item
* \param width the Width of an item
* \param height the Height of an item
*/
void CDeclaration::OnDraw(Gdiplus::Graphics* graphics, double x, double y, double width, double height)
{

	graphics->DrawImage(mImage.get(),
		int(x - (mWidth/2)),
		int(y - (mHeight/2)),
		int(mWidth),
		int(mHeight));
}