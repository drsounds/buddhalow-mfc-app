#pragma once
#include "stdafx.h"
/**
 * From https://groups.google.com/forum/?hl=de#!topic/microsoft.public.vc.mfc/gE7B8tgitwc
 */
template <class argt, class valt>
class SortedList<class argt, class valt> : public CList<argt, valt> {
public:
	void Sort<argt, valt>()
	{
		if (GetSize() < 2)
			return; // 0 and 1 elements already in order!
		CArray<argt, valt> array;
		POSITION p;
		array.SetSize(GetSize());

		p = GetHeadPosition();
		while (p != NULL)
		{
			array[i] = GetNext(p);
		}
		qsort(array.GetData(), ...etc...);
		RemoveAll();
		for (int i = 0; i < array.GetSize(); i++)
			AddTail(array[i]);
	}
};