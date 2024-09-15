/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:27:50 by bainur            #+#    #+#             */
/*   Updated: 2024/09/15 15:29:16 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
    std::string _name;

public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    
    void announce();
    void set_name(std::string name);
    std::string get_name();
};

Zombie *zombieHorde(int N, std::string name);

#endif
