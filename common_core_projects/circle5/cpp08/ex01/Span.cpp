#include "Span.hpp"

Span::Span(unsigned int N) : _limit(N) {srand(time(0));}

Span::~Span() {}

Span::Span(const Span& copy) {
	_storage = copy._storage;
	_limit = copy._limit;
}

Span&			Span::operator= (const Span& copy) {
	_storage = copy._storage;
	_limit = copy._limit;
	return *this;
}

void			Span::addNumber(unsigned int num) {
	if (_storage.size() != _limit)
		_storage.push_back(num);
	else
		throw std::out_of_range("No more numbers, increase the limit first.");
}

void			Span::printElements() const{
	for (unsigned int i = 0; i < _storage.size(); i++) {
		std::cout << _storage[i] << " ";
	}
}

unsigned int	Span::shortestSpan() const {
	if (_storage.size() < 2)
		throw std::logic_error("We need more numbers");
	unsigned int	shortest = _storage[1] - _storage[0];

	for (unsigned int i = 1; i < _storage.size(); i++) {
		shortest = std::min(shortest, _storage[i + 1] - _storage[i]);
	}
	return shortest;
}

unsigned int	Span::longestSpan() const {
	if (_storage.size() < 1)
		throw std::logic_error("We need more numbers");
	std::vector<unsigned int>::const_iterator max = std::max_element(_storage.begin(), _storage.end());
	std::vector<unsigned int>::const_iterator min = std::min_element(_storage.begin(), _storage.end());
	return *max - *min;
}

void			Span::fill(int amount) {
	if (amount <= 0)
		throw std::logic_error("Please enter a valid amount.");
	std::vector<int>	temp(amount);
	std::vector<int>::iterator	start = temp.begin();
	std::vector<int>::iterator	end = temp.end();
	if (static_cast<unsigned long>(std::distance(start, end)) > _limit - _storage.size()) {
		throw std::out_of_range("Not enough space in the container.");
	}
	while (start != end) {
		_storage.push_back(rand() % 1000000 + 1);
		++start;
	}
}