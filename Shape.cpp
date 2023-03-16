// Eric Feng
// 912306906

#include "Shape.h"
#include <algorithm>
#include <math.h>
using namespace std;

Rectangle::~Rectangle() {
}

bool Rectangle::overlaps(const Shape& s) const      {
    return s.overlaps(*this);
}

bool Rectangle::overlaps(const Circle& r) const     {
    int x_n;
    int y_n;
    int d;
    x_n = min(max(r.center.x, position.x), position.x + width);
    y_n = min(max(r.center.y, position.y), position.y + height);
    d = pow((x_n - r.center.x), 2) + pow((y_n - r.center.y), 2);
    if (d < pow(r.radius, 2)) {
        return true;
    } else {
        return false;
    }
}

bool Rectangle::overlaps(const Rectangle& r) const      {
    int l1_x = position.x;
    int l1_y = position.y + height;
    int r1_x = position.x + width;
    int r1_y = position.y;
    int l2_x = r.position.x;
    int l2_y = r.position.y + r.height;
    int r2_x = r.position.x + r.width;
    int r2_y = r.position.y;

    if (l1_x >= r2_x || l2_x >= r1_x) {
        return false;
    }
    if (r1_y >= l2_y || r2_y >= l1_y) {
        return false;
    }   else {
        return true;
    }
}

bool Rectangle::fits_in(const Rectangle& r) const   {
    int l1_x = position.x;
    int l1_y = position.y;
    int r1_x = position.x + width;
    int r1_y = position.y + height;
    int l2_x = r.position.x;
    int l2_y = r.position.y;
    int r2_x = r.position.x + r.width;
    int r2_y = r.position.y + r.height;
    if ((l2_x <= l1_x) && (l2_y <= l1_y) && (r2_x >= r1_x) && (r2_y >= r1_y)) {
        return true;
    } else {
        return false;
    }
}

void Rectangle::draw(void) const    {
    cout << "<rect x=\"" << position.x << "\"" <<  " y=\"" << position.y << "\"" << " width=\"" << width << "\"" << " height=\"" << height << "\"/>" << endl;
}

Circle::~Circle()   {
}

bool Circle::overlaps(const Shape& s) const     {
    return s.overlaps(*this);
}

bool Circle::overlaps(const Rectangle& r) const {
    int x_n;
    int y_n;
    int d;
    x_n = min(max(center.x, r.position.x), r.position.x + r.width);
    y_n = min(max(center.y, r.position.y), r.position.y + r.height);
    d = pow((x_n - center.x), 2) + pow((y_n - center.y), 2);
    if (d < pow(radius, 2)) {
        return true;
    } else {
        return false;
    }
}

bool Circle::overlaps(const Circle& r) const    {
    int d = pow((center.x - r.center.x), 2) + pow((center.y - r.center.y), 2);
    int r_1 = pow(radius, 2);
    int r_2 = pow(r.radius, 2);
    if (d < r_1 + r_2) {
        return true;
    }   else {
        return false;
    }
}

bool Circle::fits_in(const Rectangle& r) const  {
    int l1_x = r.position.x;
    int l1_y = r.position.y;
    int r1_x = r.position.x + r.width;
    int r1_y = r.position.y + r.height;
    int c1_x = center.x - radius;
    int c1_y = center.y - radius;
    int c2_x = center.x + radius;
    int c2_y = center.y + radius;
    if ((c1_x >= l1_x) && (c2_x <= r1_x) && (c1_y >= l1_y) && (c2_y <= r1_y))   {
        return true;
    }
    return false;
}

void Circle::draw(void) const   {
    cout << "<circle cx=\"" << center.x << "\"" << " cy=\"" << center.y << "\"" " r=\"" << radius << "\"/>" << endl;
}