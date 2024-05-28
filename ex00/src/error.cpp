/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:45:21 by svolodin          #+#    #+#             */
/*   Updated: 2024/05/28 08:46:39 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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
