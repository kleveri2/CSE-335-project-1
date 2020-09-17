/**
 * \file DeclarationBackground.h
 *
 * \author Noah Little
 *
 * 
 */

#pragma once
#include "Declaration.h" /**
 * Class for the background declaration
 */
class CDeclarationBackground :
	public CDeclaration
{
public:

	CDeclarationBackground(const std::wstring id, const std::wstring filename);

	virtual void OnDraw(Gdiplus::Graphics* graphics, double x, double y, double width, double height) override;

private:
    
    ///Height of image
    double mHeight;

    ///Width of image
    double mWidth;
};
