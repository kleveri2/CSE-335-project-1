// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "ChildView.h"
#include "DoubleBufferDC.h"

using namespace std;
using namespace Gdiplus;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
using namespace Gdiplus;
// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}

BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_COMMAND(ID_FILE_LOAD, &CChildView::OnFileLoad)
	ON_WM_TIMER()
	ON_COMMAND(ID_LEVELS_LEVEL0, &CChildView::OnEnterLevel0)
	ON_COMMAND(ID_LEVELS_LEVEL1, &CChildView::OnEnterLevel1)
	ON_COMMAND(ID_LEVELS_LEVEL2, &CChildView::OnEnterLevel2)
	ON_COMMAND(ID_LEVELS_LEVEL3, &CChildView::OnEnterLevel3)
END_MESSAGE_MAP()

// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), nullptr);

	return TRUE;
}

/** Paints the window
*/
void CChildView::OnPaint()
{
	CPaintDC paintDC(this);
	CDoubleBufferDC dc(&paintDC); // device context for painting
	Graphics graphics(dc.m_hDC);

	CRect rect;

	GetClientRect(&rect);

	mGame.OnDraw(&graphics, rect.Width(), rect.Height());

	if (mFirstDraw)
	{
		mFirstDraw = false;
		
		SetTimer(1, FrameDuration, nullptr);

		/*
		* Initialize the elapsed time system
		*/
		LARGE_INTEGER time, freq;
		QueryPerformanceCounter(&time);
		QueryPerformanceFrequency(&freq);

		mLastTime = time.QuadPart;
		mTimeFreq = double(freq.QuadPart);
	}

	/*
	* Compute the elapsed time since the last draw
	*/
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	long long diff = time.QuadPart - mLastTime;
	double elapsed = double(diff) / mTimeFreq;
	mLastTime = time.QuadPart;

	//
	// Prevent tunnelling
	//
	while (elapsed > MaxElapsed)
	{
		mGame.Update(MaxElapsed);

		elapsed -= MaxElapsed;
	}

	// Consume any remaining time
	if (elapsed > 0)
	{
		mGame.Update(elapsed);
	}
}

/**
 * Erase the background
 *
 * This is disabled to eliminate flicker
 * \param pDC Device context
 * \returns FALSE
 */
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	return FALSE;
}

/**
 * Handle a key-down message
 * \param nChar The character key code.
 * \param nRepCnt How many times it has been repeated.
 * \param nFlags Additional keyboard state information.
 */
void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	mGame.OnKeyDown(nChar, nRepCnt, nFlags);

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}

/**
 * Handle a key-up message
 * \param nChar The character key code.
 * \param nRepCnt How many times it has been repeated.
 * \param nFlags Additional keyboard state information.
 */
void CChildView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	mGame.OnKeyUp(nChar, nRepCnt, nFlags);

	CWnd::OnKeyUp(nChar, nRepCnt, nFlags);
}

/**
 * This function is called when a Load menu item is selected.
 *
 * It loads the game from a level file.
 */
void CChildView::OnFileLoad()
{
	CFileDialog dlg(true,  // true = Open dialog box
		L".xml",           // Default file extension
		nullptr,            // Default file name (none)
		0,    // Flags
		L"Level Files (*.xml)|*.xml|All Files (*.*)|*.*||");  // Filter
	if (dlg.DoModal() != IDOK)
		return;

	wstring filename = dlg.GetPathName();

	mGame.XmlLoad(filename);
	Invalidate();
}

/**
* Handle timer events
* \param nIDEvent The timer event ID
*/
void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	Invalidate();
	CWnd::OnTimer(nIDEvent);
}

/// Level load up X location
const int InitialX = 0;

/// Level load up Y location
const int InitialY = 200;

/** Enters the test level
*/
void CChildView::OnEnterLevel0()
{
	mGame.XmlLoad(L"levels/level0.xml");
}

/** Enters level 1
*/
void CChildView::OnEnterLevel1()
{
	mGame.XmlLoad(L"levels/level1.xml");
}

/** Enters level 2
*/
void CChildView::OnEnterLevel2()
{
	mGame.XmlLoad(L"levels/level2.xml");
}

/** Enters level 3
*/
void CChildView::OnEnterLevel3()
{
	mGame.XmlLoad(L"levels/level3.xml");
}