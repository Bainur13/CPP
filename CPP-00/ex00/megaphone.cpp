/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:41:54 by bainur            #+#    #+#             */
/*   Updated: 2024/08/29 15:19:33 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>

void    ft_strcaps(std::string str)
{
    int i;
    
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = toupper(str[i]);
        i++;
    }
    std::cout << str;
}

int main(int ac, char **av)
{
    int i;
    
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    i = 1;
    while(i < ac)
    {
        ft_strcaps(av[i]);
        i++;
    }
    std::cout << std::endl;
    return (0);
}