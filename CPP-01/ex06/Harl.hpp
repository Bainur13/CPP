/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:28:35 by udumas            #+#    #+#             */
/*   Updated: 2024/09/12 19:28:03 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
  public:
	Harl();
	~Harl();
	void complain(std::string level);
	void complain_filter(std::string level);

  private:
	void debug();
	void info();
	void warning();
	void error();
};

#endif
