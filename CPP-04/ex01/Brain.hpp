/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:07:20 by udumas            #+#    #+#             */
/*   Updated: 2024/09/02 16:39:15 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class Brain
{
    private:
        std::string *ideas;

    public:
        Brain();
        Brain(const Brain &to_cpy);
        ~Brain();

        Brain   &operator=(const Brain &to_cpy);
};

#endif