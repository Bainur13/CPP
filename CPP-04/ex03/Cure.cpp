/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:57:10 by udumas            #+#    #+#             */
/*   Updated: 2024/09/15 16:33:15 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	return ;
}

Cure::Cure(Cure const &to_cpy)
{
	_type = to_cpy.getType();
	return ;
}

Cure::~Cure()
{
	return ;
}

Cure &Cure::operator=(Cure const &to_cpy)
{
	if (this == &to_cpy)
		return (*this);
	return (*this);
}

std::string const &Cure::getType() const
{
	return (_type);
}

AMateria *Cure::clone() const
{
	Cure *clone_cure = new Cure();
	return (clone_cure);
}

void Cure::use(ICharacter &target)
{
	std::cout << "Cure : * heals " << target.getName() << "’s wounds *";
	std::cout << std::endl;
}
