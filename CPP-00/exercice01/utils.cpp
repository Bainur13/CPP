/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bainur <bainur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:38:22 by bainur            #+#    #+#             */
/*   Updated: 2024/07/30 14:23:55 by bainur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conciliator.h"


int ft_stringalpha(std::string buffer)
{
    int i;
    char c;

    i = 0;
    if (buffer == "")
        return (0);
    while (buffer[i])
    {
        c = buffer[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            i++;
        else 
            return (0);
    }   
    return (1);
}

int ft_digit(std::string buffer)
{
    int i;
    char c;

    i = 0;
    if (buffer == "")
        return (0);
    while (buffer[i])
    {
        c = buffer[i];
        if (c >= '0' && c <= '9')
            i++;
        else
            return (0);
    }
    return (1);
}