
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Buddhalow.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}
int CMainFrame::LoadToolBar(int resId, CToolBar& toolBar, int flags, bool flat) {
	int cflags = 0;
	flags |= WS_CHILD | WS_VISIBLE | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC;
	if (flat) {
		cflags = TBSTYLE_FLAT;
	}
	if (!toolBar.CreateEx(this, cflags, flags) ||
		!toolBar.LoadToolBar(resId))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	toolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&toolBar);
	if (!flat) {
		RECT *rect = (RECT *)malloc(sizeof(RECT));
		rect->left = 6;
		rect->right = 6;
		rect->top = 4;
		rect->bottom = 4;
		toolBar.SetBorders(rect);
	}
	return 1;
}
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!LoadToolBar(IDR_MAINFRAME, m_wndToolBar, CBRS_TOP, false))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	LoadToolBar(IDR_TOOLBAR1, m_wndBuddhalowToolBar, CBRS_LEFT, false);
	m_wndBuddhalowToolBar.SetButtonStyle(0, BTNS_CHECKGROUP);
	m_wndBuddhalowToolBar.SetButtonStyle(1, BTNS_CHECKGROUP);

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers

