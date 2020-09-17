/**
 * \file SolidContact.cpp
 *
 * \author Griffin Klevering
 *
 *
 */

#include "pch.h"
#include "SolidContact.h"
#include "Gnome.h"

 /** Visit a CSolid object
 * \param item Solid we are visiting
 * \param gnome The gnome we're visiting
 */
void CSolidContact::VisitSolid(CSolid* item, CGnome* gnome)
{

	auto itemX = item->GetX();
	auto itemY = item->GetY();
	auto itemWidth = item->GetWidth();
	auto itemHeight = item->GetHeight();

	auto itemImageWidth = item->GetImageWidth();
	auto itemImageHeight = item->GetImageHeight();

	auto gnomeX = gnome->GetX();
	auto gnomeY = gnome->GetY();
	auto gnomeWidth = gnome->GetWidth();
	auto gnomeHeight = gnome->GetHeight();

	// Border for the item
	auto itemLeft = itemX - (itemWidth / 2) + (itemImageWidth / 2);
	auto itemRight = itemX + (itemWidth / 2) - (itemImageWidth / 2);
	auto itemTop = itemY - (itemHeight / 2);
	auto itemBottom = itemY + (itemHeight / 2);

	// For us
	auto ourLeft = gnomeX - (gnomeWidth / 2);
	auto ourRight = gnomeX + (gnomeWidth / 2);
	auto ourTop = gnomeY - (gnomeHeight / 2);
	auto ourBottom = gnomeY + (gnomeHeight / 2);

	// Test for all of the non-collision cases,
	// cases where there is a gap between the two items
	if (ourRight <= itemLeft ||  // Completely to the left
		ourLeft >= itemRight ||  // Completely to the right
		ourTop >= itemBottom ||  // Completely below
		ourBottom <= itemTop)    // Completely above
	{
		mSolidPoint = mSolidPoint;
	}
	else
	{
		mSolidPoint = item;
	}
}