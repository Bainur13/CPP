/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bainur <bainur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:57:29 by bainur            #+#    #+#             */
/*   Updated: 2024/09/08 20:13:50 by bainur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include <string>
#include "Materia.h"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(Ice const &to_cpy);
        Ice &operator=(Ice const &to_cpy);
        ~Ice();
        
        std::string const &getType() const;

        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
}

#endif