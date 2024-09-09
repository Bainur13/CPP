/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:17:13 by udumas            #+#    #+#             */
/*   Updated: 2024/09/09 17:44:32 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"

AAnimal::AAnimal() : _type("NA")
{
	std::cout << "New animal without type" << std::endl;
}

AAnimal::AAnimal(const std::string &type) : _type(type)
{
	std::cout << type << " type of animal created" << std::endl;
}

AAnimal::AAnimal(const AAnimal &to_cpy) : _type(to_cpy._type)
{
	std::cout << "Cloning animal type " << _type << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal disparition : " << _type << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &to_cpy)
{
	if (this != &to_cpy)
	{
		_type = to_cpy._type;
		std::cout << "Assignation of new animal type " << _type << std::endl;
	}
	return (*this);
}

std::string AAnimal::getType() const
{
	return (_type);
}

void AAnimal::setType(std::string &new_type)
{
	_type = new_type;
	return ;
}

