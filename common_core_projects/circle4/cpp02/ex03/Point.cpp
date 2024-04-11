#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x1, const float y1) : _x(x1), _y(y1) {}

Point::Point(const Point &copy) {
	*this = copy;
}

Point& Point::operator= (const Point& copy) {
	(void)copy;
	return *this;
}

Point::~Point() {}

Fixed const	&Point::getX(void) const {
	return _x;
}

Fixed const	&Point::getY(void) const {
	return _y;
}

float	Point::toFloatX(void) const {
	return _x.toFloat();
}

float	Point::toFloatY(void) const {
	return _y.toFloat();
}