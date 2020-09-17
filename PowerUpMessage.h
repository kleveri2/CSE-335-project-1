#pragma once
#include "Item.h"
#include <string>
#include <sstream>

/**
 * Establishes different game messages based on object hit
 */
class CPowerUpMessage : public CItem
{
public:

	CPowerUpMessage(std::wstring message, double x, double y);

	~CPowerUpMessage();

	virtual void OnDraw(Gdiplus::Graphics* graphics);
	virtual void Update(double elapsed, std::vector<CItem*>* toRemove);
	
	/** Accept a visitor
	 * \param visitor The visitor we accept
	 * \param gnome The gnome we accept
	 */
	void Accept(CItemVisitor* visitor, CGnome* gnome) {};

private:
	///Location of the item
	CVector mP;
	///The message being printed
	std::wstring mMessage;
	///The time the message has existed
	double mTime;
	///The size of the message font
	int mFontSize;
};