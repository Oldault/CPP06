/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:40:07 by oldault           #+#    #+#             */
/*   Updated: 2024/05/29 14:36:34 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal)
{
  if (isChar(literal)) {
    printChar(literal);
  } else if (isNumber(literal)) {
    printNumber(literal);
  } else if (isException(literal)) {
    printException(literal);
  } else {
    std::cout <<
      "\n" << BRED(" Invalid Type: ") << "\n\t" <<
      FRED(ITAL(" The parameter is neither a decimal notation, nor a char literal.\n"))
      << std::endl;
  }
  return ;
}

bool ScalarConverter::isChar(const std::string &s)
{
  return s.length() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]);
}

bool ScalarConverter::isNumber(const std::string &s)
{
  std::string::const_iterator it = s.begin();
  size_t dot = 0;

  if (*it == '-' || *it == '+') ++it;
  while (it != s.end() && (std::isdigit(*it) || *it == '.')) {
    if (*it == '.') dot++;
    ++it;
  }
  if (*it == 'f') ++it;
  return !s.empty() && it == s.end() && dot <= 1;
}

bool ScalarConverter::isException(const std::string &s)
{
  return (s == "nan" || s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff");
}

void ScalarConverter::printChar(const std::string &literal)
{
  char c = literal[0];

  std::ostringstream floatStream;
  std::ostringstream doubleStream;
  floatStream << std::fixed << std::setprecision(1) << static_cast<float>(c);
  doubleStream << std::fixed << std::setprecision(1) << static_cast<double>(c);
  
  std::cout << FYEL("Char:\t\'") << BOLD(FYEL(c)) << FYEL("\'") << std::endl;
  std::cout << FMAG("Int:\t") << BOLD(FMAG(static_cast<int>(c))) << std::endl;
  std::cout << FCYN("Float:\t") <<  BOLD(FCYN(floatStream.str())) << FCYN("f") << std::endl;
  std::cout << FGRN("Double:\t") <<  BOLD(FGRN(doubleStream.str())) << std::endl;
}

void ScalarConverter::printNumber(const std::string &literal)
{
  std::cout << "Number Detected: " << literal << std::endl;
}

void ScalarConverter::printException(const std::string &literal)
{
  std::cout << "Exception Detected: " << literal << std::endl;
}