/**
 * \file ItemContact.h
 *
 * \author Griffin Klevering
 *
 *
 */

#pragma once
#include "ItemVisitor.h"

 /**
 * Class for the Contact visitor
 */
class CItemContact : public CItemVisitor
{
public:
	/** Get the item pointer
	 * \returns the pointer to an item or nullptr */
	CItem* GetItemPointer() const { return mItemPoint; }
	void VisitItem(CItem* item, CGnome* gnome);
private:
	/// Pointer to the hit item
	CItem* mItemPoint = nullptr;
};
