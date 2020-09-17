/**
 * \file DeclarationPlatform.h
 *
 * \author Noah Little
 */
#pragma once
#include "Declaration.h"

 /**
 * Class for the platform declaration
 */
class CDeclarationPlatform :
	public CDeclaration
{
public:

	CDeclarationPlatform(const std::wstring id, const std::wstring leftimage,
		const std::wstring midimage, const std::wstring rightimage);

	virtual void OnDraw(Gdiplus::Graphics* graphics, double x, double y, double width, double height) override;

private:
	///Pointer to the left image
	std::shared_ptr<Gdiplus::Bitmap> mLeftImage;
	///Pointer to the right of the image
	std::shared_ptr<Gdiplus::Bitmap> mRightImage;
};
