/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:31:06 by bainur            #+#    #+#             */
/*   Updated: 2024/09/12 19:10:11 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("")
{
    return ;
}

AMateria::AMateria(std::string const &new_type) : _type(new_type)
{
    return ;
}

AMateria::AMateria(AMateria const &to_cpy)
{
    this->_type = to_cpy._type;
}

AMateria &AMateria::operator=(AMateria const &to_cpy)
{
    if (this == &to_cpy)
        return (*this);
    *this = to_cpy;
    return (*this);
}

AMateria::~AMateria()
{
    return ;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "Nothing to use on " << &target << std::endl << std::endl;
}

std::string const &AMateria::getType() const
{
    if (_type == "")
        std::cout << "No type in the Materia" << std::endl;
    return (_type);
}
