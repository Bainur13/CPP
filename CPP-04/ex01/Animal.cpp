/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:17:13 by udumas            #+#    #+#             */
/*   Updated: 2024/08/29 19:32:08 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("NA")
{
    std::cout << "New animal without type" << std::endl;
}

Animal::Animal(const std::string &type) : _type(type)
{
    std::cout << type << " type of animal created" << std::endl;
}

Animal::Animal(const Animal &to_cpy) : _type(to_cpy._type)
{
    std::cout << "Cloning animal type " << _type << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal disparition : " << _type << std::endl; 
}

Animal &Animal::operator=(const Animal &to_cpy)
{
    _type = to_cpy._type;
    std::cout << "Assignation of new animal type " << _type << std::endl;
    return (*this);
}

std::string Animal::getType() const
{
    return (_type);
}

void Animal::setType(std::string &new_type)
{
    _type = new_type;
    return ;
}

void Animal::makeSound() const
{
    std::cout << "Weird noise" << std::endl;
}