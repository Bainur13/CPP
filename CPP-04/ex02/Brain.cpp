/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:07:04 by udumas            #+#    #+#             */
/*   Updated: 2024/09/09 17:11:24 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	int	i;

	i = 0;
	_ideas = new std::string[100];
	while (i < 100)
	{
		_ideas[i] = "";
		i++;
	}
	return ;
}

Brain::Brain(const Brain &to_cpy)
{
	int	i;

	i = 0;
	_ideas = new std::string[100];
	while (i < 100)
	{
		_ideas[i] = to_cpy._ideas[i];
		i++;
	}
	return ;
}

Brain::~Brain()
{
	delete[] _ideas;
	return ;
}

Brain &Brain::operator=(const Brain &to_cpy)
{
	int	i;

	i = 0;
	if (this != &to_cpy)
	{
		delete[] _ideas;
		_ideas = new std::string[100];
		while (i < 100)
		{
			_ideas[i] = to_cpy._ideas[i];
			i++;
		}
	}
	return (*this);
}

void Brain::set_ideas(std::string ideas, int index)
{
	if (index > 100 || index < 1)
	{
		std::cout << "Wrong index ! [1-100]";
		return ;
	}
	this->_ideas[index] = ideas;
	return ;
}

std::string Brain::get_ideas(int index)
{
	if (index > 100 || index < 1)
	{
		std::cout << "Wrong index ! [1-100]" << std::endl;
		return ("");
	}
	if (this->_ideas[index] == "")
	{
		return ("So deep over here, fill the void...");
	}
	return (this->_ideas[index]);
}
