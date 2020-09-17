/**
 * \file Solid.h
 *
 * \author Junnan Fu
 */
#pragma once
#include "Item.h"
/**
* Base class for the solid objects
*/
class CSolid : public CItem
{
public:

	CSolid(std::shared_ptr<CDeclaration> declaration, double x, double y);

	~CSolid();

	///  Default constructor (disabled)
	CSolid() = delete;

	///  Copy constructor (disabled)
	CSolid(const CSolid&) = delete;

	/** Accept a visitor
	 * \param visitor The visitor we accept
	 * \param gnome The gnome we accept
	 */
	virtual void Accept(CItemVisitor* visitor, CGnome* gnome) override { visitor->VisitSolid(this, gnome); }
};
