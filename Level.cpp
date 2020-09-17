/**
 * \file Level.cpp
 *
 * \author
 */

#include "pch.h"
#include "Level.h"
#include "Villain.h"
#include "FastTrack.h"

using namespace std;
using namespace Gdiplus;

/** Constructs a level in a game
* \param game The game involved in creation
*/
CLevel::CLevel(CGame* game) : mGame(game), mLevelName(L"")
{
	double mBoardLocX = 800;
	double mBoardLocY = 800;
}

/** Destructor*/
CLevel::~CLevel()
{
}

/** Draws the level
*  \param graphics the CChildview being drawn in
*/
void CLevel::OnDraw(Gdiplus::Graphics* graphics)
{
	for (auto item : mItems)
	{
		item->OnDraw(graphics);
	}
}

/**
* Adds an item to a level
* Used for test level and level loading
* \param item the item being added
*/
void CLevel::Add(std::shared_ptr<CItem> item)
{
	mItems.push_back(item);
}

/**
* Clear the level data.
*
* Deletes all known items in the level.
*/
void CLevel::Clear()
{
	mItems.clear();
	mDeclarations.clear();
}

/**
 * Load the level from a .level XML file.
 *
 * Opens the XML file and reads the nodes, creating items as appropriate.
 * ONLY LOAD A LEVEL ONCE, IF YOU NEED TO RESET USE CLevel::Install
 *
 * \param filename The filename of the file to load the level from.
 */
void CLevel::XmlLoad(const std::wstring& filename)
{
	mLevelName = filename;

	// We surround with a try/catch to handle errors
	try
	{
		// Open the document to read
		shared_ptr<CXmlNode> root = CXmlNode::OpenDocument(filename);

		// Once we know it is open, clear the existing data
		Clear();

		mP.SetX(root->GetAttributeDoubleValue(L"start-x", 0));
		mP.SetY(root->GetAttributeDoubleValue(L"start-y", 0));
		mWidth = root->GetAttributeDoubleValue(L"width", 0);
		mHeight = root->GetAttributeDoubleValue(L"height", 0);

		//
		// Traverse the children of the root
		// node of the XML document in memory!!!!
		//

		for (auto node : root->GetChildren())
		{
			bool declared = false;
			if (node->GetType() == NODE_ELEMENT && node->GetName() == L"declarations")
			{
				XmlDeclarations(node);
				declared = true;
			}
			if (declared = true && node->GetName() == L"items")
			{
				XmlItem(node);
			}
		}

		Install(mGame);
		mGame->GetScoreboard()->SetZero();
	}
	catch (CXmlNode::Exception ex)
	{
		AfxMessageBox(ex.Message().c_str());
	}
}

/** Reads an item in from a nod
* \param node A pointer for the item being loaded
*/
void CLevel::XmlDeclarations(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	// A pointer for the item we are loading

	for (auto child : node->GetChildren())
	{
		// We have a declaration. What type?

		shared_ptr<CDeclaration> declaration;

		if (child->GetType() == NODE_ELEMENT && child->GetName() == L"background")
		{
			declaration = make_shared<CDeclarationBackground>(child->GetAttributeValue(L"id", L""), child->GetAttributeValue(L"image", L""));
		}
		else if (child->GetType() == NODE_ELEMENT && child->GetName() == L"platform")
		{
			declaration = make_shared<CDeclarationPlatform>(child->GetAttributeValue(L"id", L""), child->GetAttributeValue(L"left-image", L""),
				child->GetAttributeValue(L"mid-image", L""), child->GetAttributeValue(L"right-image", L""));
		}
		else if (child->GetType() == NODE_ELEMENT && child->GetName() == L"wall")
		{
			declaration = make_shared<CDeclarationWall>(child->GetAttributeValue(L"id", L""), child->GetAttributeValue(L"image", L""));
		}
		else if (child->GetType() == NODE_ELEMENT && child->GetName() == L"money")
		{
			declaration = make_shared<CDeclaration>(child->GetAttributeValue(L"id", L""), child->GetAttributeValue(L"image", L""),
				child->GetAttributeDoubleValue(L"value", 0));
		}
		else if (child->GetType() == NODE_ELEMENT && child->GetName() == L"tuition-up")
		{
			declaration = make_shared<CDeclaration>(child->GetAttributeValue(L"id", L""), child->GetAttributeValue(L"image", L""));
		}
		else if (child->GetType() == NODE_ELEMENT && child->GetName() == L"door")
		{
			declaration = make_shared<CDeclaration>(child->GetAttributeValue(L"id", L""), child->GetAttributeValue(L"image", L""));
		}
		else if (child->GetType() == NODE_ELEMENT && child->GetName() == L"villain")
		{
			declaration = make_shared<CDeclaration>(child->GetAttributeValue(L"id", L""), child->GetAttributeValue(L"image", L""));
		}
		else if (child->GetType() == NODE_ELEMENT && child->GetName() == L"fasttrack")
		{
			declaration = make_shared<CDeclaration>(child->GetAttributeValue(L"id", L""), child->GetAttributeValue(L"image", L""));
		}

		if (declaration != nullptr)
			mDeclarations.push_back(declaration);
	}
}

/**
* Handle an item node.
* \param node Pointer to XML node we are handling
*/
void CLevel::XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	// A pointer for the item we are loading
	shared_ptr<CItem> item;

	for (auto child : node->GetChildren())
	{
		std::wstring itemID = child->GetAttributeValue(L"id", L"");
		std::wstring childName = child->GetName();

		for (auto declaration : mDeclarations)
		{
			std::wstring decID = L"";
			decID = declaration->GetID();

			if (itemID == decID)
			{
				if (childName == L"background")
				{
					item = make_shared<CBackground>(declaration, child->GetAttributeDoubleValue(L"x", 0), child->GetAttributeDoubleValue(L"y", 0));
				}
				else if (childName == L"platform")
				{
					item = make_shared<CPlatform>(declaration, child->GetAttributeDoubleValue(L"x", 0), child->GetAttributeDoubleValue(L"y", 0),
						child->GetAttributeDoubleValue(L"width", 0), child->GetAttributeDoubleValue(L"height", 0));
				}
				else if (childName == L"wall")
				{
					item = make_shared<CWall>(declaration, child->GetAttributeDoubleValue(L"x", 0), child->GetAttributeDoubleValue(L"y", 0),
						child->GetAttributeDoubleValue(L"width", 0), child->GetAttributeDoubleValue(L"height", 0));
				}
				else if (childName == L"money")
				{
					item = make_shared<CMoney>(declaration, child->GetAttributeDoubleValue(L"x", 0), child->GetAttributeDoubleValue(L"y", 0),
						child->GetAttributeDoubleValue(L"width", 0), child->GetAttributeDoubleValue(L"height", 0));
				}
				else if (childName == L"tuition-up")
				{
					item = make_shared<CTuitionUp>(declaration, child->GetAttributeDoubleValue(L"x", 0), child->GetAttributeDoubleValue(L"y", 0));
				}
				else if (childName == L"door")
				{
					item = make_shared<CDoor>(declaration, child->GetAttributeDoubleValue(L"x", 0), child->GetAttributeDoubleValue(L"y", 0),
						child->GetAttributeDoubleValue(L"width", 0), child->GetAttributeDoubleValue(L"height", 0));
				}
				else if (childName == L"villain")
				{
					item = make_shared<CVillain>(declaration, child->GetAttributeDoubleValue(L"x", 0), child->GetAttributeDoubleValue(L"y", 0),
						child->GetAttributeDoubleValue(L"width", 0), child->GetAttributeDoubleValue(L"height", 0));
				}
				else if (childName == L"fasttrack")
				{
					item = make_shared<CFastTrack>(declaration, child->GetAttributeDoubleValue(L"x", 0), child->GetAttributeDoubleValue(L"y", 0));
				}
				else
				{
					continue;
				}

				if (item != nullptr)
				{
					Add(item);
					break;
				}
			}
			else
				continue;
		}
	}
}

/** Handle updates for animation
* \param elapsed The time since the last update
*/
void CLevel::Update(double elapsed)
{
	for (auto item : mItems)
	{
		//item->Update(elapsed, mGame, std::vector<CItem*> toRemove);
	}
}

/** Install items from level to the game
*\param game the game being installed into
*/
void CLevel::Install(CGame* game)
{
	// Reset the game
	mGame->Clear();

	// Add to the game
	for (auto item : mItems)
	{
		game->Add(item);
	}

	game->GetGnome()->SetLocation(mP.X(), mP.Y());
}

/** Reset the game, such as when the gnome dies or a door is reached.
*\param game The game being loaded
*/
void CLevel::Reset(CGame* game)
{
	game->Reset();
}
/**Loads the next level */
void CLevel::NextLevel()
{
	if (mLevelName == L"levels/level0.xml") {
		mGame->XmlLoad(L"levels/level1.xml");
	}

	else if (mLevelName == L"levels/level1.xml") {
		mGame->XmlLoad(L"levels/level2.xml");
	}

	else if (mLevelName == L"levels/level2.xml") {
		mGame->XmlLoad(L"levels/level3.xml");
	}

	else if (mLevelName == L"levels/level3.xml")
		mGame->XmlLoad(L"levels/level3.xml");
}

/** Test the colission of an item in the level
*\param x The x location of an item
*\param y The Y location of an item
* \return a pointer to the hit item
*/
std::shared_ptr<CItem> CLevel::CollisionTest(double x, double y)
{
	for (auto item : mItems)
	{
		if (x == item->GetX() && y == item->GetY())
			return item;
	}
	return NULL;
}