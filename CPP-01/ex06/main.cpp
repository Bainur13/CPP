/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:28:26 by udumas            #+#    #+#             */
/*   Updated: 2024/09/23 18:42:14 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int which_level(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	
	while (i < 4)
	{
		if (levels[i] == level)
			return (i);
		i++;
	}
	return (-1);
}
void filter_actions(std::string level, Harl harl)
{
	switch (which_level(level))
	{
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break;
		case -1:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

int	main(int ac, char **av)
{
	Harl harl;
	
	if (ac != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (1);
	}
	filter_actions(av[1], harl);
	return (0);
}
