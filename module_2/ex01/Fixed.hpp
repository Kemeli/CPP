#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>
#	include <math.h>

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

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif
