#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point = value * (1 << this->fractional_bits);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point = value * (1 << this->fractional_bits);
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

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_point = raw;
}

Fixed& Fixed::operator=(const Fixed&fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (&fixed != this)
		this->fixed_point = fixed.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return (out);
}
