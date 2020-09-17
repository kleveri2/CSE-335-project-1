#pragma once
#include "PowerUp.h"

/**
* Class for the TuitionUp object
*/
class CTuitionUp : public CPowerUp
{
public:

	CTuitionUp(std::shared_ptr<CDeclaration> declaration, double x, double y);


	virtual void UpdateGame(CGame* game);

private:
	///The multiplier the power up gives
	double mMultiplier;
};
