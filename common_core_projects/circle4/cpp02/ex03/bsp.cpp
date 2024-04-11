#include "Point.hpp"

int	crossCalc(Point const &a, Point const &b, Point const &c) {
	Point	ab(b.toFloatX() - a.toFloatX(), b.toFloatY() - a.toFloatY());
	Point	ac(c.toFloatX() - a.toFloatX(), c.toFloatY() - a.toFloatY());
	float cross = ab.toFloatX() * ac.toFloatY() - ab.toFloatY() * ac.toFloatX();
	if (cross > 0)
		return 1;
	else if (cross < 0)
		return -1;
	else
		return 0;
}

bool bsp( Point const a, Point const b, Point const c, Point const p) {
	int	check = crossCalc(a, b, p) + crossCalc(b, c, p) + crossCalc(c, a, p);
	if (check == 3 || check == -3)
		return true;
	else if (check == 0)
		return false;
	else
		return false;
}