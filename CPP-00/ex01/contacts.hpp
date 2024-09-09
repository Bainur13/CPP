/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:15:08 by bainur            #+#    #+#             */
/*   Updated: 2024/09/05 13:56:51 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include "conciliator.h"
# include <string>

class contacts
{
  public:
	contacts(void);
	~contacts(void);

	std::string get_firstName();
	std::string get_lastName();
	std::string get_nickName();
	std::string get_phone();
	std::string get_secret();
	int			get_exit();

	void set_firstName(std::string first_name);
	void set_lastName(std::string last_name);
	void set_nickName(std::string nickname);
	void set_phone(std::string phone);
	void set_secret(std::string secret);
	void set_exit(int exit);

  private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone;
	std::string secret;
	int _exit;
};

#endif
