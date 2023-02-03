#include "Number.h"
#include "AttributedHalfSegment2D.h"
#include <climits>

AttributedHalfSegment2D::AttributedHalfSegment2D(HalfSegment2D hs, bool above)
{
	this->hs = hs;
	this->above = above;
}

AttributedHalfSegment2D::AttributedHalfSegment2D(const AttributedHalfSegment2D& ahs)
{
	this->hs = ahs.hs;
	this->above = ahs.above;
}

void AttributedHalfSegment2D::operator=(AttributedHalfSegment2D ahs)
{
	this->hs.s = ahs.hs.s;
	this->hs.isLeft = ahs.hs.isLeft;
}

bool AttributedHalfSegment2D::operator==(AttributedHalfSegment2D ahs)
{
	if (this->hs.s == ahs.hs.s && this->hs.isLeft == ahs.hs.isLeft)
		return true;
	else
		return false;
}

bool AttributedHalfSegment2D::operator<(AttributedHalfSegment2D ahs)
{
	// Case 1: 
	if (this->hs.isLeft)		// this is left half segment
	{
		if (ahs.hs.isLeft)		// hs is left half segment
		{
			if (this->hs.s.l < ahs.hs.s.l)									// if dominating point is less than
				return true;
			else if (ahs.hs.s.l < this->hs.s.l)							// if dominating point is greater than 
				return false;
			// if equal, move on to next case
		}
		else				// hs is right half segment
		{
			if (this->hs.s.l < ahs.hs.s.r)             // if dominating point is less than
				return true;
			else if (ahs.hs.s.r < this->hs.s.l)        // if dominating point is greater than
				return false;
			// if equal, move on to next case
		}
	}
	else				  // this is right half segment
	{
		if (ahs.hs.isLeft)	  // hs is left half segment
		{
			if (this->hs.s.r < ahs.hs.s.l)              // if dominating point is less than
				return true;
			else if (ahs.hs.s.l < this->hs.s.r)         // if dominating point is greater than
				return false;
			// if equal, move on to next case
		}
		else             // hs is right half segment
		{
			if (this->hs.s.r < ahs.hs.s.r)             // if dominating point is less than
				return true;
			else if (ahs.hs.s.r < this->hs.s.r)        // if dominating point is greater than
				return false;
			// if equal, move on to next case
		}
	}

	// Case 2a:
	if (!this->hs.isLeft && ahs.hs.isLeft)			// this is right half segment and hs is left half segment
		return true;
	else if (!ahs.hs.isLeft && this->hs.isLeft)	// this is left half segment and hs is right half segment
		return false;

	// Case 2b: 
	Number m1, m2;

	if (this->hs.s.r.x == this->hs.s.l.x)       // check for infinity slope
		m1 = INT_MAX;
	else
		m1 = (this->hs.s.r.y - this->hs.s.l.y) / (this->hs.s.r.x - this->hs.s.l.x);       // calculate slope of this normally

	if (ahs.hs.s.r.x == ahs.hs.s.l.x)       // check for infinity slope
		m2 = INT_MAX;
	else
		m2 = (ahs.hs.s.r.y - ahs.hs.s.l.y) / (ahs.hs.s.r.x - ahs.hs.s.l.x);					  // calculate slope of hs normally

	if (this->hs.isLeft)                     // both are left half segments
	{
		// so we are pretty much restricted to quadrants I and IV of the euclidean plane. Otherwise they could not both be left half segments.
		// this means we just need to compare slopes to check for the counterclockwise rotation
		if (m2 > m1)
			return true;
		else if (m1 > m2)
			return false;
		// if slope is equal, it is case 3
	}
	else                                  // both are right half segments - essentially opposite of if both are left
	{
		// so we are pretty much restricted to quadrants II and III of the euclidean plane. Otherwise they could not both be right half segments.
		// this means we just need to compare slopes to check for the counterclockwise rotation
		if (m2 > m1)
			return false;
		else if (m1 > m2)
			return true;
		// if slope is equal, it is case 3
	}

	// Case 3:
	if (this->hs.s.length < ahs.hs.s.length)
		return true;
	else
		return false;
}

bool AttributedHalfSegment2D::operator<=(AttributedHalfSegment2D ahs)
{
	if (*this < ahs || *this == ahs)
		return true;
	else
		return false;
}

AttributedHalfSegment2D::~AttributedHalfSegment2D()
{
	~this->hs();
}
