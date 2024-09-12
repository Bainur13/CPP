/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:28:54 by bainur            #+#    #+#             */
/*   Updated: 2024/09/12 19:09:44 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_HPP
#define MATERIA_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria();
        AMateria(std::string const &new_type);
        AMateria(AMateria const &to_cpy);

        virtual ~AMateria();

        AMateria &operator=(AMateria const &to_cpy);       
        std::string const &getType() const; //return the materia type
        
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif
