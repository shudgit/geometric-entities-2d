#include "Poi2D.h"
#include "vector"


class Point2D {
private:
    std::vector<Poi2D> pointCollection;
public:
    Point2D();
    Point2D(std::vector<Poi2D> _pointCollection);
    Point2D(Point2D &sourcePoint2D);
    Point2D(Point2D &&sourcePoint2D);

};
