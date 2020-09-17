/**
 * \file Wall.cpp
 *
 * \author Junnan Fu
 */
#include "pch.h"
#include "Wall.h"

CWall::CWall(std::shared_ptr<CDeclaration> declaration, double x, double y, double width, double height) : CSolid(declaration, x, y)
{
	SetWidth(width);
	SetHeight(height);
}