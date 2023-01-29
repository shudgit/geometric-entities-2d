#include <vector>
#include <utility>
#include "AttributedHalfSeg2D.h"
#include "Seg2D.h"

class Region2D {
private:
    std::vector<AttributedHalfSeg2D> regionSegments;

public:
    Region2D();
    Region2D(std::vector<Seg2D> _regionSegments);
    Region2D(Region2D &sourceRegion2D);
    Region2D(Region2D &&sourceRegion2D);
};
