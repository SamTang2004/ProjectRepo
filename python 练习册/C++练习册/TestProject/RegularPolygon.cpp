#include <iostream>
#include <cmath>
#include <math.h>
class RegularPolygon{
private:
    int sides;
    double length;
public:
    RegularPolygon(int numSides, double sizeLength);
    int get_qty_sides() const;
    double get_side_length() const;
    double get_area() const;
    bool operator<(RegularPolygon const & other) const;
};
RegularPolygon::RegularPolygon(int numSides, double sizeLength){
    if (numSides < 3 ||sizeLength < 0){
        sides = 3;
        length = 1;
    }else{
        sides = numSides;
        length = sizeLength;
    }
}
int RegularPolygon::get_qty_sides() const{
        return sides;
    }

double RegularPolygon::get_side_length() const{
        return length;
    }

double RegularPolygon::get_area() const{
        std::cout<<tan(M_PI/7)<<std::endl;
        return (sides * length) * (length/(2.0*tan((180.0/sides) * M_PI / 180)))/2;

    }

bool RegularPolygon::operator<(RegularPolygon const & other) const {
        return get_area() < other.get_area();
}
