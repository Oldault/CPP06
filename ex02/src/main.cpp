/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:23:59 by oldault           #+#    #+#             */
/*   Updated: 2024/05/30 15:39:18 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main( void )
{
  std::cout << std::endl;

  Base util;

  Base *ptr = util.generate();
  Base &ref = *ptr;

  util.identify(ptr);
  util.identify(ref);

  std::cout << std::endl;
  
}
