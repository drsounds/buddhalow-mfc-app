#pragma once
#include "stdafx.h"
#include "SelectedObject.h"
class SelectedObjectList : public CList<SelectedObject *> {
public:
	SelectedObject *GetTopMostObject(int layer, const CPoint&);
	int GetTopMostLayer(const CPoint&);
};