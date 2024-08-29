/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:35:41 by udumas            #+#    #+#             */
/*   Updated: 2024/08/29 14:45:25 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() 
{
    this->_health = 100;
    this->_energy = 50;
    this->_attack = 20;
    this->_guardGate = false;
    std::cout << "ScavTrap default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_health = 100;
    this->_energy = 50;
    this->_attack = 20;
    this->_guardGate = false;
    std::cout << "Scavtrap ready, name : " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &to_cpy)
{
    this->_name = to_cpy._name;
    this->_health = to_cpy._health;
    this->_energy = to_cpy._energy;
    this->_attack = to_cpy._attack;
    this->_guardGate = to_cpy._guardGate;
    std::cout << "ScavTrap copy done" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap disabled, name : " << this->_name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &to_cpy)
{
    if (this == &to_cpy)
        return *this;
    _name = to_cpy._name;
    _health = to_cpy._health;
    _energy = to_cpy._energy;
    _attack = to_cpy._attack;
    _guardGate = to_cpy._guardGate;
    std::cout << "ScavTrap assignment operator called" << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->_health == 0)
    {
        std::cout << "ScavTrap...." << this->_name << " need repare" << std::endl;
        return ;
    }
    if (this->_energy == 0)
    {
        std::cout << "ScavTrap...." << this->_name << " exhausted" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->_name << " attack " << target << ", causing " << this->_attack << " points of damage !" << std::endl;
    this->_energy -= 1;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_health == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't be less than 0" << std::endl;
		return ;
	}
	this->_health = this->_health - amount;
	if (this->_health < 0)
		this->_health = 0;
	std::cout << "ScavTrap " << this->_name << " took " << amount << " of damage." << std::endl;
	std::cout << this->_name << " is now " << this->_health << "." << std::endl;
	return ;
}

void ScavTrap::beRepaired(unsigned int amount)
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
	std::cout << "ScavTrap " << this->_name << " healed for " << amount_healed << " health point" << std::endl;
	std::cout << "ScavTrap " << this->_name << " health = " << this->_health << " and energy = " << this->_energy << std::endl;
	return ;
}

void ScavTrap::guardGate()
{
    if (this->_guardGate == true)
    {
        std::cout << "ScavTrap " << this->_name << " is already in Gate keeper mode" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->_name << " have enterred in Gate keeper mode" << std::endl;
    this->_guardGate = true;
}
