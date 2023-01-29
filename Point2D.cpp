#include "Point2D.h"
#include <algorithm>

Point2D::Point2D() {}

Point2D::Point2D(std::vector<Poi2D> _pointCollection)
{
    //std::sort(_pointCollection[0], _pointCollection[_pointCollection.size() - 1]);
    this->pointCollection = _pointCollection;
}
Point2D::Point2D(Point2D &sourcePoint2D)
{
    this->pointCollection = sourcePoint2D.pointCollection;
}
Point2D::Point2D(Point2D &&sourcePoint2D)
{

}
