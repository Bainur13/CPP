/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:22:09 by udumas            #+#    #+#             */
/*   Updated: 2024/09/09 17:35:39 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	std::cout << "TEST PRINCIPAL :" << std::endl;
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	delete j; // should not create a leak
	delete i;

	std::cout << std::endl << std::endl;
	std::cout << "TEST CREATION DE DEUX ANIMAUX CHAT ET CHIEN" << std::endl;
	Animal *animals[2];

	animals[0] = new Dog("Jerry");
	animals[1] = new Cat("Patrick");

	animals[0]->makeSound();
	animals[1]->makeSound();

	std::cout << "TEST BRAIN ET COPIE PROFONDE" << std::endl;

	Brain *a = animals[0]->get_brain();
	Brain *b = animals[1]->get_brain();
	
	a->set_ideas("la mula", 1);
	b->set_ideas("moulaga", 1);

	a->set_ideas("raton dans la street", 2);
	b->set_ideas("c pas des lols", 2);

	std::cout << animals[0]->get_brain()->get_ideas(1) << std::endl;
	std::cout << animals[1]->get_brain()->get_ideas(1) << std::endl;

	std::cout << animals[0]->get_brain()->get_ideas(2) << std::endl;
	std::cout << animals[1]->get_brain()->get_ideas(2) << std::endl;

	Brain *echo = new Brain(*a);
	*a = *b;

	std::cout << animals[0]->get_brain()->get_ideas(1) << std::endl;
	std::cout << animals[1]->get_brain()->get_ideas(1) << std::endl;
	std::cout << echo->get_ideas(1) << std::endl;
	
	std::cout << animals[0]->get_brain()->get_ideas(2) << std::endl;
	std::cout << animals[1]->get_brain()->get_ideas(2) << std::endl;
	std::cout << echo->get_ideas(2) << std::endl;

	delete animals[0];
	delete animals[1];
	delete echo;
	
	std::cout << "COPIE PROFONDE DOG/DOG CAT/CAT" << std::endl;
	Dog *o = new Dog();
	Dog *l = new Dog();

	o->get_brain()->set_ideas("c pas des lols", 1);
	o->get_brain()->set_ideas("le temps des cerises", 2);
	
	std::cout << o->get_brain()->get_ideas(1) << std::endl;
	std::cout << o->get_brain()->get_ideas(2) << std::endl;
	
	
	*l = *o;

	std::cout << o->get_brain()->get_ideas(1) << std::endl;
	std::cout << l->get_brain()->get_ideas(1) << std::endl;

	delete(o);
	delete(l);

	Cat *k = new Cat();
	Cat *n = new Cat();
	
	k->get_brain()->set_ideas("c pas des lols", 1);
		
	std::cout << k->get_brain()->get_ideas(1) << std::endl;
	
	Cat *felix = new Cat(*k);
	*n = *k;

	std::cout << k->get_brain()->get_ideas(1) << std::endl;
	std::cout << n->get_brain()->get_ideas(1) << std::endl;
	std::cout << felix->get_brain()->get_ideas(1) << std::endl;
	delete(k);
	delete(n);
	delete(felix);
	return (0);
}