/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:16:27 by svolodin          #+#    #+#             */
/*   Updated: 2024/05/30 14:28:23 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include "Colors.hpp"

#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <limits.h>
#include <iomanip>

class ScalarConverter
{
  private:

    /* Life Cycle */
    explicit ScalarConverter(void);
    ScalarConverter(const ScalarConverter &src);
    ~ScalarConverter(void);
    ScalarConverter &operator=(const ScalarConverter &src);

    /* Core functionality */
    static bool isChar(const std::string &s);
    static bool isNumber(const std::string &s);
    static bool isException(const std::string &s);
  
    static void printChar(const std::string &literal);
    static void printNumber(const std::string &literal);
    static void printException(const std::string &literal);
    
  public:

    static void convert(const std::string &literal);
};


#endif // __SCALARCONVERTER_HPP__