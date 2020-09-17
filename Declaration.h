/**
 * \file Declaration.h
 *
 * \author Noah Little
 */
#pragma once
#include <string>
#include <memory>

using namespace Gdiplus;
using namespace std;

/**
* Base declaration class
*/
class CDeclaration
{
public:

	virtual ~CDeclaration();

	CDeclaration(const std::wstring id, const std::wstring image, int value = 0);

	virtual void OnDraw(Gdiplus::Graphics* graphics, double x, double y, double width, double height);

	/** Gets the ID of an item
	* \return The ID of the item
	*/
	virtual std::wstring GetID() { return mID; }

	/** Gets the width of an item
	* \return The width of the item
	*/
	virtual double GetImageWidth() { return mWidth; }

	/** Gets the height of an item
	* \return The height of the item
	*/
	virtual double GetImageHeight() { return mHeight; }
	
	/**Gets the value of a money delcaration
	* \return the value of a dollar
	*/
	int GetMoneyValue() { return mValue; }

	/** Gets the image from a declaration
	*\return the image of the object
	*/
	std::shared_ptr<Gdiplus::Bitmap> GetImage() { return mImage; }


private:
	/// The value of an item
	int mValue;

	///The width of the item
	double mWidth;

	///The height of the item
	double mHeight;

	/// Pointers to the images (Use mImage as mMidImage)
	std::shared_ptr<Gdiplus::Bitmap> mImage;

	/// The ID of an item
	std::wstring mID;
};