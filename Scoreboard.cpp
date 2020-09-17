/**
 * \file Scoreboard.cpp
 *
 * \author Yash Anandakumar & Junnan Fu
 */

#include "pch.h"
#include "Scoreboard.h"
#include "Game.h"
#include <sstream>
#include "Level.h"

using namespace std;
using namespace Gdiplus;



/**The constructor of the scoreboard
* \param game The game the scoreboard is in
*/
CScoreboard::CScoreboard(CGame* game) : mGame(game)
{
	mMultiplier = 1;
	mTimeLocX = 200;
	mTimeLocY = 0;
	mTimeSecond = 0;
	mTimeMinute = 0;
	mGameTime = 0;
	mScore = 0;
	mBoardLocX = 1600;
	mBoardLocY = 0;
}

/**
* Draws scoreboard on screen
* \param graphics The graphics the scoreboard is being drawn on
* \param width The width of the board
* \param height The height of the board
*/
void CScoreboard::OnDraw(Gdiplus::Graphics* graphics, int width, int height)
{



	wstringstream mScoreDisplay;
	mScoreDisplay << L"$" << mScore;

	wstringstream mTimeDisplay;
	if (mTimeSecond < 10)
	{
		mTimeDisplay << mTimeMinute << ":0" << mTimeSecond;
	}
	else
	{
		mTimeDisplay << mTimeMinute << ":" << mTimeSecond;
	}

	/// Sets Font
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 80);
	StringFormat centFormat;
	StringFormat scoreFormat;

	scoreFormat.SetTrimming(StringTrimmingNone);

	RectF rectScore(Gdiplus::REAL(width), 0, 0, 0);
	RectF rectTime(0, 0, 0, 0);

	/// Displays Scoreboard
	SolidBrush blue(Color(BYTE(40), BYTE(1500), BYTE(2000)));
	SolidBrush green(Color(BYTE(40), BYTE(2000), BYTE(40)));
	SolidBrush red(Color(BYTE(2000), BYTE(40), BYTE(40)));
	graphics->DrawString(mTimeDisplay.str().c_str(), -1, &font, rectTime, &scoreFormat, &blue);
	scoreFormat.SetFormatFlags(StringFormatFlagsDirectionRightToLeft);
	graphics->DrawString(mScoreDisplay.str().c_str(), -1, &font, rectScore, &scoreFormat, &blue);

	//Level Start Message
	if (mTimeSecond <= 2 && mTimeMinute == 0)
	{
		mLevel = mGame->GetLevelName();

		std::wstring levelStart;

		if (mLevel == L"levels/level1.xml")
		{
			levelStart = L"Level 1";
		}
		else if (mLevel == L"levels/level2.xml")
		{
			levelStart = L"Level 2";
		}
		else if (mLevel == L"levels/level3.xml")
		{
			levelStart = L"Level 3";
		}
		else
			levelStart = L"Level 0";

		centFormat.SetAlignment(StringAlignmentCenter);
		centFormat.SetLineAlignment(StringAlignmentCenter);
		RectF rectCenter(Gdiplus::REAL(width / 2), Gdiplus::REAL(height / 2), 0, 0);
		rectCenter.Inflate(400, 400);
		graphics->DrawString(levelStart.c_str(), -1, &font, rectCenter, &centFormat, &green);
	}

	if (mGame->GetGnome()->GetReset() == true)
	{
		centFormat.SetAlignment(StringAlignmentCenter);
		centFormat.SetLineAlignment(StringAlignmentCenter);
		std::wstring levelStart(L"You Lose!");
		RectF rectCenter(Gdiplus::REAL(width / 2), Gdiplus::REAL(height / 2), 0, 0);
		rectCenter.Inflate(400, 400);
		graphics->DrawString(levelStart.c_str(), -1, &font, rectCenter, &centFormat, &red);
	}
	if (mGame->GetLevelComplete() == true) 
	{
		centFormat.SetAlignment(StringAlignmentCenter);
		centFormat.SetLineAlignment(StringAlignmentCenter);
		std::wstring levelStart(L"Level Complete!");
		RectF rectCenter(Gdiplus::REAL(width / 2), Gdiplus::REAL(height / 2), 0, 0);
		rectCenter.Inflate(400, 400);
		graphics->DrawString(levelStart.c_str(), -1, &font, rectCenter, &centFormat, &green);
	}
}

/**
* Determines the score
* \param money the pointer to the money being added
*/
void CScoreboard::Sum(CMoney* money)
{
	mScore += int(money->GetValue() * mMultiplier);
}

void CScoreboard::SetZero()
{
	mScore = 0;
	mGameTime = 0;
	mTimeSecond = 0;
	mTimeMinute = 0;
	mMultiplier = 1;
}

/**
* Update the scoreboard
* \param elapsed The time since the last update
*/
void CScoreboard::Update(double elapsed)
{
	mGameTime = mGameTime + elapsed;

	mTimeSecond = int(mGameTime);

	if (mTimeSecond >= 60)
	{
		mTimeMinute += 1;
		mGameTime = 0;
	}
}
