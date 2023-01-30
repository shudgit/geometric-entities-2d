#pragma once
#include "HalfSegment2D.h"
struct AttributedHalfSegment2D
{
	HalfSegment2D hs;
	bool above;
	AttributedHalfSegment2D(HalfSegment2D hs, bool above);
	void operator=(AttributedHalfSegment2D ahs);
	bool operator==(AttributedHalfSegment2D ahs);
	bool operator<(AttributedHalfSegment2D ahs);
	bool operator<=(AttributedHalfSegment2D ahs);
};