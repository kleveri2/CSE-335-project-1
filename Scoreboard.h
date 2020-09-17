/**
 * \file Door.h
 *
 * \author Junnan Fu & Yash
 */
#pragma once

#include <vector>
#include <memory>
#include "Money.h"
#include "XmlNode.h"

class CGame;

/**
* Scoreboard object class
*/
class CScoreboard
{
public:

	CScoreboard(CGame* game);

	void OnDraw(Gdiplus::Graphics* graphics, int width, int height);
	void Sum(CMoney* money);

	/**Reset the score */
	void SetZero();
	void Update(double elapsed);

	/** Gets the score
	* \return the score of the game
	*/
	int GetScore() { return mScore; }

	/**Set the money multiplier
	* \param m the multiplier being added
	*/
	void AddMultiplier(double m) { mMultiplier += m; }

	/**Get the money multiplier
	* \returns the multiplier for the money
	*/
	double GetMultiplier() { return mMultiplier; }

private:
	///The game the scoreboard is in
	CGame* mGame;

	/// The x coordinate of the scoreboard
	double mBoardLocX;

	/// The y coordinate of the scoreboard
	double mBoardLocY;

	///The score displayed on the board
	int mScore;

	///The multiplier from powerups
	double mMultiplier;

	/// The x coordinate of the Time
	double mTimeLocX;

	/// The y coordinate of the Time
	double mTimeLocY;

	///The seconds of the time
	int mTimeSecond;

	///The minutes of the time
	int mTimeMinute;

	///The total time elapsed
	double mGameTime;

	///Filename of the level
	std::wstring mLevel;
};
