/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_list.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:01:45 by udumas            #+#    #+#             */
/*   Updated: 2024/09/12 16:43:44 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

t_floor* globalFloor = nullptr;

void	ft_lstAddback(AMateria *new_AMateria)
{
	t_floor	*travel;
	t_floor	*new_node;

	new_node = new t_floor;
	new_node->object = new_AMateria;
	new_node->next = NULL;
	travel = globalFloor;
	if (globalFloor == NULL)
	{
		globalFloor = new_node;
	}
	else
	{
		while (travel->next != NULL)
			travel = travel->next;
		travel->next = new_node;
	}
}

void	ft_lstDestroy()
{
	t_floor *tmp;

	if (globalFloor == NULL)
		return ;
	std::cout << "Destroying Floor" << std::endl;
	while (globalFloor != NULL)
	{
		tmp = globalFloor->next;
		delete globalFloor->object;
		delete globalFloor;
		globalFloor = tmp;
	}
	return ;
}
