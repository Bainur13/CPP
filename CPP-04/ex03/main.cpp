/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:34:21 by udumas            #+#    #+#             */
/*   Updated: 2024/09/12 19:00:39 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	// {
	// 	IMateriaSource* src = new MateriaSource();
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Cure());
	// 	ICharacter* me = new Character("me");
	// 	AMateria* tmp;
	// 	tmp = src->createMateria("ice");
	// 	me->equip(tmp);
	// 	tmp = src->createMateria("cure");
	// 	me->equip(tmp);
	// 	ICharacter* bob = new Character("bob");
	// 	me->use(0, *bob);
	// 	me->use(1, *bob);
	// 	std::cout << std::endl;

	// 	delete bob;
	// 	delete me;
	// 	delete src;
	// }
	// {
	// 	std::cout << "1. Create new MateriaSource and learn materias (check maximum too):" << std::endl;
	// 	IMateriaSource* src = new MateriaSource();
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Cure());
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Cure());
	// 	AMateria *mat = new Cure();
	// 	src->learnMateria(mat);
	// 	std::cout << std::endl;
		
	// 	std::cout << "2. Create 2 new characters and test deep copy:" << std::endl;
	// 	Character *dur0 = new Character("Alice");
	// 	ICharacter *dur1 = new Character(*dur0);
	// 	delete dur0;
	// 	delete dur1;
	// 	std::cout << std::endl;

	// 	std::cout << "3. Create materias and equip them (also check unknown materias):" << std::endl;
	// 	AMateria* tmp;
	// 	ICharacter *dur2 = new Character("Alice");
	// 	tmp = src->createMateria("ice");
	// 	dur2->equip(tmp);
	// 	tmp = src->createMateria("cure");
	// 	dur2->equip(tmp);
	// 	tmp = src->createMateria("hi");
	// 	dur2->equip(tmp);
	// 	delete src;
	// 	std::cout << std::endl;

	// 	std::cout << "4. Check maximum equipped too:" << std::endl;
	// 	AMateria *cure = new Cure();
	// 	AMateria *ice = new Ice();
	// 	dur2->equip(cure);
	// 	dur2->equip(cure);
	// 	dur2->equip(ice);
	// 	dur2->unequip(2);
	// 	dur2->unequip(2);
	// 	dur2->unequip(6);
	// 	std::cout << std::endl;

	// 	std::cout << "5. Use materias on new chacarter:" << std::endl;
	// 	ICharacter* bob = new Character("Bob");
	// 	dur2->use(0, *bob);
	// 	dur2->use(1, *bob);
	// 	dur2->use(2, *bob);
	// 	dur2->use(6, *bob);
	// 	dur2->use(-4, *bob);
	// 	dur2->use(3, *bob);
	// 	delete bob;
	// 	std::cout << std::endl;

	// 	delete dur2;

	// 	ft_lstDestroy();
	// 	return (0); 
	// }

	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		ICharacter *me = new Character("me");
		AMateria *tmp;
		tmp = src->createMateria("poulet");
		tmp = src->createMateria("ice");
		me->equip(tmp);
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		delete (tmp);
		ICharacter *bob = new Character("bob");
		me->unequip(0);
		me->unequip(3);
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(5, *bob);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		me->use(0, *bob);
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << std::endl << "Test copie profonde character :" << std::endl << std::endl;
		Character *me = new Character("me");
		Character *bob = new Character("loubard");
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		me->use(0, *bob);
		*me = *bob;
		me->use(0, *bob);
		delete bob;
		delete me;
		delete src;
		ft_lstDestroy();		
	}
	{
		std::cout << std::endl << "Test copie profonde MateriaSource :" << std::endl << std::endl;
		MateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		MateriaSource *src_new = new MateriaSource();
		*src_new = *src;
		Character *me = new Character("me");
		AMateria *tmp;
		tmp = src_new->createMateria("ice");
		me->equip(tmp);
		me->use(0, *me);
		delete me;
		delete src;
		delete src_new;
	}
	
}