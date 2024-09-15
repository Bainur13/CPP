/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:34:36 by udumas            #+#    #+#             */
/*   Updated: 2024/09/15 17:14:55 by udumas           ###   ########.fr       */
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

	Fixed &operator=(const Fixed &);
	
};

std::ostream &operator<<(std::ostream &o, Fixed const &cur);
#endif
