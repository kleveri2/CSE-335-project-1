#include "pch.h"
#include "FastTrack.h"

/**  constructor of the Fast Track powerup
* \param declaration The declaration being used
* \param x The X location of an item
* \param y The Y location of an item
*/
CFastTrack::CFastTrack(std::shared_ptr<CDeclaration> declaration, double x, double y) : CPowerUp(declaration, x, y)
{
}

/** This will do a specific task, please update this header later
* \param game The game being played in.
*/
void CFastTrack::UpdateGame(CGame* game)
{
	if (GetHit() == false)
	{
		auto message = make_shared<CPowerUpMessage>(L"Fast Track!", GetX(), GetY());

		game->Add(message);

		SetHit(true);
		game->GetGnome()->SetBoostTime(20);
	}
}