/**
 * \file DoorContact.h
 *
 * \author Griffin Klevering
 *
 *
 */

#pragma once
#include "pch.h"
#include "ItemVisitor.h"

 /**
 * Class for the Door Contact visitor
 */
class CDoorContact : public CItemVisitor
{
public:
	/** Get the pointer to the door
 * \returns pointer to the door */
	CDoor* GetDoorPointer() const { return mDoorPoint; }
	void VisitDoor(CDoor* door, CGnome* gnome);
private:
	/// Pointer to the hit item
	CDoor* mDoorPoint = nullptr;
};
