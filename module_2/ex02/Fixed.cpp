#include "Fixed.hpp"
#include <math.h>

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->fixed_point = 0;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->fixed_point = value * (1 << this->fractional_bits);
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->fixed_point = roundf(value * (1 << this->fractional_bits));
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->fixed_point / (float)(1 << this->fractional_bits));
}

int	Fixed::toInt( void ) const
{
	return (this->fixed_point / (1 << this->fractional_bits));
}

int	Fixed::getRawBits( void ) const
{
	return (this->fixed_point);
}

void	Fixed::setRawBits( int const raw )
{
	this->fixed_point = raw;
}

Fixed&	Fixed::operator=(const Fixed&obj)
{
	if (&obj != this)
		this->fixed_point = obj.getRawBits();
	return *this;
}

//##############################################################################
// Arithmetic operators
//##############################################################################

// transforms it back to float in order to multiply it considering the correct
// fractional bits
Fixed	Fixed::operator+(const Fixed&obj)
{
	Fixed	aux;

	aux.setRawBits(
		this->toFloat() + obj.toFloat() * ( 1 << this->fractional_bits ));
	return aux;
}

Fixed	Fixed::operator-(const Fixed&obj)
{
	Fixed	aux;

	aux.setRawBits(
		this->toFloat() - obj.toFloat() * ( 1 << this->fractional_bits ));
	return aux;
}

Fixed	Fixed::operator*(const Fixed&obj)
{
	Fixed	aux;

	aux.setRawBits(
		this->toFloat() * obj.toFloat() * ( 1 << this->fractional_bits ));
	return aux;
}

Fixed	Fixed::operator/(const Fixed&obj)
{
	Fixed	aux;

	aux.setRawBits(
		this->toFloat() / obj.toFloat() * ( 1 << this->fractional_bits ));
	return aux;
}

//##############################################################################
// Comparing operators
//##############################################################################

bool	Fixed::operator<(const Fixed&fixed)
{
	if (this->fixed_point < fixed.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>(const Fixed&fixed)
{
	if (this->fixed_point > fixed.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>=(const Fixed&fixed)
{
	if (this->fixed_point >= fixed.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<=(const Fixed&fixed)
{
	if (this->fixed_point <= fixed.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator==(const Fixed&fixed)
{
	if (this->fixed_point == fixed.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator!=(const Fixed&fixed)
{
	if (this->fixed_point != fixed.getRawBits())
		return true;
	return false;
}

//##############################################################################
// Increment/Decrement operators
//##############################################################################

Fixed	Fixed::operator++()
{
	this->fixed_point++;
	return *this;
}

Fixed	Fixed::operator--()
{
	this->fixed_point--;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp;

	temp.setRawBits(this->fixed_point);
	this->fixed_point++;
	return temp;
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp;

	temp.setRawBits(this->fixed_point);
	this->fixed_point--;
	return temp;
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return (out);
}

//##############################################################################
// Overloaded functions
//##############################################################################

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
