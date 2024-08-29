/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 22:57:14 by bainur            #+#    #+#             */
/*   Updated: 2024/08/29 16:44:44 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conciliator.h"

int	main(void)
{
	Phonebook Phonebook;
	std::string buffer;
	int number_contact;
	int i;

	i = 0;
	number_contact = 0;
	while (1)
	{
		std::cout << "Phonebook > ";
		std::getline(std::cin, buffer);
		if (buffer == "ADD")
		{
			Phonebook.list_contacts[i] = ft_put_contact_info();
			i++;
            if (number_contact < 8)
			    number_contact++;
		}
		else if (buffer == "SEARCH")
		{
			ft_show_contact(Phonebook.list_contacts, number_contact);
		}
		else if (buffer == "EXIT")
			break ;
		else
			std::cout << "Wrong command" << std::endl;
		if (i == 8)
			i = 0;
	}
	return (0);
}