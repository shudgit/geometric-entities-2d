#pragma once
#include "SimplePoint2D.h"
struct Segment2D
{
	SimplePoint2D l, r;
	Number length;
	Segment2D();
	Segment2D(SimplePoint2D l, SimplePoint2D r);
	void operator=(Segment2D p);
	bool operator==(Segment2D p);
	bool operator<(Segment2D p);
	bool operator<=(Segment2D p);
};