/**
 * \file SolidContact.h
 *
 * \author Griffin Klevering
 *
 *
 */

#pragma once
#include "ItemVisitor.h"
 /**
 * Class for the Item visitor class
 */
class CSolidContact : public CItemVisitor
{
public:
	/** Get the number of buildings
	 * \returns Number of buildings */
	CSolid* GetSolidPointer() const { return mSolidPoint; }
	void VisitSolid(CSolid* solid, CGnome* gnome);

private:
	/// Buildings counter
	CSolid* mSolidPoint = nullptr;
};
