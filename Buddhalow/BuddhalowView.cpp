
// BuddhalowView.cpp : implementation of the CBuddhalowView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Buddhalow.h"
#endif

#include "BuddhalowDoc.h"
#include "BuddhalowView.h"
#include "BuddhalowObject.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBuddhalowView

IMPLEMENT_DYNCREATE(CBuddhalowView, CView)

BEGIN_MESSAGE_MAP(CBuddhalowView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_TOOL_POINTER, &CBuddhalowView::OnPointerSelected)
	ON_COMMAND(ID_TOOL_RECTANGLE, &CBuddhalowView::OnRectangleSelected)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CBuddhalowView construction/destruction

void CBuddhalowView::OnPointerSelected() {
	this->currentTool = 0;
}
void CBuddhalowView::OnRectangleSelected() {
	this->currentTool = TOOL_CREATE_OBJECT;
}

CBuddhalowView::CBuddhalowView()
{
	// TODO: add construction code here
	this->selection = NULL;
}

CBuddhalowView::~CBuddhalowView()
{
}

BOOL CBuddhalowView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CBuddhalowView drawing

void CBuddhalowView::OnDraw(CDC* pDC)
{
	CBuddhalowDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// Draw all objects
	pDoc->object->Draw(pDC);

	// Draw selection
	if (this->selection != nullptr) {
		RECT rect = (CRect)*this->selection;
		
		pDC->DrawFocusRect(&rect);
		
	}
	// TODO: add draw code for native data here
}


// CBuddhalowView printing

BOOL CBuddhalowView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBuddhalowView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBuddhalowView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CBuddhalowView diagnostics

#ifdef _DEBUG
void CBuddhalowView::AssertValid() const
{
	CView::AssertValid();
}

void CBuddhalowView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBuddhalowDoc* CBuddhalowView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBuddhalowDoc)));
	return (CBuddhalowDoc*)m_pDocument;
}
#endif //_DEBUG


// CBuddhalowView message handlers


void CBuddhalowView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	this->selection = new CRect(point.x, point.y, 0, 0);
	
	CView::OnLButtonDown(nFlags, point);
}


void CBuddhalowView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (this->selection != NULL) {
		this->selection->right = point.x;
		this->selection->bottom = point.y;
	
	}
	

	this->RedrawWindow();
	CView::OnMouseMove(nFlags, point);
}


void CBuddhalowView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (this->currentTool == TOOL_CREATE_OBJECT) {
		// If currentTool is create object, create a new BuddhalowObject
		BuddhalowObject *object = new BuddhalowObject((CRect)this->selection);
		BuddhalowObject *rootObject = this->GetDocument()->object;
		rootObject->Add(object);
	}
	this->selection = NULL;
	this->RedrawWindow();
	
	CView::OnLButtonUp(nFlags, point);
}
