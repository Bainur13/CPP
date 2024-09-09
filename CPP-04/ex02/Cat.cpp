/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:29:44 by udumas            #+#    #+#             */
/*   Updated: 2024/09/09 17:45:24 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat"), _name("WildCat")
{
	_brain = new Brain;
	std::cout << "New born wild cat. Welcome !!" << std::endl;
}

Cat::Cat(const std::string &name) : AAnimal("Cat"), _name(name)
{
	_brain = new Brain;
	std::cout << "New born Cat named " << name << ". Welcome !!" << std::endl;
}

Cat::Cat(const Cat &to_cpy) : AAnimal(to_cpy), _name(to_cpy._name)
{
	_brain = new Brain(*to_cpy._brain);
	std::cout << "Cat : " << _name << ", has been cloned correctly" << std::endl;
}

Cat::~Cat()
{
	delete	_brain;
	std::cout << "Cat : " << _name << ", Has leaved us." << std::endl;
}

Cat &Cat::operator=(const Cat &to_cpy)
{
	if (this != &to_cpy)
	{
		_type = to_cpy._type;
		if (_brain != to_cpy.get_brain())
		{
			delete(_brain);
			_brain = new Brain(*to_cpy._brain);
		}
		std::cout << "Cat " << _name << " looks now the same as cat " << to_cpy._name << std::endl;
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}

Brain *Cat::get_brain() const
{
	return (_brain);
}
