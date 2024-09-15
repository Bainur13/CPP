/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:30:35 by udumas            #+#    #+#             */
/*   Updated: 2024/09/12 19:27:32 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    std::cout << "I am Harl" << std::endl;
    return ;
}

Harl::~Harl()
{
    std::cout << "I am leaving" << std::endl;
    return ;
}
void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-";
	std::cout << "ketchup burger.I really do !" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough!";
	std::cout << "If you did I would not have to ask for it!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years";
	std::cout << "and you just started working here last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable. I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	int i;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[4])(void) = {&Harl::debug, &Harl::info,
		&Harl::warning, &Harl::error};
    
    i = 0;
    while (i < 4)
    {
        if (levels[i] == level)
        {
            (this->*functions[i])();
            return ;
        }
        i++;
    }
    return ;
}
