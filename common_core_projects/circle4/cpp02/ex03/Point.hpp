#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

#define RESET   "\033[0m"
#define RED     "\033[1m\033[31m"
#define GREEN   "\033[1m\033[32m"
#define YELLOW  "\033[1m\033[33m"
#define BLUE    "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN    "\033[1m\033[36m"
#define WHITE   "\033[1m\033[37m"

class Point {
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point();
		Point(const float x1, const float y1);
		Point(const Point& copy);
		Point& operator= (const Point& copy);
		~Point();
		Fixed const	&getX() const;
		Fixed const	&getY() const;
		float	toFloatX(void) const;
		float	toFloatY(void) const;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif