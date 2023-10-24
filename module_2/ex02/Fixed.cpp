#include "Fixed.hpp"
#include <iostream>
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
	// std::cout << "setRawBits member function called" << std::endl;
	this->fixed_point = raw;
}

// #############################################################################
// Overloading operators
//##############################################################################

Fixed&	Fixed::operator=(const Fixed&obj)
{
	if (&obj != this)
		this->fixed_point = obj.getRawBits();
	return *this;
}

// transforms it back to float in order to multiplicate considering the correct
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
