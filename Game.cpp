/**
 * \file Game.cpp
 *
 * \author Yash Anandakumar
 */
#include "pch.h"
#include "Game.h"

 /// Game area height in virtual pixels
const static int Height = 1024;

/**
*  Constructor
*/
CGame::CGame()
{
	mLevel = make_shared<CLevel>(this);
	mGnome = make_shared<CGnome>(this, mLevel.get());
	mScoreboard = make_shared<CScoreboard>(this);

	mSpeedX = 500;
	mSpeedY = 800;
	mTime = 0;
	mLevelComplete = false;
	XmlLoad(L"levels/level1.xml");
}

/**
*  Destructor
*/
CGame::~CGame()
{
}

/**
 * Draw the game area
 * \param graphics The GDI+ graphics context to draw on
 * \param width Width of the client window
 * \param height Height of the client window
 */
void CGame::OnDraw(Gdiplus::Graphics* graphics, int width, int height)
{
	//
	// Automatic Scaling
	//
	float mScale = float(height) / float(Height);
	graphics->ScaleTransform(mScale, mScale);

	// Determine the virtual width
	float virtualWidth = (float)width / mScale;

	// Compute the amount to scroll in the X dimension
	float xOffset = (float)-mGnome->GetX() + virtualWidth / 2.0f;

	//Translates by xOffset, at the middle of the screen
	auto save = graphics->Save();

	graphics->TranslateTransform(xOffset, 0);

	// Put draw functions here
	for (auto item : mItems)
		item->OnDraw(graphics);
	mGnome->OnDraw(graphics);

	graphics->Restore(save);

	mScoreboard->OnDraw(graphics, int(virtualWidth), height);
}

/** Updates all items in a game
* \param elapsed the time since the last update
*/
void CGame::Update(double elapsed)
{
	if (mGnome->GetReset() == false && mLevelComplete == false)
	{

		mGnome->Update(elapsed);
		std::vector<CItem*> toRemove;
		for (auto item : mItems)
			item->Update(elapsed, &toRemove);

		for (auto item : toRemove)
		{
			RemoveItem(item);
		}
	}
	else if (mGnome->GetReset() == true)
	{
		mGnome->GameOverFall(elapsed);
	}
	
	else if (mLevelComplete == true)
	{
		mTime += elapsed;

		if (mTime > 2)
		{
			mLevelComplete = false;
			mTime = 0;
			mLevel->NextLevel();
		}
	}
	
	mScoreboard->Update(elapsed);
}

/**
 * Handle a key-down message
 * \param nChar The character key code.
 * \param nRepCnt How many times it has been repeated.
 * \param nFlags Additional keyboard state information.
 */
void CGame::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	///Add message handler code here
	switch (nChar)
	{
	case VK_RIGHT:
		if (mGnome->GetBoostTime() > 0)
		{
			mGnome->SetXVelocity(mSpeedX*1.25);
		}
		else {
			mGnome->SetXVelocity(mSpeedX);
		}
		break;

	case VK_LEFT:
		if (mGnome->GetBoostTime() > 0)
		{
			mGnome->SetXVelocity(-mSpeedX * 1.25);
		}
		else {
			mGnome->SetXVelocity(-mSpeedX);
		}
		break;

	case VK_SPACE:
		if (mGnome->GetYVelocity() < 15 && mGnome->GetYVelocity() > -15)
		{
			mGnome->SetYVelocity(-mSpeedY);
		}
		break;
	}
}

/**
 * Handle a key-up message
 * \param nChar The character key code.
 * \param nRepCnt How many times it has been repeated.
 * \param nFlags Additional keyboard state information.
 */
void CGame::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch (nChar)
	{
	case VK_RIGHT:
	case VK_LEFT:
		mGnome->SetXVelocity(0);
		break;
	}
}

/** Load a game from an xml node
* \param filename The name of the file being loaded
*/
void CGame::XmlLoad(const std::wstring& filename)
{
	mLevel->XmlLoad(filename);
	mGnome->SetStart();
	mGnome->SetLocation(mLevel->GetX(), mLevel->GetY());
}

/** Accept a visitor
	 * \param visitor The visitor we accept
	 * \param gnome The gnome we accept
	 */
void CGame::Accept(CItemVisitor* visitor, CGnome* gnome)
{
	for (auto item : mItems)
	{
		item->Accept(visitor, gnome);
	}
}


/** Adds item to list of items from level
* \param item Item to add to list
*/
void CGame::Add(std::shared_ptr<CItem> item)
{
	mItems.push_back(item);
}

/** Clear a level of items
*/
void CGame::Clear()
{
	mItems.clear();
}

/** Reset a level, for example when mGnome dies or a door is reached
*/
void CGame::Reset()
{
	mLevel->Install(this);
	for (auto item : mItems)
	{
		item->ResetItem();
	}
	mScoreboard->SetZero();
}

/** Remove an item from the list of items
* \param itemDelete Item to delete from list
*/
void CGame::RemoveItem(CItem* itemDelete)
{	
	int index = 0;
	for (auto item : mItems)
	{
		if (itemDelete == item.get())
		{
			mItems.erase(mItems.begin() + index);
		}

		index++;
	}
}