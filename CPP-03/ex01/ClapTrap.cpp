/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:34:10 by udumas            #+#    #+#             */
/*   Updated: 2024/09/12 19:24:11 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Bill"), _health(10), _energy(10), _attack(0)
{
	std::cout << "Basic ClapTrap created, hello Bill." << std::endl;
	return ;
}
ClapTrap::ClapTrap(std::string name) : _name(name), _health(10), _energy(10),
	_attack(0)
{
	std::cout << "Claptrap ready, name : " << name << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &to_cpy)
    : _name(to_cpy._name), _health(to_cpy._health), _energy(to_cpy._energy), _attack(to_cpy._attack)
{
	std::cout << "ClapTrap copy done" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap disabled, name : " << this->_name << std::endl;
	return ;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &to_cpy)
{
    if (this == &to_cpy)
        return *this;
    _name = to_cpy._name;
    _health = to_cpy._health;
    _energy = to_cpy._energy;
    _attack = to_cpy._attack;
    std::cout << "ClapTrap assignment operator called" << std::endl;
    return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_health == 0)
	{
		std::cout << "ClapTrap...." << this->_name << " need repare" << std::endl;
		return ;
	}
	if (this->_energy == 0)
	{
		std::cout << "ClapTrap...." << this->_name << " exhausted" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ",";
	std::cout << "causing " << this->_attack << " points of damage!" << std::endl;
	this->_energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_health == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't be less than 0" << std::endl;
		return ;
	}
	this->_health = this->_health - amount;
	if (this->_health < 0)
		this->_health = 0;
	std::cout << "ClapTrap " << this->_name << " took " << amount << " of damage." << std::endl;
	std::cout << this->_name << " is now " << this->_health << "." << std::endl;
	return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	int amount_healed;

	amount_healed = 0;
	if (this->_health == 10)
	{
		std::cout << "Already maximum health" << std::endl;
		return ;
	}
	if (this->_energy == 0)
	{
		std::cout << "No more energy left" << std::endl;
		return ;
	}
	while (this->_health <= 10 && this->_energy > 0 && amount > 0)
	{
		this->_health++;
		this->_energy--;
		amount--;
		amount_healed++;
	}
	std::cout << "ClapTrap " << this->_name << " healed for " << amount_healed << " health point" << std::endl;
	std::cout << "ClapTrap " << this->_name << " health = " << this->_health << " and energy = " << this->_energy << std::endl;
	return ;
}
