/**
 * \file Game.h
 *
 * \author Noah Little
 *
 *
 */

#pragma once
#include "Gnome.h"
#include "Level.h"
#include "XmlNode.h"
#include "Scoreboard.h"

using namespace std;
using namespace Gdiplus;

/**
* Class for the game object
*/
class CGame
{
public:
	CGame();
	~CGame();

	void OnDraw(Gdiplus::Graphics* graphics, int height, int width);
	void Update(double elapsed);
	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	void XmlLoad(const std::wstring& filename);
	void RemoveItem(CItem* itemDelete);

	/** Sets the gnome's location
	* \param x the x coordinate
	* \param y the y coordinate
	*/
	void SetGnomeLocation(int x, int y) { mGnome->SetLocation(x, y); }
	void Add(std::shared_ptr<CItem> item);
	void Clear();
	void Reset();


	/** Sets the level to an indicated number
	* \param number the level being set to
	*/
	void SetLevelNumber(double number) {};

	/** Gets the gnome
	* \return mGnome the gnome in the game
	*/
	shared_ptr<CGnome> GetGnome() { return mGnome; };

	void Accept(CItemVisitor* visitor, CGnome* gnome);

	/** Gets the scoreboard
	* \return the scoreboard connected to the game
	*/
	shared_ptr<CScoreboard> GetScoreboard() { return mScoreboard; }

	/** Gets the name of the current level's xml
	* \return A string of the name
	*/
	std::wstring GetLevelName() { return mLevel->GetLevelName(); }

	/** Gets the level's current status
	* \return If the level is complete
	*/
	bool GetLevelComplete() {return mLevelComplete;}
	/** Sets the level's current status
	* \param m The new status of the level
	*/
	void SetLevelComplete(bool m) { mLevelComplete = m; }

private:

	///List of items in a game
	std::vector<std::shared_ptr<CItem>> mItems;

	/// The gnome in the game
	shared_ptr<CGnome> mGnome;

	/// The scoreboard the game uses
	shared_ptr<CScoreboard> mScoreboard;

	///The level being played
	shared_ptr<CLevel> mLevel;

	/// The initial X speed of the gnome
	double mSpeedX;

	///Initial Y speed of the gnome
	double mSpeedY;

	/// Game Complete
	bool mLevelComplete;

	/// Time Variable
	double mTime;
};
