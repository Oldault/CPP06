/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:15:34 by svolodin          #+#    #+#             */
/*   Updated: 2024/05/17 15:16:18 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int  printError(int i);

int main(int ac, char **av)
{
  if (ac != 2)
    return printError(1);

  char *value = av[1];
  ScalarConverter::convert(value);
  
  return 0;
}

int  printError(int i)
{
  switch(i) {
    case 1:
      std::cerr << "\n\t" << BRED(" Please give one argument to the converter ") << "\n\n"
      << "\t" << UNDL(FGRN(BOLD("Examples :"))) << "\n"
      << "\t\t" << ITAL("./convert 0") << "\n"
      << "\t\t" << ITAL("./convert nan") << "\n"
      << "\t\t" << ITAL("./convert 42.0f") << "\n\n";
  }
  return 42;
}