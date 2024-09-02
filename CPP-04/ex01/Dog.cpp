/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:29:44 by udumas            #+#    #+#             */
/*   Updated: 2024/08/29 19:31:52 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _name("WildDog")
{
    std::cout << "New born wild Dog. Welcome !!" << std::endl;
}

Dog::Dog(const std::string &name) : Animal("Dog"), _name(name)
{
    std::cout << "New born Dog named " << name << ". Welcome !!" << std::endl; 
}

Dog::Dog(const Dog &to_cpy) : Animal(to_cpy), _name(to_cpy._name)
{
    std::cout << "Dog : " << _name << ", has been cloned correctly" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog : " << _name << ", Has leaved us." << std::endl;
}

Dog &Dog::operator=(const Dog &to_cpy)
{
    _type = to_cpy._type;
    std::cout << "Dog " << _name << " looks now the same as Dog " << to_cpy._name << std::endl;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Wouf Wouf" << std::endl;    
}

