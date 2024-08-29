/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:15:35 by bainur            #+#    #+#             */
/*   Updated: 2024/08/29 16:32:29 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conciliator.h"

contacts::contacts(void)
{
	return ;
}

contacts::~contacts(void)
{
	return ;
}
std::string contacts::get_firstName(void)
{
	return (this->first_name);
}

std::string contacts::get_lastName(void)
{
	return (this->last_name);
}

std::string contacts::get_nickName(void)
{
	return (this->nickname);
}

std::string contacts::get_phone(void)
{
	return (this->phone);
}

std::string contacts::get_secret(void)
{
	return (this->secret);
}

void contacts::set_firstName(std::string first_name)
{
    this->first_name = first_name;
}

void contacts::set_lastName(std::string last_name)
{
    this->last_name = last_name;
}

void contacts::set_nickName(std::string nickname)
{
    this->nickname = nickname;
}

void contacts::set_phone(std::string phone)
{
    this->phone = phone;
}

void contacts::set_secret(std::string secret)
{
    this->secret = secret;
}

contacts	ft_put_contact_info(void)
{
	contacts	contact;

	std::string buffer;
	std::cout << "New Contact" << std::endl;
	while (1)
	{
		std::cout << "First name = ";
		std::getline(std::cin, buffer);
		if (buffer == "")
		{
			std::cout << "Can not be empty" << std::endl;
			continue ;
		}
		if (ft_stringalpha(buffer) == 0)
		{
			std::cout << "Only alphabet characters" << std::endl;
			continue ;
		}
        contact.set_firstName(buffer);
		break ;
	}
	while (1)
	{
		std::cout << "Last name = ";
		std::getline(std::cin, buffer);
		if (buffer == "")
		{
			std::cout << "Can not be empty" << std::endl;
			continue ;
		}
		if (ft_stringalpha(buffer) == 0)
		{
			std::cout << "Only alphabet characters" << std::endl;
			continue ;
		}
        contact.set_lastName(buffer);
		break ;
	}
	while (1)
	{
		std::cout << "Nickname = ";
		std::getline(std::cin, buffer);
		if (buffer == "")
		{
			std::cout << "Can not be empty" << std::endl;
			continue ;
		}
		if (ft_stringalpha(buffer) == 0)
		{
			std::cout << "Only alphabet characters" << std::endl;
			continue ;
		}
        contact.set_nickName(buffer);
		break ;
	}
	while (1)
	{
		std::cout << "Phone Number = ";
		std::getline(std::cin, buffer);
		if (buffer == "")
		{
			std::cout << "Can not be empty" << std::endl;
			continue ;
		}
		if (ft_digit(buffer) == 0)
		{
			std::cout << "Only digit characters" << std::endl;
			continue ;
		}
        contact.set_phone(buffer);
		break ;
	}
	while (1)
	{
		std::cout << "Deepest secret = ";
		std::getline(std::cin, buffer);
		if (buffer == "")
		{
			std::cout << "Can not be empty" << std::endl;
			continue ;
		}
        contact.set_secret(buffer);
		break ;
	}
	return (contact);
}

void	print_info_right(std::string str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (j < 9 && j <= i)
	{
		std::cout << str[j];
		j++;
	}
	if (j > 8)
	{
		std::cout << ".";
		j++;
		std::cout << "|";
		return ;
	}
	while (j <= 10)
	{
		std::cout << " ";
		j++;
	}
	std::cout << "|";
	return ;
}

void	ft_show_contact(contacts contact[8], int count)
{
	int	i;
	int	index;

	std::string buffer;
	i = 0;
	if (count == 0)
	{
		std::cout << "No contacts, type \"ADD\" to add some" << std::endl;
		return ;
	}
	std::cout << "index     |first nam.|last name |nickname  |" << std::endl;
	while (i < count)
	{
		std::cout << i + 1 << "         |";
		print_info_right(contact[i].get_firstName());
		print_info_right(contact[i].get_lastName());
		print_info_right(contact[i].get_nickName());
		std::cout << std::endl;
		i++;
	}
	std::cout << "Index to show ? [1-8]" << std::endl;
	while (1)
	{
		std::getline(std::cin, buffer);
		if (buffer == "")
		{
			std::cout << "Can not be empty" << std::endl;
			continue ;
		}
		if (buffer[0] >= '1' && buffer[0] <= '8' && buffer[1] == '\0')
			break ;
		std::cout << "Wrong index" << std::endl;
	}
	index = buffer[0] - '0' - 1;
	std::cout << "Contact number [" << index
		+ 1 << "]" << std::endl << std::endl;
	std::cout << "First name : " << contact[index].get_firstName() << std::endl;
	std::cout << "Last name : " << contact[index].get_lastName() << std::endl;
	std::cout << "Nickname : " << contact[index].get_nickName() << std::endl;
	std::cout << "Phone Number : " << contact[index].get_phone() << std::endl;
	std::cout << "Deep secret : " << contact[index].get_secret() << std::endl << std::endl;
}
