#include "stdafx.h"
#include "SelectedObjectList.h"

SelectedObject *SelectedObjectList::GetTopMostObject(int layer, const CPoint& point) {

	POSITION pos = this->GetHeadPosition();
	while (pos) {
		SelectedObject *obj = this->GetNext(pos);
		if (obj->layer == layer) {
			if (point.x > obj->object->bounds.left && point.x < obj->object->bounds.right &&
				point.y > obj->object->bounds.top && point.y < obj->object->bounds.bottom)
				return obj;
		}
	}
	return nullptr;
}

int SelectedObjectList::GetTopMostLayer(const CPoint& point) {
	POSITION pos = this->GetHeadPosition();
	int layer = 0;
	while (pos) {
		SelectedObject *obj = this->GetNext(pos);
		if (obj->layer > layer) {
			layer = obj->layer;
		}
	}
	return layer;
}