/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:51:10 by udumas            #+#    #+#             */
/*   Updated: 2024/08/29 17:30:25 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;
        
    public:
        Point();
        Point(float const x, float const y);
        Point(Point const &);
        ~Point();
        
        float getX() const;
        float getY() const;
        Point &operator=(const Point &);
        
        static bool	bsp(Point const a, Point const b, Point const c, Point const p);
};