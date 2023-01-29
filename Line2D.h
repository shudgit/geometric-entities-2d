#include <vector>
#include "HalfSeg2D.h"
#include "Seg2D.h"

class Line2D {
private:
    std::vector<HalfSeg2D> lineSegments; //vector to hold half segment data
public:
    Line2D(); //empty constructor
    Line2D(std::vector<Seg2D> &inputLineSegments); //base constructor
    Line2D(Line2D &sourceLine2D); //copy constructor
    Line2D(Line2D &&sourceLine2D); //move constructor
    ~Line2D(); //Destructor
};
