/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:33:32 by udumas            #+#    #+#             */
/*   Updated: 2024/09/12 19:23:35 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap robot("North2");

    robot.attack("Bouffon");
    robot.takeDamage(10);
    robot.beRepaired(10);
    robot.highFivesGuys();
    return (0);
}
