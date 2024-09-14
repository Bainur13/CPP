/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bainur <bainur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:07:58 by bainur            #+#    #+#             */
/*   Updated: 2024/09/14 11:08:50 by bainur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
    std::cout << "Weapon created " << _type << std::endl;
}

Weapon::~Weapon()
{
    std::cout << "Weapon destroyed " << _type << std::endl;
}

const std::string &Weapon::getType() const
{
    return (_type);
}

void Weapon::setType(std::string type)
{
    _type = type;
}
