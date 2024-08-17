/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bainur <bainur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:15:35 by bainur            #+#    #+#             */
/*   Updated: 2024/08/02 14:21:36 by bainur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conciliator.h"

contacts::contacts(void)
{
    return;
}

contacts::~contacts(void)
{
    return;
}

contacts ft_put_contact_info(void)
{
    contacts contact;

    std::cout << "New Contact" << std::endl;
    while (1)
    {
        std::cout << "First name = ";
        std::getline(std::cin, contact.first_name);
        if (contact.first_name == "")
        {
            std::cout << "Can not be empty" << std::endl;
            continue;
        }
        if (ft_stringalpha(contact.first_name) == 0)
        {
            std::cout << "Only alphabet characters" << std::endl;
            continue;
        }
        break;
    }
    while (1)
    {
        std::cout << "Last name = ";
        std::getline(std::cin, contact.last_name);
        if (contact.last_name == "")
        {
            std::cout << "Can not be empty" << std::endl;
            continue;
        }
        if (ft_stringalpha(contact.last_name) == 0)
        {
            std::cout << "Only alphabet characters" << std::endl;
            continue;
        }
        break;
    }
    while (1)
    {
        std::cout << "Nickname = ";
        std::getline(std::cin, contact.nickname);
        if (contact.nickname == "")
        {
            std::cout << "Can not be empty" << std::endl;
            continue;
        }
        if (ft_stringalpha(contact.nickname) == 0)
        {
            std::cout << "Only alphabet characters" << std::endl;
            continue;
        }
        break;
    }
    while (1)
    {
        std::cout << "Phone Number = ";
        std::getline(std::cin, contact.phone);
        if (contact.nickname == "")
        {
            std::cout << "Can not be empty" << std::endl;
            continue;
        }
        if (ft_digit(contact.phone) == 0)
        {
            std::cout << "Only digit characters" << std::endl;
            continue;
        }
        break;
    }
    while (1)
    {
        std::cout << "Deepest secret = ";
        std::getline(std::cin, contact.secret);
        if (contact.secret == "")
        {
            std::cout << "Can not be empty" << std::endl;
            continue;
        }
        break;
    }
    return contact;
}

void print_info_right(std::string str)
{
    int i;
    int j;

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
        return;
    }
    while (j <= 10)
    {
        std::cout << " ";
        j++;
    }
    std::cout << "|";
    return;
}

void ft_show_contact(contacts contact[8], int count)
{
    int i;
    int index;
    std::string buffer;

    i = 0;
    if (count == 0)
    {
        std::cout << "No contacts, type \"ADD\" to add some" << std::endl;
        return;
    }
    std::cout << "index     |first nam.|last name |nickname  |" << std::endl;
    while (i < count)
    {
        std::cout << i + 1 << "         |";
        print_info_right(contact[i].first_name);
        print_info_right(contact[i].last_name);
        print_info_right(contact[i].nickname);
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
            continue;
        }
        if (buffer[0] >= '1' && buffer[0] <= '8' && buffer[1] == '\0')
            break;
        std::cout << "Wrong index" << std::endl;
    }
    index = buffer[0] - '0' - 1;
    std::cout << "Contact number [" << index + 1 << "]" << std::endl
              << std::endl;
    std::cout << "First name : " << contact[index].first_name << std::endl;
    std::cout << "Last name : " << contact[index].last_name << std::endl;
    std::cout << "Nickname : " << contact[index].nickname << std::endl;
    std::cout << "Phone Number : " << contact[index].phone << std::endl;
    std::cout << "Deep secret : " << contact[index].secret << std::endl << std::endl;
}
