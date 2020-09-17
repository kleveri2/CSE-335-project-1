/**
 * \file Background.h
 *
 * \author Noah Little
 */
#pragma once
#include <string>
#include <memory>
#include "Item.h"

class CDeclaration;
class CGnome;
class CItemVisitor;

 /**
 * Class for the background object
 */
class CBackground : public CItem
{
public:

	CBackground::CBackground(std::shared_ptr<CDeclaration> declaration, double x, double y);

	/** Accept a visitor
	 * \param visitor The visitor we accept
	 * \param gnome The gnome we accept
	 */
	virtual void Accept(CItemVisitor* visitor, CGnome* gnome) {};

	/// Copy constructor (disabled)
	CBackground(const CBackground&) = delete;
};
