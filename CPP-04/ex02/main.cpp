/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:22:09 by udumas            #+#    #+#             */
/*   Updated: 2024/09/15 16:24:33 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	// AAnimal *lol = new AAnimal();
	// lol->makeSound();

	AAnimal *catou = new Cat();
	catou->makeSound();

	// AAnimal doggo = Dog();
	// doggo->makeSound();

	delete(catou);
	return (0);
}
