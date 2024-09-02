/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:07:04 by udumas            #+#    #+#             */
/*   Updated: 2024/09/02 16:46:29 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	int	i;

	i = 0;
	ideas = new std::string[100];
	while (i < 100)
	{
		ideas[i] = "";
		i++;
	}
	return ;
}

Brain::Brain(const Brain &to_cpy)
{
	int	i;

	i = 0;
	ideas = new std::string[100];
	while (i < 100)
	{
		ideas[i] = to_cpy.ideas[i];
		i++;
	}
	return ;
}

Brain::~Brain()
{
	delete this->ideas;
	return ;
}

Brain &Brain::operator=(const Brain &to_cpy)
{
	int i;

    i = 0;
    while (i < 100)
    {
        ideas[i] = to_cpy.ideas[i];
        i++;
    }
	return (*this);
}
