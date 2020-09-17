#pragma once

#include "PowerUp.h"
#include "Game.h"

/**
* Class for the game object
*/
class CFastTrack : public CPowerUp
{
public:
	//mostly empty because inheireted from CPowreUp and CItem
	/** Accept a visitor
	 * \param visitor The visitor we accept
	 * \param gnome The gnome we accept
	 */
	virtual void Accept(CItemVisitor* visitor, CGnome* gnome) override { visitor->VisitItem(this, gnome); }

	virtual void UpdateGame(CGame* game);

	CFastTrack(std::shared_ptr<CDeclaration> declaration, double x, double y);

private:
};
