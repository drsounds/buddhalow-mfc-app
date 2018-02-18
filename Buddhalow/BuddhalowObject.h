#include "stdafx.h"

#pragma once
class BuddhalowObject;
typedef CList<BuddhalowObject *> BuddhalowObjectList;
class BuddhalowObject : public CObject
{
public:
	CString identifier; // Identifier of the object
	CRect bounds; // Bounds
	BuddhalowObjectList *objects; // Child objects
public:
	BuddhalowObject();
	BuddhalowObject(CRect bounds);
	~BuddhalowObject();
	virtual BuddhalowObjectList *GetObjectsAtPosition(const CPoint&);
	virtual void Add(BuddhalowObject *object);
	virtual void Draw(CDC *pDC, CView *view);
	virtual void AssertValid() const;
	virtual void Serialize(CArchive& ar);
	virtual void Dump(CDumpContext& dc) const;
};

