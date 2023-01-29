#include "Line2D.h"
#include "vector"
#include "utility"
#include <algorithm>

//empty constructor
Line2D::Line2D() {}

//base constructor
Line2D::Line2D(std::vector<Seg2D> &inputLineSegments)
{
    std::sort(inputLineSegments[0], inputLineSegments[inputLineSegments.size() - 1]); //sort input vector to order segments
    for(int i = 0; i < inputLineSegments.size(); i++)
    {
        HalfSeg2D domHalfSeg = HalfSeg2D(inputLineSegments[i], true); //set dominant point half segment from segment
        this->lineSegments.push_back(domHalfSeg);
        HalfSeg2D endHalfSeg = HalfSeg2D(inputLineSegments[i], false); //set end point half segment from segment
        this->lineSegments.push_back(endHalfSeg);
    }
}

//copy constructor
Line2D::Line2D(Line2D &sourceLine2D)
{
    this->lineSegments = sourceLine2D.lineSegments; //copy line segment data
}

//move constructor
Line2D::Line2D(Line2D &&sourceLine2D)
{
    this->lineSegments = sourceLine2D.lineSegments;
    sourceLine2D.lineSegments = nullptr; //not viable overload - needs fixing
}

//destructor
Line2D::~Line2D()
{

}
