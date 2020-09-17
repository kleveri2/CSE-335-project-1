/**
 * \file ItemContact.cpp
 *
 * \author Griffin Klevering
 *
 *
 */

#include "pch.h"
#include "DoorContact.h"
#include "Gnome.h"

 /** Visit a CDoor object
 * \param door door we are visiting
 * \param gnome the gnome we're visiting
 */
void CDoorContact::VisitDoor(CDoor* door, CGnome* gnome)
{
	// Collision distance for the door in pixels
	const double CollisionDistance = 20;
	// Collision for door is different
	double dx = door->GetX() - gnome->GetX();
	double dy = door->GetY() - gnome->GetY();
	double distance = sqrt(dx * dx + dy * dy);
	if (distance < CollisionDistance)
	{
		mDoorPoint = door;
	}

	mDoorPoint = mDoorPoint;
}