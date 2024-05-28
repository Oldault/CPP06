/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:16:27 by svolodin          #+#    #+#             */
/*   Updated: 2024/05/28 08:43:17 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER_H__
#define __SCALARCONVERTER_H__

#include "Colors.hpp"

#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>

int  printError(int i);

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