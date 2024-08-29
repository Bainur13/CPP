/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:33:32 by udumas            #+#    #+#             */
/*   Updated: 2024/08/29 13:46:39 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap newTrap("Raoul");
    ScavTrap newScavTrap("Albert");
    ScavTrap robot1(newScavTrap);
    newScavTrap.guardGate();
    newScavTrap.attack("Bouffon");
    newScavTrap.takeDamage(10);
    newScavTrap.beRepaired(10);
    
    return (0);
}