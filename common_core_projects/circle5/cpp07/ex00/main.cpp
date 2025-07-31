#include "whatever.hpp"

class Awesome
{
  public:
    Awesome(void) : _n(0) {}
    Awesome( int n ) : _n( n ) {}
    Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
    bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
    bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
    bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
    bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
    bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
    bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
    int get_n() const { return _n; }
  private:
    int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main(void)
{
	int num1 = 5;
	int num2 = 10;
	Awesome a(2), b(4);

        swap(a, b);
		std::cout << num1 << " " << num2 << std::endl << max(num1, num2) << " " << min(num1, num2) << std::endl;;
        std::cout << a << " " << b << std::endl;
        std::cout << max(a, b) << std::endl;
        std::cout << min(a, b) << std::endl;
        return (0);
}