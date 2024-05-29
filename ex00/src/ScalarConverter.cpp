/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:40:07 by oldault           #+#    #+#             */
/*   Updated: 2024/05/29 16:22:26 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

size_t get_precision(const std::string &s);

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
  double valueDouble = atof(literal.c_str());
  int valueInt = static_cast<int>(valueDouble);

  /* Char printing */
  std::cout << FYEL("Char:\t");
  if (valueInt >= 32 && valueInt <= 126)
    std::cout << FYEL("\'") << BOLD(FYEL(static_cast<char>(valueInt))) << FYEL("\'");
  else
    std::cout << BOLD(FRED("Non displayable"));
  std::cout << std::endl;

  /* Int printing */
  std::cout << FMAG("Int:\t");
  if (valueDouble >= INT_MAX) std::cout << BOLD(FMAG(INT_MAX));
  else if (valueDouble <= INT_MIN) std::cout << BOLD(FMAG(INT_MIN));
  else std::cout << BOLD(FMAG(valueInt));
  std::cout << std::endl;

  /* Float and Double printing */
  std::ostringstream floatStream;
  std::ostringstream doubleStream;
  size_t precision = get_precision(literal);
  floatStream << std::fixed << std::setprecision(precision) << static_cast<float>(valueDouble);
  doubleStream << std::fixed << std::setprecision(precision) << static_cast<double>(valueDouble);

  std::cout << FCYN("Float:\t") <<  BOLD(FCYN(floatStream.str())) << FCYN("f") << std::endl;
  std::cout << FGRN("Double:\t") <<  BOLD(FGRN(doubleStream.str())) << std::endl;
}

void ScalarConverter::printException(const std::string &literal)
{
  if (literal == "nan") {
    std::cout << FYEL("Char:\t\'") << BOLD(FYEL("Impossible")) << FYEL("\'") << std::endl;
    std::cout << FMAG("Int:\t") << BOLD(FMAG("Impossible")) << std::endl;
    std::cout << FCYN("Float:\t") <<  BOLD(FCYN("nan")) << FCYN("f") << std::endl;
    std::cout << FGRN("Double:\t") <<  BOLD(FGRN("nan")) << std::endl;
  } else if (literal == "+inf" || literal == "+inff") {
    std::cout << FYEL("Char:\t") << BOLD(FYEL("∞")) << std::endl;
    std::cout << FMAG("Int:\t") << BOLD(FMAG(INT_MAX)) << std::endl;
    std::cout << FCYN("Float:\t") <<  BOLD(FCYN(__FLT_MAX__)) << FCYN("f") << std::endl;
    std::cout << FGRN("Double:\t") <<  BOLD(FGRN(__DBL_MAX__)) << std::endl;
  } else if (literal == "-inf" || literal == "-inff") {
    std::cout << FYEL("Char:\t") << BOLD(FYEL("-∞")) << std::endl;
    std::cout << FMAG("Int:\t") << BOLD(FMAG(INT_MIN)) << std::endl;
    std::cout << FCYN("Float:\t") <<  BOLD(FCYN(__FLT_MIN__)) << FCYN("f") << std::endl;
    std::cout << FGRN("Double:\t") <<  BOLD(FGRN(__DBL_MIN__)) << std::endl;
  }
}

size_t get_precision(const std::string &s)
{
  size_t dotPos = s.find('.');
  if (dotPos == std::string::npos) {
    return 1;
  }
  return s.size() - dotPos - 1;
}
