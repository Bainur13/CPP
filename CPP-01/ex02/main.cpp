/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:37:13 by bainur            #+#    #+#             */
/*   Updated: 2024/09/15 15:29:56 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string &stringREF = brain;

    std::cout << "Address of the string: " << &brain << std::endl;
    std::cout << "Address of the string using stringPTR: " << stringPTR << std::endl;
    std::cout << "Address of the string using stringREF: " << &stringREF << std::endl;

    std::cout << "Value of the string : " << brain << std::endl;
    std::cout << "Value of the string using stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value of the string using stringREF: " << stringREF << std::endl;
}
