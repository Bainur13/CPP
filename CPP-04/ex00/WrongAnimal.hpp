/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:27:35 by udumas            #+#    #+#             */
/*   Updated: 2024/09/12 19:08:53 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class  WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &to_cpy);
        WrongAnimal(const std::string &type);

        ~WrongAnimal();
        
        WrongAnimal &operator=(const WrongAnimal &to_cpy);

        std::string getType() const;
        void setType(std::string &);

        void makeSound() const;
};

#endif
