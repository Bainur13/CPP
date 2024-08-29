/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 23:00:01 by bainur            #+#    #+#             */
/*   Updated: 2024/08/29 16:35:00 by udumas           ###   ########.fr       */
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