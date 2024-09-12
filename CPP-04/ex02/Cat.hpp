/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:26:04 by udumas            #+#    #+#             */
/*   Updated: 2024/09/12 19:21:07 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
  public:
	Cat();
	Cat(const Cat &to_cpy);
	Cat(const std::string &name);

	~Cat();

	Cat &operator=(const Cat &to_cpy);

	void makeSound() const;

	Brain *get_brain() const;


  private:
	const std::string _name;
	Brain *_brain;
};

#endif
