#pragma once
#include "Item.h"
#include <string>
#include <sstream>

/**
 * Establishes different game messages based on object hit
 */
class CLevelMessage : public CItem
{
public:

	CLevelMessage(int value, double x, double y);

	~CLevelMessage();

	virtual void OnDraw(Gdiplus::Graphics* graphics);
	virtual void Update(double elapsed, std::vector<CItem*>* toRemove);

	/** Accepts an item visitor
	* \param visitor The item visitor being brought
	* \param gnome the gnome also being visited
	*/
	void Accept(CItemVisitor* visitor, CGnome* gnome) {};

private:
	///Location of the item
	CVector mP;
	///The value of an item
	int mValue;
	///The time elapsed
	double mTime;
};