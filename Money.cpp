#include "pch.h"
#include "Money.h"
#include "Game.h"


/** The drawing of a platform
* \param declaration the declaration being used
* \param x The X location of an item
* \param y The Y location of an item
* \param width the Width of an item
* \param height the Height of an item
*/
CMoney::CMoney(std::shared_ptr<CDeclaration> declaration, double x, double y, double width, double height) : CItem(declaration, x, y)
{
	mValue = declaration->GetMoneyValue();
	mHit = false;
}

/** This will do a specific task, please update this header later
* \param game The game being played in.
*/
void CMoney::UpdateGame(CGame* game)
{
	if (mHit == false)
	{
		game->GetScoreboard()->Sum(this);

		auto message = make_shared<CLevelMessage>((game->GetScoreboard()->GetMultiplier()*mValue), GetX(), GetY());

		game->Add(message);

		mHit = true;
	}
}

/**
* Update function
* \param elapsed The time since the last update
* \param toRemove A vector of items to be removed from the main list
*/
void CMoney::Update(double elapsed, std::vector<CItem*>* toRemove)
{
	if (mHit == true)
	{
		CVector v(0, -700);
		CVector newP = GetPositionVector() + v * elapsed;
		SetLocation(newP.X(), newP.Y());
		if (GetPositionVector().Y() < -20)
		{
			toRemove->push_back(this);
		}
	}
}

/** Resets the money location and if its been hit */
void CMoney::ResetItem()
{
	this->CItem::ResetItem();
	mHit = false;
}

