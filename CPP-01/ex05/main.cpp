/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:28:26 by udumas            #+#    #+#             */
/*   Updated: 2024/09/12 19:27:27 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl harl;

	std::cout << std::endl << "Asking for Harl to debug :" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl << "Asking for Harl to display info :" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl << "Asking for Harl to warn us :" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl << "Asking for Harl to display error message :" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;
	return (0);
}
