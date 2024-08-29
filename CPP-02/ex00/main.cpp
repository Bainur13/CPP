/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:28:22 by udumas            #+#    #+#             */
/*   Updated: 2024/08/20 19:26:24 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

int	main(void)
{
    std::cout << "TEST 1 :" << std::endl;
	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

    std::cout << std::endl << "TEST 2 :" << std::endl;
    a.setRawBits(5);
    std::cout << a.getRawBits() << std::endl;
    b = a;
    std::cout << b.getRawBits() << std::endl;

	return (0);
}