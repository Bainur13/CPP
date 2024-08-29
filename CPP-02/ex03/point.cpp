/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:55:46 by udumas            #+#    #+#             */
/*   Updated: 2024/08/29 17:31:19 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.hpp"

float	area(Point const &p1, Point const &p2, Point const &p3)
{
	return (std::abs((p1.getX() * (p2.getY() - p3.getY()) + p2.getX()
				* (p3.getY() - p1.getY()) + p3.getX() * (p1.getY() - p2.getY()))
			/ 2.0));
}

bool Point::bsp(Point const a, Point const b, Point const c, Point const p)
{
	float	area_abc;
	float	area_pbc;
	float	area_apc;
	float	area_abp;

	area_abc = area(a, b, c);
	area_pbc = area(p, b, c);
	area_apc = area(a, p, c);
	area_abp = area(a, b, p);
	if (area_pbc == 0 || area_apc == 0 || area_abp == 0)
		return (false);
	if (area_abc == (area_pbc + area_apc + area_abp))
		return (true);
	else
		return (false);
}

Point::Point() : _x(), _y()
{
	std::cout << "Basic constructor called" << std::endl;
}

float Point::getX() const
{
	return (this->_x.toFloat());
}

float Point::getY() const
{
	return (this->_y.toFloat());
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
	std::cout << "Float constructor called" << std::endl;
}

Point::Point(Point const &other) : _x(other._x), _y(other._y)
{
	std::cout << "Copy constructor called" << std::endl;
}

Point::~Point()
{
	std::cout << "Point destructor called" << std::endl;
}

Point &Point::operator=(const Point &to_cpy)
{
	to_cpy.getX();
	std::cout << "Point copy assignement operator called" << std::endl;
	return (*this);
}
