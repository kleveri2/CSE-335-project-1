/**
* /file Gnome.cpp
* /author Griffin Klevering
*/

#include "pch.h"
#include "Gnome.h"
#include "Game.h"

// Gnome.cpp : implementation of the Gnome Class
/** Constructs the gnome class
* \param game the game the gnome is being made in
* \param level the level the gnome is in
*/
CGnome::CGnome(CGame* game, CLevel* level) : mGame(game), mLevel(level)
{
	mImage = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/gnome.png"));
	mBoostTime = 0;
	mWalkCycle = 0;
	mLevelNumber = 0;
	mTwoSeconds = 0;
	SetLocation(0, 0);
	mReset = false;
	mStart = false;

	mWidth = mImage->GetWidth();
	mHeight = mImage->GetHeight();

	mResetTime = 0;
}

/**
 * Draws the gnome item
 * \param graphics Graphics its drawn upon
 */
void CGnome::OnDraw(Gdiplus::Graphics* graphics)
{
	if (mBoostTime <= 0)
	{
		if (mV.X() < 0)
		{
			if (mWalkCycle > .5 && (int(mV.Y()) > -5 && int(mV.Y()) < 5))
			{
				mImage = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/gnome-walk-left-1.png"));
				mWalkCycle = 0;
			}
			else
			{
				mImage = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/gnome-walk-left-2.png"));
			}
		}
		if (mV.X() > 0)
		{
			if (mWalkCycle > .5 && (int(mV.Y()) > -5 && int(mV.Y()) < 5))
			{
				mImage = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/gnome-walk-right-1.png"));
				mWalkCycle = 0;
			}
			else
			{
				mImage = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/gnome-walk-right-2.png"));
			}
		}

		if (mV.X() == 0)
		{
			mImage = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/gnome.png"));
		}
	}
	else
	{
		if (mV.X() < 0)
		{
			if (mWalkCycle > .5 && (int(mV.Y()) > -5 && int(mV.Y()) < 5))
			{
				mImage = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/gnome-walk-left-1-boost.png"));
				mWalkCycle = 0;
			}
			else
			{
				mImage = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/gnome-walk-left-2-boost.png"));
			}
		}
		if (mV.X() > 0)
		{
			if (mWalkCycle > .5 && (int(mV.Y()) > -5 && int(mV.Y()) < 5))
			{
				mImage = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/gnome-walk-right-1-boost.png"));
				mWalkCycle = 0;
			}
			else
			{
				mImage = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/gnome-walk-right-2-boost.png"));
			}
		}

		if (mV.X() == 0)
		{
			mImage = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/gnome-boost.png"));
		}
	}

	double wid = mWidth;
	double hit = mHeight;

	if (mImage->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open image");
	}
	if ((mStart == true || mGame->GetLevelComplete() == true))
	{
		mImage = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/gnome.png"));
	}
	if (mReset == true)
	{
		mImage = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/gnome-sad.png"));
	}


	graphics->DrawImage(mImage.get(),
		float(mP.X() - (wid / 2)), float(mP.Y() - (hit / 2)),
		(float)mWidth, (float)mHeight);


}

/**
* Update the gnome for movement
* \param elapsed The time since the last update
*/
void CGnome::Update(double elapsed)
{
	mWalkCycle = mWalkCycle + elapsed;
	double const Gravity = 1000;
	double const Epsilon = .1;

	//CItem::Update(elapsed);
	if (mBoostTime > 0)
	{
		mBoostTime = mBoostTime - elapsed;
	}
	if (mReset == true || mStart == true)
	{
		mTwoSeconds = mTwoSeconds + elapsed;
		mBoostTime = 0;
	}
	

	if (mReset == false && mStart == false)
	{
		// Gravity
		// Compute a new velocity with gravity added in.
		CVector newV(mV.X(), mV.Y() + Gravity * elapsed);

		// Update position
		CVector newP = mP + newV * elapsed;

		// Store old position
		CVector oldP = mP;

		// Try updating the Y location.
		mP.SetY(newP.Y());

		//When game exists, this will work
		CSolidContact visitor;
		mGame->Accept(&visitor, this);
		CSolid* collided = visitor.GetSolidPointer();

		if (collided != nullptr)
		{
			if (mV.Y() > Gravity* elapsed)
			{
				// We are falling, stop at the collision point
				newP.SetY(oldP.Y() - Epsilon);
				newV.SetY(0);
			}

			else if (mV.Y() < -(Gravity * elapsed))
			{
				// We are rising, stop at the collision point
				newP.SetY(oldP.Y() + Epsilon);
				newV.SetY(0);
			}

		}

		//
		// Try updating the X location
		//
		SetLocation(newP.X(), oldP.Y());
		CSolidContact visitor1;
		mGame->Accept(&visitor1, this);
		CSolid* collided2 = visitor1.GetSolidPointer();

		if (collided2 != nullptr)
		{
			if (mV.X() > 0 && (newP.X() - mWidth / 2) < (collided2->GetX() - (collided2->GetWidth() / 2) + (collided2->GetImageWidth() / 2)))
			{
				// We are on the left, stop at the collision point
				newP.SetX(oldP.X() - Epsilon);

			}

			else if (mV.X() < 0 && (newP.X() + mWidth / 2) > (collided2->GetX() + (collided2->GetWidth() / 2) - (collided2->GetImageWidth() / 2)))
			{
				// We are on the right, stop at the collision point
				newP.SetX(oldP.X() + Epsilon);
			}

		}

		SetLocation(newP.X(), newP.Y());

		// Update the velocity and position
		mV = newV;

		CItemContact visitor3;
		mGame->Accept(&visitor3, this);
		auto collided3 = visitor3.GetItemPointer();

		if (collided3 != nullptr)
		{
			collided3->UpdateGame(mGame);

		}

		//Put one for door here too.
		CDoorContact visitor4;
		mGame->Accept(&visitor4, this);
		CDoor* collided4 = visitor4.GetDoorPointer();

		if (collided4 != nullptr)
		{
			mGame->SetLevelComplete(true);
			
		}

		if (mP.Y() > double(1024 + mHeight / 2))
		{
			mReset = true;
		}

	}

	if (mTwoSeconds > 2)
	{
		mTwoSeconds = 0;
		mReset = false;
		mStart = false;
	}

}
/** This makes the gnome fall when he's hit
* \param elapsed the time elapsed since the last update
*/
void CGnome::GameOverFall(double elapsed)
{
	mResetTime = mResetTime + elapsed;
	double newy = mP.Y() + 500 * elapsed;
	SetLocation(mP.X(), newy);
	if (mResetTime > 2)
	{
		mGame->Reset();
		mReset = false;
		mStart = true;
		mResetTime = 0;
	}
}