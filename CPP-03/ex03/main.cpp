/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:33:32 by udumas            #+#    #+#             */
/*   Updated: 2024/09/12 19:23:03 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap ironGeant1("echo");
    ironGeant1.attack("boloss");
    ironGeant1.takeDamage(10);
    ironGeant1.beRepaired(10);
    ironGeant1.highFivesGuys();
    ironGeant1.guardGate();
    ironGeant1.whoAmI();
    return (0);
}
