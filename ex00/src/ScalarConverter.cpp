/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:19:20 by svolodin          #+#    #+#             */
/*   Updated: 2024/05/17 17:25:39 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void handleInt(const char *value);

void handleChar(const char *value);
void printChar(const char *value);
void printCharFromInt(int value);

void ScalarConverter::convert(const char *value)
{
  int valueInt = atoi(value);

  (void)valueInt;
  handleInt(value);
  handleChar(value);
}

void handleInt(const char *value)
{
  int valueInt = atoi(value);
  char c;
  
  if (strlen(value) == 1)
    c = value[0];

  std::cout << FMAG("Int value is: ");
  if (valueInt == 0 && c) {
    std::cout << BOLD(FMAG(int(c))) << std::endl;
  } else {
    std::cout << BOLD(FMAG(valueInt)) << std::endl;
  }
}

void handleChar(const char *value)
{
  int valueInt = atoi(value);

  std::cout << FYEL("Char value is: ");
  if ((valueInt > 9 && strlen(value) == 1)) {
    printChar(value);
  } else {
    printCharFromInt(valueInt);
  }
}

void printCharFromInt(int value)
{
  char c = static_cast<char>(value);

  if (std::isprint(c) && (value >= 32 && value <= 126)) {
    std::cout << BOLD(FYEL('\'')) << BOLD(FYEL(c)) << BOLD(FYEL('\'')) << std::endl;
  } else {
    std::cout << ITAL(FYEL("Non displayable")) << std::endl;
  }
 
}

void printChar(const char *value)
{
  std::cout << BOLD(FYEL('\'')) << BOLD(FYEL(value)) << BOLD(FYEL('\'')) << std::endl;
}
