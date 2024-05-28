/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:19:20 by svolodin          #+#    #+#             */
/*   Updated: 2024/05/28 14:01:49 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void handleChar(const char *value);
void handleInt(const char *value);
void handleFloat(const char *value);

void ScalarConverter::convert(const char *value)
{
  // int valueInt = atoi(value);

  handleChar(value);
  handleInt(value);
  // handleFloat(value);
}

void handleChar(const char *value)
{
  int  valueInt = atoi(value);
  bool isDisplayable = true;
  char output = '\0';

  std::cout << FYEL("Char value is: ");
  if (extremeCasesChar(value)) return ;

  if (valueInt == 0 && strlen(value) == 1 && std::isprint(value[0])) {
    if (static_cast<int>(value[0]) == 48) {isDisplayable = false; }
    output = value[0];
  }
  else if (valueInt >= 32 && valueInt <= 126) {
    output = static_cast<char>(valueInt);
  }
  else { isDisplayable = false; }

  if (isDisplayable) {
      std::cout << FYEL("\'") << BOLD(FYEL(output)) << FYEL("\'");
  } else {
      std::cout << BOLD(FYEL("Non displayable"));
  }
  std::cout << std::endl;
}

void handleInt(const char *value)
{
  int valueInt = atoi(value);
  int output = 0;

  std::cout << FMAG("Int value is: ");
  if (extremeCasesInt(value)) { return ; }

  if (valueInt == 0)
  {
    for (size_t i = 0; i < strlen(value); i++) {
      output += (static_cast<int>(value[i]) == 48 ? 0 : value[i]);
    }
  } else {
    output = valueInt;
  }
  std::cout << BOLD(FMAG(output)) << std::endl;
}

// void handleFloat(const char *value)
// {
//   float valueFloat = atof(value);
//   float output = 0;

//   std::cout << FCYN("Float value is: ");
//   if (extremeCasesInt(value)) { return ; }

//   if (valueFloat == 0)
//   {
//     for (size_t i = 0; i < strlen(value); i++) {
//       output += (static_cast<float>(value[i]) == 48 ? 0 : value[i]);
//     }
//   } else {
//     output = valueFloat;
//   }
//   std::cout << std::fixed << std::setprecision(1) << BOLD(FCYN(output)) << std::endl;
// }
