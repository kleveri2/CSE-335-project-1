#include "pch.h"

#pragma once
#include <memory>
#include "Villain.h"
/** Constructor
* \param declaration The declaration being made from
* \param x The x location of the powerup
* \param y The y location of the powerup
* \param width The width of the villain
* \param height The height of the villain
*/
CVillain::CVillain(std::shared_ptr<CDeclaration> declaration, double x, double y, double width, double height) : CItem(declaration, x, y)
{
	SetWidth(width);
	SetHeight(height);
	mV.SetX(0);
	mV.SetY(-240);
	mTime = 0;
}

/** This will do a specific task, please update this header later
* \param game The game being played in.
*/

void CVillain::UpdateGame(CGame* game)
{
	//game->Reset();
	game->GetGnome()->SetReset();
}

/**
* Update function
* \param elapsed The time since the last update
* \param toRemove A vector of items to be removed from the main list
*/
void CVillain::Update(double elapsed, std::vector<CItem*>* toRemove)
{
	if (mTime > 1.25)
	{
		CVector newV(0, -mV.Y());
		SetSpeed(newV);
		SetTime(0);
	}
	CVector newP = GetPositionVector() + GetSpeed() * elapsed;
	double passed = GetTime();
	passed += elapsed;
	SetTime(passed);
	SetLocation(newP.X(), newP.Y());
}

/** Resets the villain location and if its been hit */
void CVillain::ResetItem()
{
	this->CItem::ResetItem();
	mTime = 0;
	mV.SetY(-240);
	
}