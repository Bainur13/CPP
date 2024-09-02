/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:26:04 by udumas            #+#    #+#             */
/*   Updated: 2024/09/02 17:11:09 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
  public:
	Cat();
	Cat(const Cat &to_cpy);
	Cat(const std::string &name);

	~Cat();

	Cat &operator=(const Cat &to_cpy);

    void makeSound() const;
  private:
	const std::string _name;
	Brain *_brain;
};

#endif