
// BuddhalowView.h : interface of the CBuddhalowView class
//


#pragma once
#define TOOL_CREATE_OBJECT 0x28
class BuddhalowObject;
class CBuddhalowDoc;
#include "BuddhalowObject.h"

class CBuddhalowView : public CView
{
protected: // create from serialization only
	CBuddhalowView();
	DECLARE_DYNCREATE(CBuddhalowView)

// Attributes
public:
	CBuddhalowDoc* GetDocument() const;
	CRect *selection;
	BuddhalowObjectList *selectedObjects;
	CRect *moveBounds;
	int currentTool;
// Operations
public:

// Overrides
public:
	virtual void OnPointerSelected();
	virtual void OnRectangleSelected();
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual bool IsObjectSelected(BuddhalowObject *object);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CBuddhalowView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in BuddhalowView.cpp
inline CBuddhalowDoc* CBuddhalowView::GetDocument() const
   { return reinterpret_cast<CBuddhalowDoc*>(m_pDocument); }
#endif

