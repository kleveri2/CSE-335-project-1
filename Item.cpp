/**
 * \file Item.cpp
 *
 * \author Junnan Fu
 */
#include "pch.h"
#include "Item.h"

using namespace std;

/**
* Constructor
*/
CItem::CItem(std::shared_ptr<CDeclaration> declaration, double x, double y) : mDeclaration(declaration)
{
	mP.SetX(x);
	mP.SetY(y);
	mStartP.SetX(x);
	mStartP.SetY(y);
	mHeight = 0;
	mWidth = 0;

	mImageWidth = mDeclaration->GetImageWidth();
	mImageHeight = mDeclaration->GetImageHeight();
}

void CItem::ResetItem()
{
	SetLocation(mStartP.X(), mStartP.Y());
}

/**
* Destructor
*/
CItem::~CItem()
{
}

/**
 * Draws the item
 * \param graphics Graphics its drawn upon
 */
void CItem::OnDraw(Gdiplus::Graphics* graphics)
{
	mDeclaration->OnDraw(graphics, mP.X(), mP.Y(), mWidth, mHeight);
}

/**
* Load an item from a save
* \param node The XML node being loaded
*/
void CItem::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	mP.SetX(node->GetAttributeDoubleValue(L"x", 0));
	mP.SetY(node->GetAttributeDoubleValue(L"y", 0));
	mWidth = node->GetAttributeDoubleValue(L"width", 0);
	mHeight = node->GetAttributeDoubleValue(L"height", 0);
}

void CItem::Update(double elapsed, std::vector<CItem*>* toRemove)
{
}