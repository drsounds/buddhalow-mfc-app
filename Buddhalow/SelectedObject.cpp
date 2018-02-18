#include "stdafx.h"
#include "SelectedObject.h"

SelectedObject::SelectedObject(BuddhalowObject *object, int layer) {
	this->object = object;
	this->layer = layer;
}