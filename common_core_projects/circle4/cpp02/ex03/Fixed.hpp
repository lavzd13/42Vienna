#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

	private:
		int					_fixed;
		static const int	_f_bits;

	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		~Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator= (const Fixed& copy);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		Fixed	operator+(const Fixed& copy);
		Fixed	operator-(const Fixed& copy);
		Fixed	operator*(const Fixed& copy) const;
		Fixed	operator/(const Fixed& copy);
		Fixed	operator++();
		Fixed	operator++(int);
		Fixed	operator--();
		Fixed	operator--(int);
		bool	operator<(const Fixed& copy);
		bool	operator<=(const Fixed& copy);
		bool	operator>(const Fixed& copy);
		bool	operator>=(const Fixed& copy);
		bool	operator==(const Fixed& copy);
		bool	operator!=(const Fixed& copy);
		static Fixed&	minn(Fixed& a, Fixed& b);
		static Fixed&	maxx(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed);

#endif