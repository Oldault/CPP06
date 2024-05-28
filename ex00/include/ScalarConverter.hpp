/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:16:27 by svolodin          #+#    #+#             */
/*   Updated: 2024/05/28 14:01:29 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER_H__
#define __SCALARCONVERTER_H__

#include "Colors.hpp"

#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <limits.h>
#include <iomanip>

int  printError(int i);
int  extremeCasesChar(const char *value);
int  extremeCasesInt(const char *value);

class ScalarConverter
{
  private:
    ScalarConverter(void);
  
  public:
    ScalarConverter(const ScalarConverter &src);
    ~ScalarConverter(void);

    ScalarConverter &operator=(const ScalarConverter &src);

    static void convert(const char *value);
};


#endif // __SCALARCONVERTER_H__