/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:29:50 by udumas            #+#    #+#             */
/*   Updated: 2024/09/12 19:09:10 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("NA")
{
    std::cout << "New WrongAnimal without type" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type)
{
    std::cout << type << " type of WrongAnimal created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &to_cpy) : _type(to_cpy._type)
{
    std::cout << "Cloning WrongAnimal type " << _type << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal disparition : " << _type << std::endl; 
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &to_cpy)
{
    _type = to_cpy._type;
    std::cout << "Assignation of new WrongAnimal type " << _type << std::endl;
    return (*this);
}

std::string WrongAnimal::getType() const
{
    return (_type);
}

void WrongAnimal::setType(std::string &new_type)
{
    _type = new_type;
    return ;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Weird noise" << std::endl;
}
