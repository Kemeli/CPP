#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class Fixed
{
	private:
	int					fixed_point;
	static const int	fractional_bits = 8;

	public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed(const int value);
	Fixed(const float value);

	~Fixed();

	Fixed&	operator=( const Fixed& fixed);
	Fixed	operator+( const Fixed& fixed);
	Fixed	operator-( const Fixed& fixed);
	Fixed	operator*( const Fixed& fixed);
	Fixed	operator/( const Fixed& fixed);

	bool	operator<(const Fixed&fixed);
	bool	operator>( const Fixed& fixed);
	bool	operator>=( const Fixed& fixed);
	bool	operator<=( const Fixed& fixed);
	bool	operator==( const Fixed& fixed);
	bool	operator!=( const Fixed& fixed);

	Fixed	operator++(int);
	Fixed	operator--(int);
	Fixed	operator++(void);
	Fixed	operator--(void);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif
