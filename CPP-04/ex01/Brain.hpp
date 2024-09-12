/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:07:20 by udumas            #+#    #+#             */
/*   Updated: 2024/09/12 19:21:45 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class Brain
{
    private:
        std::string *_ideas;

    public:
        Brain();
        Brain(const Brain &to_cpy);
        ~Brain();

        Brain   &operator=(const Brain &to_cpy);

        void set_ideas(std::string ideas, int index);
        std::string get_ideas(int index);
};

#endif
