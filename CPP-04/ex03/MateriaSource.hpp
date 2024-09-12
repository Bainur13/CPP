/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:57:10 by udumas            #+#    #+#             */
/*   Updated: 2024/09/11 21:48:26 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
  private:
	AMateria *_stock[4];

  public:
	MateriaSource();
	MateriaSource(MateriaSource const &to_cpy);
	~MateriaSource();

	MateriaSource &operator=(MateriaSource const &);

	void learnMateria(AMateria *);
	virtual AMateria *createMateria(std::string const &type);
};

#endif