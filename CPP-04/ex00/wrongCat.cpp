/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:20:49 by udumas            #+#    #+#             */
/*   Updated: 2024/08/29 20:25:37 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrongCat.hpp"

WrongCat::WrongCat() : Animal("WrongCat"), _name("WildWrongCat")
{
    std::cout << "New born wild Wrongcat. Welcome !!" << std::endl;
}

WrongCat::WrongCat(const std::string &name) : Animal("WrongCat"), _name(name)
{
    std::cout << "New born WrongCat named " << name << ". Welcome !!" << std::endl; 
}

WrongCat::WrongCat(const WrongCat &to_cpy) : Animal(to_cpy), _name(to_cpy._name)
{
    std::cout << "WrongCat : " << _name << ", has been cloned correctly" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat : " << _name << ", Has leaved us." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &to_cpy)
{
    _type = to_cpy._type;
    std::cout << "WrongCat " << _name << " looks now the same as Wrongcat " << to_cpy._name << std::endl;
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "Miaou" << std::endl;
}

