/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bainur <bainur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:01:53 by bainur            #+#    #+#             */
/*   Updated: 2024/07/29 21:13:54 by bainur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conciliator.h"

Phonebook::Phonebook(void)
{
    std::cout << "------------ PhoneBook ------------" << std::endl;
    std::cout << " Enregistrez vos contacts à l'aide " << std::endl;
    std::cout << "       de la commande \"ADD\".     " << std::endl;
    std::cout << " Cherchez ceux que vous avez déjà  " << std::endl;
    std::cout << "      ajouté avec \"SEARCH\".      " << std::endl;
    std::cout << " Pour terminer le programme tapez  " << std::endl;
    std::cout << "             \"EXIT\".             " << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    return ;
}

Phonebook::~Phonebook(void)
{
    std::cout << "-------- Fin de Phonebook --------" << std::endl;
    return ;
}