#pragma once
#include <memory>
#include "Item.h"
#include "PowerUpMessage.h"

using namespace std;

/**
* Base class for the Power Up class
*/
class CPowerUp : public CItem
{
public:

	CPowerUp(std::shared_ptr<CDeclaration> declaration, double x, double y);

	//OnDraw() from CItem

	/** Accept a visitor
	 * \param visitor The visitor we accept
	 * \param gnome The gnome we accept
	 */
	virtual void Accept(CItemVisitor* visitor, CGnome* gnome) override { visitor->VisitItem(this, gnome); }
	virtual void UpdateGame(CGame* game);

	virtual void Update(double elapsed, std::vector<CItem*>* toRemove);
	/** Tells if the item has been hit
	* \return if the item has been hit or not.
	*/
	bool GetHit() { return mHit; }
	/** Sets if the item has been hit
	* \param h if the item has been hit or not
	*/
	void SetHit(bool h) { mHit = h; }

	virtual void ResetItem();

private:
	/// If the item has been hit
	bool mHit;
};
