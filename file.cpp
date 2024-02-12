class Awesome {
public:
	Awesome( void ) : _n( 0 ) {}
	Awesome( int n ) : _n( n ) {}
	Awesome & operator=( Awesome & a ) { _n = a._n; return *this; }
	bool operator==( Awesome const & a ) const { return (_n == a._n); }
	bool operator!=( Awesome const & a ) const { return (_n != a._n); }
	bool operator>( Awesome const & a ) const { return (_n > a._n); }
	bool operator<( Awesome const & a ) const { return (_n < a._n); }
	bool operator>=( Awesome const & a ) const { return (_n >= a._n); }
	bool operator<=( Awesome const & a ) const { return (_n <= a._n); }
	int getN() const { return _n; }
private:
	int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & a ) { o << a.getN(); return o; }

int main()
{
	Awesome a(2), b(3);

	swap(a,b);
	std::cout << a << " " << b << std::endl;
	std::cout << "min( a, b ) = " << min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << max( a, b ) << std::endl;
}

///////////////////////////////////////////////////////////////////////////
class Awesome
{
public:
	Awesome( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
private:
	int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void printValue( T const & x ) { std::cout << x << std::endl; return; }


int main()
{
	int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];
	iter( tab, 5, printValue );
	iter( tab2, 5, printValue );

	return 0;
}

///////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

class ComplexData {
public:
	ComplexData() : _real(0) {}
	ComplexData(double real) : _real(real) {}
	double getReal() const { return _real; }
private:
	double _real;
};

int main(int, char**) {
	const int MAX_VAL = 750;
	Array<ComplexData> complexArray(MAX_VAL);
	ComplexData* mirror = new ComplexData[MAX_VAL];
	srand(time(NULL));

	for (int i = 0; i < MAX_VAL; i++) {
		const double real = static_cast<double>(rand()) / RAND_MAX;
		ComplexData data(real);
		complexArray[i] = data;
		mirror[i] = data;
	}

	// Test if the values are saved correctly
	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i].getReal() != complexArray[i].getReal()) {
			std::cerr << "Values are not saved correctly!" << std::endl;
			return 1;
		}
	}

	try {
		complexArray[-2] = ComplexData();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		complexArray[MAX_VAL] = ComplexData();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}


	delete[] mirror;
	return 0;
}

