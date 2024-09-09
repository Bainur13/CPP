/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:12:43 by udumas            #+#    #+#             */
/*   Updated: 2024/09/09 17:44:11 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Brain;
class Dog;
class Cat;

class AAnimal
{
    protected:
        std::string _type;

    public:
        AAnimal();
        AAnimal(const AAnimal &to_cpy);
        AAnimal(const std::string &type);

        virtual ~AAnimal();
        
        AAnimal &operator=(const AAnimal &to_cpy);

        std::string getType() const;
        void setType(std::string &);

        virtual void makeSound() const = 0;
};

#endif