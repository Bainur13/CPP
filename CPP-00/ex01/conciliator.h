/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conciliator.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bainur <bainur@student.42.fr>              +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:03:13 by bainur            #+#    #+#             */
/*   Updated: 2024/07/29 17:03:14 by bainur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONCILIATOR_H
#define CONCILIATOR_H

#include "Phonebook.hpp"
#include "contacts.hpp"
#include <iostream>
#include <cstring>

int ft_stringalpha(std::string buffer);
int ft_digit(std::string buffer);
contacts ft_put_contact_info(void);
void ft_show_contact(contacts contact[8], int count);
int	check_eof(void);

#endif