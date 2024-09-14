/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bainur <bainur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:43:53 by bainur            #+#    #+#             */
/*   Updated: 2024/09/14 14:50:53 by bainur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>


std::string replace(std::string line, std::string s1, std::string s2)
{
    int i = 0;
    int pos = 0;
    std::string new_line;

    while (line[i])
    {
        pos = line.find(s1, i);
        if (pos == -1)
        {
            new_line += line.substr(i);
            break;
        }
        while (i < pos)
        {
            new_line += line[i];
            i++;
        }
        new_line += s2;
        i += s1.length();
    }
    return (new_line);
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Error: wrong number of arguments" << std::endl;
        return (1);
    }
    std::ifstream file(av[1]);
    if (!file.is_open())
    {
        std::cout << "Error: could not open file" << std::endl;
        return (1);
    }
    std::ofstream outfile(((std::string)av[1] + ".replace").c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Error: Could not create file" << std::endl;
        file.close();
        return (1);
    }
    std::string line;
    while (std::getline(file, line))
    {
        if (file.eof())
            outfile << replace(line, av[2], av[3]);
        else
            outfile << replace(line, av[2], av[3]) << std::endl;
    }
    file.close();
    outfile.close();
    return (0);
}