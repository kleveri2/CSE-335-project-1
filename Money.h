#pragma once

#include "Item.h"
#include "Declaration.h"
#include "LevelMessage.h"

/**
* Class for the money object
*/
class CMoney : public CItem
{
public:
	//void OnDraw();

	CMoney(std::shared_ptr<CDeclaration> declaration, double x, double y, double width, double height);

	/** Accept a visitor
	 * \param visitor The visitor we accept
	 * \param gnome The gnome we accept
	 */
	virtual void Accept(CItemVisitor* visitor, CGnome* gnome) override { visitor->VisitItem(this, gnome); }

	virtual void UpdateGame(CGame* game);

	/** Gets the value of a money object
	* \return the value of the object
	*/
	int GetValue() { return mValue; }
	/** Sets the value of money
	* \param v The value to be set
	*/
	void SetValue(int v) { mValue = v; }

	virtual void Update(double elapsed, std::vector<CItem*>* toRemove);
	void ResetItem();
	/** Sets the hit value of money
	* \param h if its been hit
	*/
	void SetHit(bool h) { mHit = h; }

private:
	/// The value of a money object
	int mValue;
	///The ID of an object
	string mId;
	///If the money has been hit
	bool mHit;
};

