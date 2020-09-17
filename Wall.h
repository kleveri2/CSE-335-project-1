/**
 * \file Wall.h
 *
 * \author Junnan Fu
 */
#include "Item.h"
#include "Solid.h"

using namespace std;
using namespace Gdiplus;
/**
* Class for the wall object
*/
class CWall : public CSolid
{
public:
	/** Constructor
* \param declaration The solid declaration being used
* \param x The x coordinate of the solid
* \param y The y coordinate of the solid
* \param width The width of the image
* \param height The height of the image
*/
	CWall(std::shared_ptr<CDeclaration> declaration, double x, double y, double width, double height);

private:
	/// The image of the wall
	std::unique_ptr<Gdiplus::Bitmap> mImage;
};