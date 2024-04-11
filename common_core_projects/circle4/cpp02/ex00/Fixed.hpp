#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

	private:
		int					_fixed;
		static const int	_f_bits;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator= (const Fixed& copy);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif