/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:29:07 by udumas            #+#    #+#             */
/*   Updated: 2024/09/12 18:55:05 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"

Character::Character() : _name("Unknown")
{
	_inv[0] = NULL;
	_inv[1] = NULL;
	_inv[2] = NULL;
	_inv[3] = NULL;
}

Character::Character(std::string const &name) : _name(name)
{
	_inv[0] = NULL;
	_inv[1] = NULL;
	_inv[2] = NULL;
	_inv[3] = NULL;
}

Character &Character::operator=(const Character &to_cpy)
{
	int	i;

	if (this == &to_cpy)
		return (*this);
	i = 0;
	while (i < 4)
	{
		if (_inv[i] != nullptr)
			delete (_inv[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
        if (to_cpy._inv[i])
		    _inv[i] = to_cpy._inv[i]->clone();
        else
            _inv[i] = nullptr;
		i++;
	}
	_name = to_cpy._name;
	return (*this);
}

Character::Character(Character const &to_cpy) : _name(to_cpy._name)
{
	_inv[0] = to_cpy._inv[0];
	_inv[1] = to_cpy._inv[1];
	_inv[2] = to_cpy._inv[2];
	_inv[3] = to_cpy._inv[3];
}

Character::~Character()
{
	int	i;

	i = 0;
    std::cout << "Destroying " << _name << std::endl;
	while (i < 4)
	{
		if (_inv[i] != nullptr)
			delete (_inv[i]);
		i++;
	}
	return ;
}

std::string const &Character::getName() const
{
	return (_name);
}

int alreadyInInv(AMateria *inv[4], AMateria *m)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (inv[i] == m)
            return (1);
        i++;
    }
    return (0);
}

void Character::equip(AMateria *m)
{
	int	i;

	i = 0;
    if (alreadyInInv(_inv, m))
    {
        std::cout << "Item already in the inventory" << std::endl;
        return ;
    }
	while (i < 4)
	{
		if (_inv[i] == nullptr)
		{
            std::cout << _name << " equiped " << m->getType() << std::endl;
			_inv[i] = m;
			return ;
		}
		i++;
	}
    std::cout << "Too much item in inventory" << std::endl;
	return ;
}

void Character::unequip(int idx)
{
	if ((idx < 0 || idx >= 4) || !_inv[idx])
		return ;
	else
	{
		std::cout << "Unequip " << _inv[idx]->getType() << " from " << _name << std::endl;
		ft_lstAddback(_inv[idx]);
		_inv[idx] = nullptr;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && _inv[idx] != nullptr)
		_inv[idx]->use(target);
    else if (idx >= 0 && idx < 4)
        std::cout << "Nothing to use on slot " << idx << std::endl;
    else
        std::cout << "Not valid emplacement" << std::endl;
}
