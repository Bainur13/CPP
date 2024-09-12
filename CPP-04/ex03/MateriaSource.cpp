/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:56:45 by udumas            #+#    #+#             */
/*   Updated: 2024/09/12 18:05:00 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _stock() 
{
	_stock[0] = nullptr;
	_stock[1] = nullptr;
	_stock[2] = nullptr;
	_stock[3] = nullptr;
	std::cout << "New MateriaSource created" << std::endl;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &to_cpy) : _stock()
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (to_cpy._stock[i])
			_stock[i] = to_cpy._stock[i]->clone();
	}
	std::cout << "Copy over" << std::endl;
}

MateriaSource::~MateriaSource()
{
	int	i;

	i = 0;
    while (i < 4)
    {
        if (_stock[i] != nullptr)
            delete (_stock[i]);
        i++;
    }
    std::cout << "Erased Materia Source" << std::endl;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &to_cpy)
{
	int	i;
	
	i = 0;
    if (this == &to_cpy)
        return (*this);

    while (i < 4)
    {
        if (_stock[i] != nullptr)
            delete (_stock[i]);
        i++;
    }
    i = 0;
    while (i < 4)
    {
        if (to_cpy._stock[i] != nullptr)
            _stock[i] = to_cpy._stock[i]->clone();
        else
            _stock[i] = nullptr;
        i++;
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *to_learn)
{
	int	i;

	i = 0;
	if (to_learn == nullptr)
		return ;
	while (i < 4)
	{
		if (!_stock[i])
		{
			_stock[i] = to_learn;
			std::cout << "MateriaSource : learned " << to_learn->getType() << std::endl;
			return ;
		}
		i++;
	}
	delete (to_learn);
	std::cout << "No space available" << std::endl;
	return ;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (_stock[i] != nullptr)
		{
			if (_stock[i]->getType() == type)
			{
				std::cout << "Creating " << type << " materia" << std::endl;
				return (_stock[i]->clone());
			}
		}
		i++;
	}
	std::cout << "No " << type << " spell available" << std::endl;
	return (0);
}
