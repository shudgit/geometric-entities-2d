#include <iostream>
#include "Number.h"
#include "SimplePoint2D.h"
#include "Segment2D.h"
#include "HalfSegment2D.h"
#include "AttributedHalfSegment2D.h"
using namespace std;

int main()
{
	// Testing Simple Point 2D
	// Number objects for testing
	Number one = 1.0;
	Number two = 2.0;
	// Testing Constructors
	SimplePoint2D pointA;
	SimplePoint2D pointB(one,two);
	cout << "SimplePoint2D Tests\n\nDefault Constructor: " << pointA.x << ", " << pointA.y << "\nPreset Value Constructor: " << pointB.x << ", " << pointB.y << "\n" << endl;
	// Testing Reassignment from Point to Point
	pointA = pointB;
	cout << "After assigning point A equal to point B, comparison should yield true:" << endl;
	if(pointA == pointB)
		cout << "True, previous points are the same\n" << endl;
	else
		cout << "False, equality operator or assignment operator are erroneous...\n" << endl;
	return 0;
}
