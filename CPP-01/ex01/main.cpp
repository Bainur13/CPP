/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:37:13 by bainur            #+#    #+#             */
/*   Updated: 2024/09/15 15:29:33 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *zombies = zombieHorde(5, "FRED");
    for (int i = 0; i < 5; i++)
        zombies[i].announce();
    delete[] zombies;

    return (0);
}
