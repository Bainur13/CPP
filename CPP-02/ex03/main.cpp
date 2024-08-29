/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:28:22 by udumas            #+#    #+#             */
/*   Updated: 2024/08/26 16:17:49 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"
#include "point.hpp"

int	main(void)
{
	// Création des points du triangle
	Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
	Point c(2.5f, 5.0f);

	// Points à tester
	Point p1(2.5f, 2.5f); // À l'intérieur du triangle
	Point p2(5.0f, 5.0f); // À l'extérieur du triangle

	// Test de la fonction bsp
	bool result1 = Point::bsp(a, b, c, p1);
	bool result2 = Point::bsp(a, b, c, p2);

if (result1) {
        std::cout << "Point p1 (2.5, 2.5) is inside the triangle." << std::endl;
    } else {
        std::cout << "Point p1 (2.5, 2.5) is outside the triangle." << std::endl;
    }

    if (result2) {
        std::cout << "Point p2 (5.0, 5.0) is inside the triangle." << std::endl;
    } else {
        std::cout << "Point p2 (5.0, 5.0) is outside the triangle." << std::endl;
    }
	return (0);
}