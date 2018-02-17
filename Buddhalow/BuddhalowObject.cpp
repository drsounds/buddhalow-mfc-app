#include "stdafx.h"
#include "BuddhalowObject.h"


void BuddhalowObject::Add(BuddhalowObject *object) {
	this->objects->AddHead(object);
}

BuddhalowObject::BuddhalowObject()
{
	this->objects = new BuddhalowObjectList;
}

BuddhalowObject::BuddhalowObject(CRect bounds)
{
	this->bounds = bounds;
	this->objects = new BuddhalowObjectList;
}

void BuddhalowObject::Draw(CDC *pDC) {
	// Here we can draw the object
	POINT point = pDC->GetCurrentPosition();
	point.x += this->bounds.left;
	point.y += this->bounds.top;
	pDC->MoveTo(	point);
	POSITION i = this->objects->GetHeadPosition();
	while(i) {
		BuddhalowObject *object = (BuddhalowObject *)this->objects->GetNext(i);
		pDC->Rectangle((LPRECT)object->bounds);
	}
	point.x -= this->bounds.left;
	point.y -= this->bounds.top;
}


BuddhalowObject::~BuddhalowObject()
{
}


void BuddhalowObject::AssertValid() const
{
	CObject::AssertValid();

	// TODO: Add your specialized code here and/or call the base class
}


void BuddhalowObject::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
	}
	else
	{	// loading code
	}
}


void BuddhalowObject::Dump(CDumpContext& dc) const
{
	CObject::Dump(dc);

	// TODO: Add your specialized code here and/or call the base class
}
