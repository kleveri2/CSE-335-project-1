#include "pch.h"
#include "LevelMessage.h"

/** Constructs a message in a game
* \param value the value of the money object
* \param x The x location
* \param y The y location
*/
CLevelMessage::CLevelMessage(int value, double x, double y)
{
	mP.SetX(x);
	mP.SetY(y);
	mValue = value;
	mTime = 0;
}

/** Destructor*/
CLevelMessage::~CLevelMessage()
{
}

/**
* Draws Message per item hit
* \param graphics the frame being drawn in
*/
void CLevelMessage::OnDraw(Gdiplus::Graphics* graphics)
{
	wstringstream mScoreDisplay;
	mScoreDisplay << L"$" << mValue;

	wstringstream mTimeDisplay;
	if(mTime < 0.5)
	{
		/// Sets Font
		FontFamily fontFamily(L"Arial");
		Gdiplus::Font font(&fontFamily, 18);

		/// Displays Scoreboard

		SolidBrush green(Color(BYTE(40), BYTE(2000), BYTE(40)));
		graphics->DrawString(mScoreDisplay.str().c_str(), -1, &font, PointF(Gdiplus::REAL(mP.X()), Gdiplus::REAL(mP.Y())), NULL, &green);
	}
}

/** Updates the message position
* \param elapsed how long since the last update
* \param toRemove a vector of items to be removed fomr the master list
*/
void CLevelMessage::Update(double elapsed, std::vector<CItem*>* toRemove)
{
	mTime += elapsed;

	mP.SetY(mP.Y() - 1);
	if (mTime > .5)
	{
		toRemove->push_back(this);
	}
}


