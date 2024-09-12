/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:57:29 by bainur            #+#    #+#             */
/*   Updated: 2024/09/12 19:09:56 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(Ice const &to_cpy);
        
        ~Ice();
        
        Ice &operator=(Ice const &to_cpy);
        
        std::string const &getType() const;

        virtual AMateria *clone() const;
        virtual void use(ICharacter &target);
};

#endif
