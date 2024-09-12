/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:26:04 by udumas            #+#    #+#             */
/*   Updated: 2024/08/29 20:08:41 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
  public:
	WrongCat();
	WrongCat(const WrongCat &to_cpy);
	WrongCat(const std::string &name);

	~WrongCat();

	WrongCat &operator=(const WrongCat &to_cpy);

    void makeSound() const;
  private:
	const std::string _name;
};

#endif
