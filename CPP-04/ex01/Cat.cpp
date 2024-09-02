/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:29:44 by udumas            #+#    #+#             */
/*   Updated: 2024/09/02 17:50:42 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _name("WildCat")
{
    _brain = new Brain;
    std::cout << "New born wild cat. Welcome !!" << std::endl;
}

Cat::Cat(const std::string &name) : Animal("Cat"), _name(name)
{
    _brain = new Brain;
    std::cout << "New born Cat named " << name << ". Welcome !!" << std::endl; 
}

Cat::Cat(const Cat &to_cpy) : Animal(to_cpy), _name(to_cpy._name)
{
    _brain = new Brain(*to_cpy._brain);
    std::cout << "Cat : " << _name << ", has been cloned correctly" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat : " << _name << ", Has leaved us." << std::endl;
}

Cat &Cat::operator=(const Cat &to_cpy)
{
    _type = to_cpy._type;
    std::cout << "Cat " << _name << " looks now the same as cat " << to_cpy._name << std::endl;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Miaou" << std::endl;
}

