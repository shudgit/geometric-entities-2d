#include "Segment2D.h"
#include <cmath>

Segment2D::Segment2D()		// Created default constructor so that HalfSegment2D works.
{
}

Segment2D::Segment2D(const Segment2D& s)
{
	this->l = s.l;
	this->r = s.r;
	this->length = s.length;
}

Segment2D::Segment2D(SimplePoint2D l, SimplePoint2D r)
{
	if (l < r)
	{
		this->l = l;
		this->r = r;
	}
	else
	{
		this->l = r;
		this->r = l;
	}
	this->length = (this->r.y - this->l.y) * (this->r.y - this->l.y) + (this->r.x - this->l.x) * (this->r.x - this->l.x);		// no sqrt because not implemented
}

void Segment2D::operator=(Segment2D s)
{
	this->l = s.l;
	this->r = s.r;
}

bool Segment2D::operator==(Segment2D s)
{
	if ((*this).l == s.l && (*this).r == s.r)
		return true;
	else
		return false;
}

bool Segment2D::operator<(Segment2D s)
{
	if ((*this).l < s.l)
		return true;
	else if ((*this).l == s.l && (*this).r < s.r)
		return true;
	else
		return false;
}

bool Segment2D::operator<=(Segment2D s)
{
	if (*this < s || *this == s)
		return true;
	else
		return false;
}

Segment2D::~Segment2D()
{
	~this->l();
	~this->r();
	~this->length();
}
