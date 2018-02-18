#pragma once
#include "stdafx.h"
class BuddhalowObject;
class SelectedObject;
class CBuddhalowView;
class SelectedObjectList;
typedef CList<BuddhalowObject *> BuddhalowObjectList;

#include "SelectedObject.h"
#include "SelectedObjectList.h"
class BuddhalowObject : public CObject
{
public:
	CString identifier; // Identifier of the object
	CRect bounds; // Bounds
	CPoint moveOffset;
	BuddhalowObjectList *objects; // Child objects
public:
	BuddhalowObject();
	BuddhalowObject(CRect bounds);
	~BuddhalowObject();	
	virtual SelectedObjectList *GetObjectsAtPosition(const CPoint&, int depth);
	virtual BuddhalowObject *GetObjectAtPosition(const CPoint&);
	virtual void Add(BuddhalowObject *object);
	virtual void Draw(CDC *pDC, CBuddhalowView *view);
	virtual void AssertValid() const;
	virtual void Serialize(CArchive& ar);
	virtual void Dump(CDumpContext& dc) const;
};
