/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bainur <bainur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:07:02 by bainur            #+#    #+#             */
/*   Updated: 2024/09/14 11:08:45 by bainur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
    public:
        Weapon(std::string type);
        ~Weapon();
        const std::string &getType() const;
        void setType(std::string type);

    private:
        std::string _type;
};

#endif
