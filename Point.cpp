// Eric Feng
// 921306906
#include "Point.h"
using namespace std;


Point Point::operator+(const Point& rhs) const {
    return Point(x + rhs.x, y + rhs.y);
}

Point Point::operator-(const Point& rhs) const {
    return Point(x - rhs.x, y - rhs.y);
}

std::istream& operator>>(std::istream& is, Point& p) {
    int x;
    int y;
    is >> x >> y;
    p.x = x;
    p.y = y;
    return is;
}
ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

