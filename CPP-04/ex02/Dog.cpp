/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:29:44 by udumas            #+#    #+#             */
/*   Updated: 2024/09/12 19:21:19 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"), _name("WildDog")
{
	_brain = new Brain;
	std::cout << "New born wild Dog. Welcome !!" << std::endl;
}

Dog::Dog(const std::string &name) : AAnimal("Dog"), _name(name)
{
	_brain = new Brain;
	std::cout << "New born Dog named " << name << ". Welcome !!" << std::endl;
}

Dog::Dog(const Dog &to_cpy) : AAnimal(to_cpy), _name(to_cpy._name)
{
	_brain = new Brain(*to_cpy._brain);
	std::cout << "Dog : " << _name << ", has been cloned correctly" << std::endl;
}

Dog::~Dog()
{
	delete	_brain;

	std::cout << "Dog : " << _name << ", Has leaved us." << std::endl;
}

Dog &Dog::operator=(const Dog &to_cpy)
{
	if (this != &to_cpy)
	{
		_type = to_cpy._type;
		if (_brain != to_cpy.get_brain())
		{
			delete(_brain);
			_brain = new Brain(*to_cpy._brain);
		}
		std::cout << "Dog " << _name << " looks now the same as Dog " << to_cpy._name << std::endl;
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Wouf Wouf" << std::endl;
}

Brain *Dog::get_brain() const
{
	return (_brain);
}
