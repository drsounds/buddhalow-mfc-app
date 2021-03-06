
// BuddhalowDoc.h : interface of the CBuddhalowDoc class
//

#include "BuddhalowObject.h"
#pragma once

class CBuddhalowDoc : public CDocument
{
protected: // create from serialization only
	CBuddhalowDoc();
	DECLARE_DYNCREATE(CBuddhalowDoc)

// Attributes
public:
	BuddhalowObject *object;
// Operations
public:
// Overrides
public:
	virtual void GetObjectById(CString id);
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CBuddhalowDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
	
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
