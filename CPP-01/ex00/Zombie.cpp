/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:29:47 by bainur            #+#    #+#             */
/*   Updated: 2024/09/15 15:28:12 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name("default")
{
    std::cout << "Zombie created : " << _name << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << "Zombie created : " << _name << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie destroyed : " << _name << std::endl;
}

void Zombie::announce()
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
    _name = name;
}

std::string Zombie::get_name()
{
    return (_name);
}
