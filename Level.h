#pragma once

#include <vector>
#include <memory>

#include "Item.h"
#include "Background.h"
#include "ItemVisitor.h"
#include "XmlNode.h"
#include "Solid.h"
#include "Vector.h"
#include "Platform.h"
#include "Wall.h"
#include "TuitionUp.h"
#include "Declaration.h"
#include "DeclarationBackground.h"
#include "DeclarationPlatform.h"
#include "DeclarationWall.h"

using namespace xmlnode;
using namespace std;

//class CItem;
class CGame;

/**
* Class for the level object
*/
class CLevel
{
public:

	CLevel(CGame* game);
	~CLevel();

	void OnDraw(Gdiplus::Graphics* graphics);

	///Add item to level
	void Add(std::shared_ptr<CItem> item);
	void Reset(CGame* game);
	void NextLevel();

	//void Accept(CItemVisitor* visitor, CGnome *gnome);
	void Update(double elapsed);

	void Clear();
	void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);
	void XmlDeclarations(const std::shared_ptr<xmlnode::CXmlNode>& node);
	void XmlLoad(const std::wstring& filename);

	std::shared_ptr<CItem> CollisionTest(double x, double y);

	/** Get the starting x location
	* \return the starting x location
	*/
	double GetX() { return mP.X(); }

	/** Get the starting y location
	* \return the starting y location
	*/
	double GetY() { return mP.Y(); }

	void Install(CGame* game);
	
	/** Gets a string of the level name
	\returns The name of the level
	*/
	std::wstring GetLevelName() { return mLevelName; }

private:

	/// x coordinates for message
	double mBoardLocX;
	/// y coordinate for message
	double mBoardLocY;

	///List of items in a level
	std::vector<std::shared_ptr<CItem>> mItems;

	///The game being played
	CGame* mGame;

	/// Height of level
	double mHeight = 0;
	///The Width of level
	double mWidth = 0;

	///Starting location
	CVector mP;

	///List of declarations
	std::vector<std::shared_ptr<CDeclaration>> mDeclarations;

	///Filename of the level
	std::wstring mLevelName;
};