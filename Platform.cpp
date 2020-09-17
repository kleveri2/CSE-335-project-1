/**
 * \file Platform.cpp
 *
 * \author Junnan Fu
 */
#include "pch.h"
#include "Platform.h"

CPlatform::CPlatform(std::shared_ptr<CDeclaration> declaration, double x, double y, double width, double height) : CSolid(declaration, x, y)
{
	SetWidth(width);
	SetHeight(height);
}