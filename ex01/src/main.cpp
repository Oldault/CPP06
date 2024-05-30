/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:43:27 by oldault           #+#    #+#             */
/*   Updated: 2024/05/30 11:04:20 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <cassert>

int main()
{
  std::cout << std::endl;

  Data data = {420024, "Com Cider", 1337.2, "sweep"};
  Data* originalPtr = &data;
  
  uintptr_t serialized = Serializer::serialize(originalPtr);
  std::cout << BGRN(" Serialized Value: ") << "\t" << BOLD(FGRN(serialized)) << std::endl;
  
  Data* deserializedPtr = Serializer::deserialize(serialized);

  assert(deserializedPtr == originalPtr);
  std::cout << "\n\t" << BOLD(BMAG(" ⭐ assert() test passed! ⭐ ")) << "\n\n";
  
  std::cout << BGRN(" Deserialized Values:")
    << "\n\t" << FGRN(UNDL("Account Number")) << "\t\t" << BOLD(FGRN(deserializedPtr->accountNumber)) << std::endl
    << "\t" << FGRN(UNDL("Full Name:")) << "\t\t" << BOLD(FGRN(deserializedPtr->fullName)) << std::endl
    << "\t" << FGRN(UNDL("Account Balance:")) << "\t" << BOLD(FGRN(deserializedPtr->accountBalance)) << std::endl
    << "\t" << FGRN(UNDL("Account Type:")) << "\t\t" << BOLD(FGRN(deserializedPtr->type)) << std::endl
  << std::endl;

  return 0;
}
