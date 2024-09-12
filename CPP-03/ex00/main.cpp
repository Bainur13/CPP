/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:33:32 by udumas            #+#    #+#             */
/*   Updated: 2024/09/12 19:24:35 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap newTrap("Raoul");
    
    newTrap.attack("Bouffon");
    newTrap.attack("Bouffon");
    newTrap.takeDamage(10);
    newTrap.takeDamage(10);
    newTrap.beRepaired(10);
    newTrap.attack("Bouffon");
    return (0);
}
