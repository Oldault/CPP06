/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:15:34 by svolodin          #+#    #+#             */
/*   Updated: 2024/05/28 08:46:08 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
  if (ac != 2)
    return printError(1);

  char *value = av[1];
  ScalarConverter::convert(value);
  
  return 0;
}
