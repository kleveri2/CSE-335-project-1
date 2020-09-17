// CSE335Project1.h : main header file for the CSE335Project1 application
//
#pragma once

#ifndef __AFXWIN_H__
#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols

/** CCSE335Project1App:
  * See CSE335Project1.cpp for the implementation of this class
  */
class CCSE335Project1App : public CWinApp
{
public:
	CCSE335Project1App() noexcept;

	// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

private:
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken = 0;
};

extern CCSE335Project1App theApp;
