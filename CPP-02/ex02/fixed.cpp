/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:38:33 by udumas            #+#    #+#             */
/*   Updated: 2024/08/29 17:26:26 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

int	move_point(int base, int pow)
{
	int	render;

	render = base;
	if (pow == 0)
		return (1);
	if (pow == 1)
	{
		return (2);
	}
	while (pow > 1)
	{
		render = render * base;
		pow--;
	}
	return (render);
}

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = other.getRawBits();
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(move_point(2, _bit) * f);
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = move_point(2, _bit) * i;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
	return ;
}

float Fixed::toFloat(void) const
{
	return (float)(this->_value) / move_point(2, 8);
}

int Fixed::toInt(void) const
{
	return (this->_value / move_point(2, 8));
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a._value < b._value)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a._value < b._value)
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a._value > b._value)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a._value > b._value)
		return (a);
	else
		return (b);
}

Fixed &Fixed::operator=(const Fixed &to_copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = to_copy.getRawBits();
	return (*this);
}

float Fixed::operator+(const Fixed &rhs) const
{
	float a;
	float b;

	a = this->toFloat();
	b = rhs.toFloat();
	return (a + b);
}

float Fixed::operator-(const Fixed &rhs) const
{
	float a;
	float b;

	a = this->toFloat();
	b = rhs.toFloat();
	return (a - b);
}

Fixed &Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed old(*this);
	this->_value++;
	return (old);
}

Fixed Fixed::operator--(int)
{
	Fixed old(*this);
	this->_value--;
	return (old);
}

Fixed &Fixed::operator--()
{
	this->_value--;
	return (*this);
}

float Fixed::operator*(const Fixed &rhs) const
{
	float a;
	float b;

	a = this->toFloat();
	b = rhs.toFloat();
	return (a * b);
}

float Fixed::operator/(const Fixed &rhs) const
{
	float a;
	float b;

	a = this->toFloat();
	b = rhs.toFloat();
	return (a / b);
}

bool Fixed::operator>(const Fixed &rhs) const
{
	if (this->_value > rhs._value)
		return (1);
	return (0);
}

bool Fixed::operator<(const Fixed &rhs) const
{
	if (this->_value < rhs._value)
		return (1);
	return (0);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	if (this->_value >= rhs._value)
		return (1);
	return (0);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	if (this->_value <= rhs._value)
		return (1);
	return (0);
}

bool Fixed::operator==(const Fixed &rhs) const
{
	if (this->_value == rhs._value)
		return (1);
	return (0);
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	if (this->_value != rhs._value)
		return (1);
	return (0);
}

std::ostream &operator<<(std::ostream &o, Fixed const &cur)
{
	o << cur.toFloat();
	return (o);
}
