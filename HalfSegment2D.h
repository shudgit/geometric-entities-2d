#pragma once
#include "Segment2D.h"
struct HalfSegment2D
{
	Segment2D s;
	bool isLeft;
	HalfSegment2D();
	HalfSegment2D(const HalfSegment2D& hs);
	HalfSegment2D(Segment2D s, bool isLeft);
	void operator=(HalfSegment2D hs);
	bool operator==(HalfSegment2D hs);
	bool operator<(HalfSegment2D hs);
	bool operator<=(HalfSegment2D hs);
	~HalfSegment2D();
};