// ChildView.h : interface of the CChildView class
//

#pragma once
#include "CSE335Project1.h"
#include "Game.h"

/// Frame duration in milliseconds
const int FrameDuration = 16;

/// Maximum amount of time to allow for elapsed
const double MaxElapsed = 0.005;

class CGame;

/**  The child window the program draws in. */

class CChildView : public CWnd
{
	// Construction
public:
	CChildView();

	// Attributes
private:

	/// The game
	CGame mGame;

	/// True until the first time we draw
	bool mFirstDraw = true;

	long long mLastTime = 0;    ///< Last time we read the timer
	double mTimeFreq = 0;       ///< Rate the timer updates

// Operations
public:

	// Overrides
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnFileLoad();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnEnterLevel0();
	afx_msg void OnEnterLevel1();
	afx_msg void OnEnterLevel2();
	afx_msg void OnEnterLevel3();
};
