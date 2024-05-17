/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.Lifecycle.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:25:17 by svolodin          #+#    #+#             */
/*   Updated: 2024/05/17 15:25:25 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
  return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
  (void)src;
  return ;
}

ScalarConverter::~ScalarConverter(void)
{
  return ;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &src)
{
  (void)src;
  return *this;
}
