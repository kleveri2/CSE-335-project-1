/**
 * \file ItemVisitor.h
 *
 * \author Griffin Klevering
 *
 * Item visitor base class.
 */

#pragma once

 // Forward references to all things that the visitor will come in contact with
 // Add more when more classes exist

class CGnome;
class CSolid;

class CVillain;
class CPowerUp;
class CItem;
class CMoney;
class CTuitionUp;
class CDoor;

/** Item visitor base class */
class CItemVisitor
{
public:

	//virtual ~CItemVisitor() {}

	/** Visit a CItemVisitor object
	 * \param solid solid we are visiting
	 * \param gnome The gnome we're visiting with
	 */
	virtual void VisitSolid(CSolid* solid, CGnome* gnome) {}

	/** Visit a CItemVisitor object
	 * \param item item we are visiting
	 * \param gnome The gnome we're visiting with
	 */
	virtual void VisitItem(CItem* item, CGnome* gnome) {}

	/** Visit a CItemVisitor object
	 * \param item item we are visiting
	 * \param gnome The gnome we're visiting with
	 */
	virtual void VisitMoney(CMoney* item, CGnome* gnome) {}

	/** Visit a CItemVisitor object
	 * \param item item we are visiting
	 * \param gnome The gnome we're visiting with
	 */
	virtual void VisitTuitionUp(CTuitionUp* item, CGnome* gnome) {}

	/** Visit a CDoor object
	* \param door door we are visiting
	* \param gnome the gnome we're visiting with
	*/
	virtual void VisitDoor(CDoor* door, CGnome* gnome) {}
};
