/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:12:43 by udumas            #+#    #+#             */
/*   Updated: 2024/09/12 19:08:42 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(const Animal &to_cpy);
        Animal(const std::string &type);

        ~Animal();
        
        Animal &operator=(const Animal &to_cpy);

        std::string getType() const;
        void setType(std::string &);

        virtual void makeSound() const;
};

#endif
