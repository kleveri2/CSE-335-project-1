/**
 * \file DeclarationPlatform.cpp
 *
 * \author Noah Little
 */

#include "pch.h"
#include "DeclarationPlatform.h"

/** Constructor for platform declarations with multiple images
* \param id The id of an item
* \param leftimage The left of the platform
* \param midimage The middle of an platform
* \param rightimage The right of the platform
*/
CDeclarationPlatform::CDeclarationPlatform(const std::wstring id, const std::wstring leftimage,
	const std::wstring midimage, const std::wstring rightimage) : CDeclaration(id, midimage)
{
	std::wstring imagefile;
	imagefile = L"images/" + leftimage;

	mLeftImage = shared_ptr<Bitmap>(Bitmap::FromFile(imagefile.c_str()));
	if (mLeftImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += leftimage;
		AfxMessageBox(msg.c_str());
	}

	imagefile = L"images/" + rightimage;

	mRightImage = shared_ptr<Bitmap>(Bitmap::FromFile(imagefile.c_str()));
	if (mRightImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += rightimage;
		AfxMessageBox(msg.c_str());
	}
}

/** The drawing of a platform
* \param graphics the CChildview being written on
* \param x The X location of an item
* \param y The Y location of an item
* \param width the Width of an item
* \param height the Height of an item
*/
void CDeclarationPlatform::OnDraw(Gdiplus::Graphics* graphics, double x, double y, double width, double height)
{
	auto imageWidth = GetImage()->GetWidth();
	auto imageHeight = GetImage()->GetHeight();

	double mCurrentMidWallX = x - (width / 2);

	/// Draw the middle platforms
	///SetPlatform(L"snowMid.png");
	while (mCurrentMidWallX <= (x + (width / 2) - (imageWidth / 2)))
	{
		graphics->DrawImage(GetImage().get(),
			int(mCurrentMidWallX),
			int(y - (imageHeight / 2)),
			32 + 1,
			32);

		mCurrentMidWallX += imageWidth;
	}

	////// Draw the LEFT platform
	///SetPlatform(L"snowLeft.png");
	graphics->DrawImage(mLeftImage.get(),
		int(x - (width / 2)),
		int(y - (imageHeight / 2)),
		32 + 1,
		32);

	/// Draw the right platform
	///SetPlatform(L"snowRight.png");
	graphics->DrawImage(mRightImage.get(),
		int(x + (width / 2) - (imageWidth)),
		int(y - (imageHeight / 2)),
		32 + 1,
		32);
}