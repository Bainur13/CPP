/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:57:02 by udumas            #+#    #+#             */
/*   Updated: 2024/09/10 13:57:49 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(Cure const &to_cpy);
        
        ~Cure();
        
        Cure &operator=(Cure const &to_cpy);
        
        std::string const &getType() const;

        virtual AMateria *clone() const;
        virtual void use(ICharacter &target);
};

#endif