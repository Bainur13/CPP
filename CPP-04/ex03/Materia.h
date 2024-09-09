/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bainur <bainur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:28:54 by bainur            #+#    #+#             */
/*   Updated: 2024/09/08 20:26:50 by bainur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_HPP
#define MATERIA_HPP

#include <iostream>
#include <string>

class AMateria
{
    protected:
    
    public:
        AMateria(std::string const &new_type);

        std::string const &getType() const; //return the materia type
        
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};
#endif