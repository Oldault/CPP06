/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:15:34 by svolodin          #+#    #+#             */
/*   Updated: 2024/05/29 09:00:48 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int  printError(int i);

int main(int ac, char **av)
{
  if (ac != 2)
    return printError(1);

  char *literal = av[1];
  ScalarConverter::convert(literal);
  
  return 0;
}

int  printError(int i)
{
  switch(i) {
    case 1:
      std::cerr << "\n\t" << BRED(" Please give an argument to the converter ") << "\n\n"
      << "\t" << UNDL(FGRN(BOLD("Such as :"))) << "\n"
      << "\t\t" << ITAL("./convert 0") << "\n"
      << "\t\t" << ITAL("./convert nan") << "\n"
      << "\t\t" << ITAL("./convert 42.0f") << "\n\n";
  }
  return 42;
}
