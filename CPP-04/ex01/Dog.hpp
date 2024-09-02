/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:49:05 by udumas            #+#    #+#             */
/*   Updated: 2024/09/02 17:11:00 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
  public:
	Dog();
	Dog(const Dog &to_cpy);
	Dog(const std::string &name);

	~Dog();

	Dog &operator=(const Dog &to_cpy);

    void makeSound() const;

  private:
	const std::string _name;
	Brain *_brain;
};

#endif