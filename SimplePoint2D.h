#pragma once
#include "Number.h"
struct SimplePoint2D
{
	Number x, y;
	SimplePoint2D();
	SimplePoint2D(const SimplePoint2D& p);
	SimplePoint2D(Number x, Number y);
	void operator=(SimplePoint2D p);
	bool operator==(SimplePoint2D p);
	bool operator<(SimplePoint2D p);
	bool operator<=(SimplePoint2D p);
	~SimplePoint2D();
};