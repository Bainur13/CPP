/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:46:48 by udumas            #+#    #+#             */
/*   Updated: 2024/08/29 18:03:34 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Bill_clap_name"), ScavTrap(), FragTrap()
{
	_diamondName = "Bill";
	_health = FragTrap::_health;
	_energy = ScavTrap::_energy;
	_attack = FragTrap::_attack;
	std::cout << "DiamondTrap default constructor, name: " << _diamondName << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
	ScavTrap(), FragTrap()
{
    _diamondName = name;
	_health = FragTrap::_health;
	_energy = ScavTrap::_energy;
	_attack = FragTrap::_attack;
	std::cout << "DiamondTrap constructor, name: " << _diamondName << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &to_cpy) : ClapTrap(to_cpy),
	ScavTrap(to_cpy), FragTrap(to_cpy)
{
    _diamondName = to_cpy._diamondName;
	std::cout << "DiamondTrap default constructor, name: " << _diamondName << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor, name: " << _diamondName << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &target)
{
    _name = target._name;
    _health = target._health;
    _attack = target._attack;
    _energy = target._energy;
    _diamondName = target._diamondName;
    std::cout << "DiamondTrap assignation operator called" << std::endl;
    return (*this);
}

void DiamondTrap::attack(const std::string &opponent) 
{
    ScavTrap::attack(opponent);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	if (this->_health == 0)
	{
		std::cout << "DiamondTrap " << this->_name << " can't be less than 0" << std::endl;
		return ;
	}
	this->_health = this->_health - amount;
	if (this->_health < 0)
		this->_health = 0;
	std::cout << "DiamondTrap " << this->_name << " took " << amount << " of damage." << std::endl;
	std::cout << this->_name << " is now " << this->_health << "." << std::endl;
	return ;
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	int amount_healed;

	amount_healed = 0;
	if (this->_health == 100)
	{
		std::cout << "Already maximum health" << std::endl;
		return ;
	}
	if (this->_energy == 0)
	{
		std::cout << "No more energy left" << std::endl;
		return ;
	}
	while (this->_health <= 100 && this->_energy > 0 && amount > 0)
	{
		this->_health++;
		this->_energy--;
		amount--;
		amount_healed++;
	}
	std::cout << "DiamondTrap " << this->_name << " healed for " << amount_healed << " health point" << std::endl;
	std::cout << "DiamondTrap " << this->_name << " health = " << this->_health << " and energy = " << this->_energy << std::endl;
	return ;
}

void DiamondTrap::whoAmI()
{
    std::cout << "My clapTrap name is : " << ClapTrap::_name << std::endl;
    std::cout << "But my real name is : " << DiamondTrap::_diamondName << std::endl;
    return ;
}


