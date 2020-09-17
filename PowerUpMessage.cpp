#include "pch.h"
#include "PowerUpMessage.h"

/** Constructs a message in a game
* \param message the message the powerup provides
* \param x The x location
* \param y The y location
*/
CPowerUpMessage::CPowerUpMessage(std::wstring message, double x, double y)
{
	mP.SetX(x);
	mP.SetY(y);
	mTime = 0;
	mMessage = message;
	mFontSize = 15;
}

/** Destructor*/
CPowerUpMessage::~CPowerUpMessage()
{
}

/**
* Draw the message on the screen
* \param graphics The screen the message is being drawn upon
*/
void CPowerUpMessage::OnDraw(Gdiplus::Graphics* graphics)
{

	wstringstream mMessageDisplay;
	mMessageDisplay << mMessage;

	/// Sets Font
	FontFamily fontFamily(L"Arial");

	Gdiplus::Font font(&fontFamily, mFontSize);

	mFontSize += 3;

	/// Displays Scoreboard

	SolidBrush green(Color(BYTE(40), BYTE(2000), BYTE(40)));
	graphics->DrawString(mMessageDisplay.str().c_str(), -1, &font, PointF(Gdiplus::REAL(mP.X() - mFontSize), Gdiplus::REAL(mP.Y())), NULL, &green);
}

/**
* Updates the position of the message
*\param elapsed Time since last message
* \param toRemove a vector of items being removed from the main list
*/
void CPowerUpMessage::Update(double elapsed, std::vector<CItem*>* toRemove)
{
	mTime += elapsed;

	mP.SetY(mP.Y() - 4);

	if (mP.Y() < 0)
	{
		toRemove->push_back(this);
	}
}


