#include "pch.h"
#include "TuitionUp.h"
#include "Game.h"

/** Constructor
* \param declaration The declaration being made from
* \param x The x location of the powerup
* \param y The y location of the powerup
*/
CTuitionUp::CTuitionUp(std::shared_ptr<CDeclaration> declaration, double x, double y) : CPowerUp(declaration, x, y)
{
	mMultiplier = .1;
}

/** This will do a specific task, please update this header later
* \param game The game being played in.
*/
void CTuitionUp::UpdateGame(CGame* game)
{
	if (GetHit() == false)
	{
		auto message = make_shared<CPowerUpMessage>(L"Tuition-Up!", GetX(), GetY());

		game->Add(message);

		SetHit(true);
		game->GetScoreboard()->AddMultiplier(.1);
	}
}