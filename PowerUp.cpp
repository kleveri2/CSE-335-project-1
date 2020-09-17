#include "pch.h"
#include "PowerUp.h"
#include "Game.h"


/**  constructor of the Power Up items
* \param declaration The declaration being used
* \param x The X location of an item
* \param y The Y location of an item
*/
CPowerUp::CPowerUp(std::shared_ptr<CDeclaration> declaration, double x, double y) : CItem(declaration, x, y)
{
	mHit = false;
}

/** This will do a specific task, please update this header later
* \param game The game being played in.
*/
void CPowerUp::UpdateGame(CGame* game)
{

}

/**
* Update function
* \param elapsed The time since the last update
* \param toRemove A vector of items to be removed from the main list
*/
void CPowerUp::Update(double elapsed, std::vector<CItem*>* toRemove)
{
	if (mHit == true)
	{
		CVector v(0, 500);
		CVector newP = GetPositionVector() + v * elapsed;
		SetLocation(newP.X(), newP.Y());
		if (GetPositionVector().Y()- GetImageHeight()  > 1024)
		{
			toRemove->push_back(this);
		}
	}
}

/** Resets the powerup location and if its been hit */
void CPowerUp::ResetItem()
{
	this->CItem::ResetItem();
	mHit = false;
}