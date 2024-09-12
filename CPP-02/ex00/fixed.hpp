/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:34:36 by udumas            #+#    #+#             */
/*   Updated: 2024/09/12 19:26:40 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

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
	~Fixed(void);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	Fixed &operator=(const Fixed &);
};

#endif
