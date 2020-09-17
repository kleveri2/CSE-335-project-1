/**
 * \file Door.h
 *
 * \author Junnan Fu
 */
#pragma once
#include "Item.h"

 /**
 * Class for the Door object
 */
class CDoor : public CItem
{
public:

	CDoor::CDoor(std::shared_ptr<CDeclaration> declaration, double x, double y, double width, double height);
	~CDoor();

	///  Default constructor (disabled)
	CDoor() = delete;

	///  Copy constructor (disabled)
	CDoor(const CDoor&) = delete;

	/** Accept a visitor
	 * \param visitor The visitor we accept
	 * \param gnome The gnome we accept
	 */
	virtual void Accept(CItemVisitor* visitor, CGnome* gnome) override { visitor->VisitDoor(this, gnome); }

private:
	///The image of the door
	std::unique_ptr<Gdiplus::Bitmap> mImage;
};
