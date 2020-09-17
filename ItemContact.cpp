/**
 * \file ItemContact.cpp
 *
 * \author Griffin Klevering
 *
 *
 */

#include "pch.h"
#include "ItemContact.h"
#include "Gnome.h"

 /** Visit a CItem object
 * \param item Item we are visiting
 * \param gnome the gnome we're visiting
 */
void CItemContact::VisitItem(CItem* item, CGnome* gnome)
{
	// Border for the item
	auto itemLeft = item->GetX() - (item->GetImageWidth() / 2);
	auto itemRight = item->GetX() + (item->GetImageWidth() / 2);
	auto itemTop = item->GetY() - (item->GetImageHeight() / 2);
	auto itemBottom = item->GetY() + (item->GetImageHeight() / 2);

	// For us
	auto ourLeft = gnome->GetX() - (gnome->GetWidth() / 2);
	auto ourRight = gnome->GetX() + (gnome->GetWidth() / 2);
	auto ourTop = gnome->GetY() - (gnome->GetHeight() / 2);
	auto ourBottom = gnome->GetY() + (gnome->GetHeight() / 2);

	// Test for all of the non-collision cases,
	// cases where there is a gap between the two items
	if (ourRight < itemLeft ||  // Completely to the left
		ourLeft > itemRight ||  // Completely to the right
		ourTop > itemBottom ||  // Completely below
		ourBottom < itemTop)    // Completely above
	{
		mItemPoint = mItemPoint;
	}
	else
	{
		mItemPoint = item;
	}
}