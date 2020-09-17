/**
 * \file Item.h
 *
 * \author Junnan Fu
 */
#pragma once
#include <string>
#include <memory>
#include "Vector.h"
#include "ItemVisitor.h"
#include "XmlNode.h"
#include "Declaration.h"
#include <vector>
class CGame;

using namespace xmlnode;
using namespace Gdiplus;

/**
* Class for the Item object
*/
class CItem
{
public:

	~CItem();

	virtual void OnDraw(Gdiplus::Graphics* graphics);

	/// Default constructor (disabled)
	CItem() = default;

	/// Copy constructor (disabled)
	CItem(const CItem&) = delete;

	/**  The The ability for something to be stood upon
	* \returns true or false */
	bool GetCanBeStanded() { return mCanBeStanded; }

	/**  The The ability for something to stop
	* \returns true or false */
	bool GetCanStop() { return mCanStop; }

	/**  Set the ability to be stoop upon
	* \param mStand true or false standing */
	void SetCanBeStanded(bool mStand) { mCanBeStanded = mStand; }

	/**  Set the ability to stop
	* \param mStop true or false stopping */
	void SetCanStop(bool mStop) { mCanBeStanded = mStop; }

	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

	/**  The X location of the center of the item
	* \returns X location in pixels */
	double GetX() const { return mP.X(); }

	/**  The Y location of the center of the item
	* \returns Y location in pixels */
	double GetY() const { return mP.Y(); }

	/**  The Width of the item's image
	* \returns Width in pixels */
	double GetImageWidth() { return mImageWidth; }

	/**  The Height of the item's image
	* \returns Height in pixels */
	double GetImageHeight() { return mImageHeight; }

	/**  The Width of the item
	* \returns Width in pixels */
	double GetWidth() { return mWidth; }

	/**  The Height of the item
	* \returns Height in pixels */
	double GetHeight() { return mHeight; }

	/** Change the width of an object
	* \param width The width being set to
	*/
	void SetWidth(double width) { mWidth = width; }
	
	/** Change the height of an item
	* \param height The height being set to
	*/
	void SetHeight(double height) { mHeight = height; }

	/**  Set the item location
	* \param x X location
	* \param y Y location */
	void SetLocation(double x, double y) { mP.SetX(x); mP.SetY(y); }

	/** Get the position from the position vector
	* \return the positition in vector
	*/
	CVector GetPositionVector() { return mP; }

	/** Accept a visitor
	 * \param visitor The visitor we accept
	 * \param gnome The gnome we accept
	 */
	virtual void Accept(CItemVisitor* visitor, CGnome* gnome) = 0;


	/** Updates the game according to each item
	* \param game The Game being updated
	*/
	virtual void UpdateGame(CGame* game) {}; //The plan is for each item to have a function that runs.


	/** Updates the item
	* \param elapsed The time elasped since the last update
	* \param toRemove A vector of items being removed from the master list
	*/
	virtual void Update(double elapsed, std::vector<CItem*>* toRemove);

	/** The ID of an item
	* \return The id of an item
	*/
	std::wstring GetDeclarationID() { return mDeclaration->GetID(); }

	/** Resets an item back to the levels original state*/
	virtual void ResetItem();

protected:
	/** Constructs an item with an image
	* \param declaration Pointer to the declaration that describes the object
	* \param x Location of object in x direction
	* \param y Location of object in y direction
	*/
	CItem(std::shared_ptr<CDeclaration> declaration, double x, double y);


private:


	/// The width of an item in pixels
	double mWidth;
	/// The height of an item in pixels
	double mHeight;

	/// The width of the item's image
	double mImageWidth;

	/// The height of the item's image
	double mImageHeight;

	///Location of the item
	CVector mP;

	///The starting location of the item
	CVector mStartP;

	///If the item can be standed
	bool mCanBeStanded = true;
	///If the item can stop Gnome
	bool mCanStop = true;

	///The declaration of the item
	std::shared_ptr<CDeclaration> mDeclaration;
};
