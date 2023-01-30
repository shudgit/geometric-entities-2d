#include "Number.h"
#include "HalfSegment2D.h"
#include <climits>

HalfSegment2D::HalfSegment2D()		// Default Constructor so that AttributedHalfSegment2D works.
{
}

HalfSegment2D::HalfSegment2D(Segment2D s, bool isLeft)
{
	this->s = s;
	this->isLeft = isLeft;
}

void HalfSegment2D::operator=(HalfSegment2D hs)
{
	this->s = hs.s;
	this->isLeft = hs.isLeft;
}

bool HalfSegment2D::operator==(HalfSegment2D hs)
{
	if ((*this).s == hs.s && (*this).isLeft == hs.isLeft)
		return true;
	else
		return false;
}

bool HalfSegment2D::operator<(HalfSegment2D hs)
{
	// Case 1: 
	if (this->isLeft)		// this is left half segment
	{
		if (hs.isLeft)		// hs is left half segment
		{
			if (this->s.l < hs.s.l)									// if dominating point is less than
				return true;
			else if (hs.s.l < this->s.l)							// if dominating point is greater than 
				return false;
			// if equal, move on to next case
		}
		else				// hs is right half segment
		{
			if (this->s.l < hs.s.r)             // if dominating point is less than
				return true;
			else if (hs.s.r < this->s.l)        // if dominating point is greater than
				return false;
			// if equal, move on to next case
		}
	}
	else				  // this is right half segment
	{
		if (hs.isLeft)	  // hs is left half segment
		{
			if (this->s.r < hs.s.l)              // if dominating point is less than
				return true;
			else if (hs.s.l < this->s.r)         // if dominating point is greater than
				return false;
			// if equal, move on to next case
		}
		else             // hs is right half segment
		{
			if (this->s.r < hs.s.r)             // if dominating point is less than
				return true;
			else if (hs.s.r < this->s.r)        // if dominating point is greater than
				return false;
			// if equal, move on to next case
		}
	}

	// Case 2a:
	if (!this->isLeft && hs.isLeft)			// this is right half segment and hs is left half segment
		return true;
	else if (!hs.isLeft && this->isLeft)	// this is left half segment and hs is right half segment
		return false;

	// Case 2b: 
	Number m1, m2;

	if (this->s.r.x == this->s.l.x)       // check for infinity slope
		m1 = INT_MAX;
	else
		m1 = (this->s.r.y - this->s.l.y) / (this->s.r.x - this->s.l.x);       // calculate slope of this normally

	if (hs.s.r.x == hs.s.l.x)       // check for infinity slope
		m2 = INT_MAX;
	else
		m2 = (hs.s.r.y - hs.s.l.y) / (hs.s.r.x - hs.s.l.x);					  // calculate slope of hs normally

	if (this->isLeft)                     // both are left half segments
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
	if (this->s.length < hs.s.length)
		return true;
	else
		return false;
}

bool HalfSegment2D::operator<=(HalfSegment2D hs)
{
	if (*this < hs || *this == hs)
		return true;
	else
		return false;
}
