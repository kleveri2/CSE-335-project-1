/**
 * \file Game.h
 *
 * \author Griffin Klevering
 *
 *
 */
#pragma once

using namespace std;
using namespace Gdiplus;
#include <memory>

#include "Vector.h"
#include "Item.h"
#include "Level.h"
#include "Vector.h"
#include "SolidContact.h"
#include "ItemContact.h"
#include "Solid.h"
#include "Door.h"
#include "DoorContact.h"

class CLevel;
class CGame;

/**
* Class for the gnome object
*/

class CGnome
{
public:

	CGnome(CGame* game, CLevel* level);

	//Delete the default constructor later, we need to add in Xml Loading for a real constructor
	/// Default constructor (deleted)
	//CGnome() = delete;

	/// Set the item location
	/// \param x X location
	/// \param y Y location
	void SetLocation(double x, double y) { mP.Set(x, y); }

	/// Set the x velocity
	/// \param x X velocity
	void SetXVelocity(double x) { mV.SetX(x); }

	/// Set the y velocity
	/// \param y Y velocity
	void SetYVelocity(double y) { mV.SetY(y); }

	/** Gets the Y velocity of the gnome
	* \return the velocity of the gnome
	*/
	double GetYVelocity() { return mV.Y(); }

	/** Gets the X velocity of the gnome
	* \return the velocity of the gnome
	*/
	double GetXVelocity() { return mV.X(); }

	void OnDraw(Gdiplus::Graphics* graphics);

	/** Get the x coordinate
	* \return X position
	*/
	double GetX() { return mP.X(); };

	/** Get the y coordinate
	* \return y position
	*/
	double GetY() { return mP.Y(); };

	/** Get the width
	* \return width
	*/
	double GetWidth() { return mWidth; }

	/** Get the height
	* \return height
	*/
	double GetHeight() { return mHeight; }

	void Update(double elasped);

	void GameOverFall(double elapsed);

	/** Get the game the gnome is in
	* \return a pointer to the game
	*/
	CGame* GetGame() { return mGame; }
	/** Sets the remaining boost time
	* \param b The boost time to be set
	*/
	void SetBoostTime(double b) { mBoostTime = b; }
	/** Gets the time remaining for boost
	* \return the boost time
	*/
	double GetBoostTime() { return mBoostTime; }

	/** Sets the gnome in a started state*/
	void SetStart() { mStart = true; }
	
	/** Sets the gnome to be reset from a game over */
	void SetReset() { mReset = true; }

	/** Shows the reset status of the gnome
	* \return A bool of the reset status
	*/
	bool GetReset() { return mReset; }

private:
	///The game the gnome is a part of
	CGame* mGame;

	/// The image of the gnome to be drawn
	unique_ptr<Gdiplus::Bitmap> mImage;

	/// The velocity of the gnome
	CVector mV;

	/// The position of the gnome
	CVector mP;

	/// The level this item is contained in
	CLevel* mLevel;

	/// The time of speed boost
	double mBoostTime;
	///The animation of the gnome
	double mWalkCycle;

	///The level the game is currently in
	int mLevelNumber;
	///The two second of pause
	double mTwoSeconds;
	/// The reset status of the gnome
	bool mReset;
	/// The stat status of the gnome
	bool mStart;

	/// Width of the gnome image
	int mWidth;

	/// Height of the gnome image
	int mHeight;

	///How long the gnome has been reset
	double mResetTime;

};