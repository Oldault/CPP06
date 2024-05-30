/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.LifeCycle.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 08:53:28 by oldault           #+#    #+#             */
/*   Updated: 2024/05/30 08:57:49 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


Serializer::Serializer(void)
{
  return ;
}

Serializer::Serializer(const Serializer &src)
{
  (void)src;
  return ;
}

Serializer::~Serializer(void)
{
  return ;
}

Serializer& Serializer::operator=(const Serializer &src)
{
  (void)src;
  return *this;
}
