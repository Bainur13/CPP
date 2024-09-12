/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:12:43 by udumas            #+#    #+#             */
/*   Updated: 2024/09/12 19:21:43 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Brain;
class Dog;
class Cat;

class Animal
{
    protected:
        std::string _type;

    public:
        Animal();
        Animal(const Animal &to_cpy);
        Animal(const std::string &type);

        virtual ~Animal();
        
        Animal &operator=(const Animal &to_cpy);

        std::string getType() const;
        void setType(std::string &);

        virtual void makeSound() const;
        virtual Brain *get_brain() const = 0;
};

#endif
