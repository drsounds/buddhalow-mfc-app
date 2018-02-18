#include "stdafx.h"
#include "BuddhalowObject.h"
#include "SelectedObject.h"
#include "SelectedObjectList.h"
#include "BuddhalowView.h"
void BuddhalowObject::Add(BuddhalowObject *object) {
	this->objects->AddHead(object);
}

BuddhalowObject::BuddhalowObject()
{
	this->objects = new BuddhalowObjectList;
}

BuddhalowObject *BuddhalowObject::GetObjectAtPosition(const CPoint& point) {
	SelectedObjectList *objects = this->GetObjectsAtPosition(point, 0);
	// Get highest value
	int layer = objects->GetTopMostLayer(point);
	SelectedObject *selectedObject = objects->GetTopMostObject(layer, point);
	BuddhalowObject *object = nullptr;
	if (selectedObject != nullptr) {
		object = selectedObject->object;
	}
	return object;
}

SelectedObjectList *BuddhalowObject::GetObjectsAtPosition(const CPoint& point, int depth) {
	SelectedObjectList *objects = new SelectedObjectList;
	POSITION pos = this->objects->GetHeadPosition();
	depth++;
	while (pos) {
		BuddhalowObject *object = this->objects->GetNext(pos);
		if (point.x > object->bounds.left && point.x < object->bounds.right &&
			point.y > object->bounds.top && point.y < object->bounds.bottom) {
			SelectedObject *selectedObject = new SelectedObject(object, depth);
			objects->AddTail(selectedObject);
			SelectedObjectList *childObjects = object->GetObjectsAtPosition(point, depth + 1);
			objects->AddTail(childObjects);
			delete childObjects;
		}
	}
	return objects;
}

BuddhalowObject::BuddhalowObject(CRect bounds)
{
	this->bounds = bounds;
	this->objects = new BuddhalowObjectList;
}

void BuddhalowObject::Draw(CDC *pDC, CBuddhalowView *view) {
	// Here we can draw the object
	POINT point = pDC->GetCurrentPosition();
	point.x += this->bounds.left;
	point.y += this->bounds.top;
	pDC->MoveTo(point);

	pDC->Rectangle((LPRECT)this->bounds);
	POSITION i = this->objects->GetTailPosition();

	if (view->IsObjectSelected(this)) {
		// Draw selection handles
		pDC->Rectangle(CRect(point.x - 2, point.y - 2, point.x + 4, point.y + 4));
		pDC->Rectangle(CRect(this->bounds.right - 2, this->bounds.bottom - 2, this->bounds.right + 4, this->bounds.bottom + 4));
		pDC->Rectangle(CRect(this->bounds.left - 2, this->bounds.bottom - 2, this->bounds.left + 4, this->bounds.bottom + 4));
		pDC->Rectangle(CRect(this->bounds.right - 2, this->bounds.top - 2, this->bounds.right + 4, this->bounds.top + 4));
	}
	if (view->moveBounds != NULL) {
		CRect rect = CRect(); 
		rect.left = view->moveBounds->left - moveOffset.x; 
		rect.top = view->moveBounds->top - moveOffset.y;
		rect.right = rect.left + bounds.Width();
		rect.bottom = rect.top + bounds.Height();
		pDC->DrawFocusRect(rect);

	}
	while(i) {
		BuddhalowObject *object = (BuddhalowObject *)this->objects->GetPrev(i);
		object->Draw(pDC, view);
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
