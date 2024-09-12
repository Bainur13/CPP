/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:34:36 by udumas            #+#    #+#             */
/*   Updated: 2024/09/12 19:25:23 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>
# include <string>
class Fixed
{
  private:
	int _value;
	static int const _bit = 8;

  public:
	Fixed(void);
	Fixed(const Fixed &);
	Fixed(const int i);
	Fixed(const float f);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a , const Fixed&  b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed&  a , const Fixed&  b);

	Fixed &operator=(const Fixed &);
	
	float operator+(const Fixed &rhs) const;
	float operator-(const Fixed &rhs) const;
	float operator*(const Fixed &rhs) const;
	float operator/(const Fixed &rhs) const;

	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);
	
	bool operator>(const Fixed &rhs) const;
	bool operator<(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;
	
};

std::ostream &operator<<(std::ostream &o, Fixed const &cur);
#endif
