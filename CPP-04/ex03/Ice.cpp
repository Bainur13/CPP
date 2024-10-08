/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:14:10 by bainur            #+#    #+#             */
/*   Updated: 2024/09/12 15:33:56 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	return ;
}

Ice::Ice(Ice const &to_cpy)
{
	_type = to_cpy.getType();
	return ;
}

Ice::~Ice()
{
	return ;
}

Ice &Ice::operator=(Ice const &to_cpy)
{
	if (this == &to_cpy)
		return (*this);
	return (*this);
}

std::string const &Ice::getType() const
{
	return (_type);
}

AMateria *Ice::clone() const
{
	Ice *clone_ice = new Ice();
	return (clone_ice);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "*";
	std::cout << std::endl;
}
