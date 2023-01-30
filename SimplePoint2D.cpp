#include "SimplePoint2D.h"

SimplePoint2D::SimplePoint2D()
{
	this->x = 0;
	this->y = 0;
}

SimplePoint2D::SimplePoint2D(Number x, Number y)
{
	this->x = x;
	this->y = y;
}

void SimplePoint2D::operator=(SimplePoint2D p)
{
	this->x = p.x;
	this->y = p.y;
}

bool SimplePoint2D::operator==(SimplePoint2D p)
{
	if ((*this).x == p.x && (*this).y == p.y)
		return true;
	else
		return false;
}

bool SimplePoint2D::operator<(SimplePoint2D p)
{
	if ((*this).x < p.x)
		return true;
	else if ((*this).x == p.x && (*this).y < p.y)
		return true;
	else
		return false;
		
}

bool SimplePoint2D::operator<=(SimplePoint2D p)
{
	if (*this < p || *this == p)
		return true;
	else
		return false;
}
