#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
	int					fixed_point;
	static const int	fractional_bits = 8;

	public:
	Fixed();
	Fixed(const Fixed& other);
	~Fixed();
	Fixed& operator=( const Fixed& fixed);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif
