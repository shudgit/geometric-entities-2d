#include "Region2D.h"
#include "vector"
#include "utility"

//empty constructor
Region2D::Region2D() {}

//base constructor
Region2D::Region2D(Region2D &_region2D)
{
    this->regionSegments = _region2D.regionSegments;
}

//copy constructor
Region2D::Region2D(vector<Seg2D> _regionSegments)
{
    this->regionSegments = _regionSegments;
}

//move constructor
Region2D::Region2D(Region2D &&sourceRegion2D)
{

}
