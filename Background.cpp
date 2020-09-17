#include "pch.h"
#include "Background.h"

using namespace std;
using namespace Gdiplus;

/** Constructor for the background
* \param declaration The declaration being loaded from
* \param x X coordinate
* \param y Y coordinate
*/
CBackground::CBackground(std::shared_ptr<CDeclaration> declaration, double x, double y) : CItem(declaration, x, y)
{
}