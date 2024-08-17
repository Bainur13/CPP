/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bainur <bainur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 23:00:01 by bainur            #+#    #+#             */
/*   Updated: 2024/07/30 14:35:24 by bainur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conciliator.h"
#include "contacts.hpp"

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

class   Phonebook
{   
    public:
        Phonebook(void);
        ~Phonebook(void);
        contacts list_contacts[8];
    
};

#endif