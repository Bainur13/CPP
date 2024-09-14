/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bainur <bainur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:27:50 by bainur            #+#    #+#             */
/*   Updated: 2024/09/13 16:37:51 by bainur           ###   ########.fr       */
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

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif