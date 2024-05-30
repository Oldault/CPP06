/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 08:50:26 by oldault           #+#    #+#             */
/*   Updated: 2024/05/30 10:57:51 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include "Colors.hpp"

#include <iostream>
#include <stdint.h>

/* Data storing Banking Credentials */
typedef struct
{
  unsigned int accountNumber;
  std::string fullName;
  double accountBalance;
  const char *type;
} Data;

/* The serializer */
class Serializer
{
  private:

    /* Life Cycle */
    explicit Serializer(void);
    Serializer(const Serializer &src);
    ~Serializer(void);
    Serializer &operator=(const Serializer &src);

  public:

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif // __SERILIZER_H__