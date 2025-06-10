#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed {
	private:
	int					numberValue;
	static const int	fractionalBits = 8;

	public:
	Fixed(void);
	Fixed(const Fixed& other);
	Fixed&	operator=(const Fixed& other);

	Fixed(const int);
	Fixed(const float);

	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
