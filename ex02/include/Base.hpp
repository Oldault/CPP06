/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:24:41 by oldault           #+#    #+#             */
/*   Updated: 2024/05/30 14:51:01 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BASE_HPP__
#define __BASE_HPP__

#include "Colors.hpp"
#include <iostream>
#include <cstdlib>
#include <typeinfo>

class Base
{
  public:
    virtual ~Base() {};

    Base *generate(void);
    void identify(Base *p);
    void identify(Base &p);
};

#endif // __BASE_HPP__
