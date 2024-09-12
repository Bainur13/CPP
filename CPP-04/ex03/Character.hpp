/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:17:17 by udumas            #+#    #+#             */
/*   Updated: 2024/09/12 18:27:54 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

void				ft_lstAddback(AMateria *new_AMateria);
void				ft_lstDestroy();

typedef struct s_floor
{
	AMateria		*object;
	s_floor			*next;
}					t_floor;

extern t_floor	*globalFloor;

class Character : public ICharacter
{
  private:
	std::string _name;
	AMateria *_inv[4];

  public:
	Character();
	Character(std::string const &name);
	Character(Character const &to_cpy);
	~Character();
	Character &operator=(Character const &to_cpy);
	std::string const &getName() const;

	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif