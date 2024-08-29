/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:18:39 by udumas            #+#    #+#             */
/*   Updated: 2024/08/29 13:20:51 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->_health = 100;
    this->_energy = 100;
    this->_attack = 30;
    std::cout << "FragTrap default constructor" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_health = 100;
    this->_energy = 100;
    this->_attack = 30;
    std::cout << "FragTrap ready, name : " << name << std::endl;
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap disabled, name : " << this->_name << std::endl;
}

FragTrap::FragTrap(const FragTrap &to_cpy) :  ClapTrap(to_cpy)
{
    std::cout << "FragTrap copy done" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap &to_cpy)
{
    if (this == &to_cpy)
        return *this;
    _name = to_cpy._name;
    _health = to_cpy._health;
    _energy = to_cpy._energy;
    _attack = to_cpy._attack;
    std::cout << "FragTrap assignment operator called" << std::endl;
    return *this;
}

void FragTrap::attack(const std::string &target)
{
    if (this->_health == 0)
    {
        std::cout << "FragTrap...." << this->_name << " need repare" << std::endl;
        return ;
    }
    if (this->_energy == 0)
    {
        std::cout << "FragTrap...." << this->_name << " exhausted" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->_name << " attack " << target << ", causing " << this->_attack << " points of damage !" << std::endl;
    this->_energy -= 1;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (this->_health == 0)
	{
		std::cout << "FragTrap " << this->_name << " can't be less than 0" << std::endl;
		return ;
	}
	this->_health = this->_health - amount;
	if (this->_health < 0)
		this->_health = 0;
	std::cout << "FragTrap " << this->_name << " took " << amount << " of damage." << std::endl;
	std::cout << this->_name << " is now " << this->_health << "." << std::endl;
	return ;
}

void FragTrap::beRepaired(unsigned int amount)
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
	std::cout << "FragTrap " << this->_name << " healed for " << amount_healed << " health point" << std::endl;
	std::cout << "FragTrap " << this->_name << " health = " << this->_health << " and energy = " << this->_energy << std::endl;
	return ;
}

void FragTrap::highFivesGuys()
{
    std::cout << this->_name << " clap hands vigorously with you !" << std::endl;
}
