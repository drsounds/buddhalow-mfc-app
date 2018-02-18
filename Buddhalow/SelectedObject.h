#pragma once
#include "stdafx.h"
#include "BuddhalowObject.h"

class SelectedObject : public CObject {
public:
	BuddhalowObject *object;
	int layer;
	SelectedObject(BuddhalowObject *object, int layer);
};