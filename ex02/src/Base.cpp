/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:30:16 by oldault           #+#    #+#             */
/*   Updated: 2024/05/30 15:22:01 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void printAction(const std::string& did, const std::string& thing);

Base* Base::generate(void)
{
  srand(time(NULL));
  int i = (rand() % 3) + 1;

  Base *ptr;
  
  switch (i) {
    case 1: ptr = new A; printAction("Generated", "A"); break;
    case 2: ptr = new B; printAction("Generated", "B"); break;
    case 3: ptr = new C; printAction("Generated", "C"); break;
  }

  return ptr;
}

void Base::identify(Base *p)
{
  A* a = dynamic_cast<A*>(p);
  B* b = dynamic_cast<B*>(p);
  C* c = dynamic_cast<C*>(p);
  
  if (a) { printAction("* Identifier", "A"); }
  else if (b) { printAction("* Identifier", "B"); }
  else if (c) { printAction("* Identifier", "C"); }
  else { std::cout << BRED(" Unknown class ") << std::endl; }
}

void Base::identify(Base &p)
{
  try {
    A& a = dynamic_cast<A&>(p);
    (void)a;
    printAction("& Identifier", "A");
  } catch (const std::bad_cast& e) {}
  try {
    B& b = dynamic_cast<B&>(p);
    (void)b;
    printAction("& Identifier", "B");
  } catch (const std::bad_cast& e) {}
  try {
    C& c = dynamic_cast<C&>(p);
    (void)c;
    printAction("& Identifier", "C");
  } catch (const std::bad_cast& e) {}
}

void printAction(const std::string& did, const std::string& thing)
{
  std::cout << "\t" << UNDL(FBLU(did)) << FBLU(":\t") << BOLD(FMAG(thing)) << std::endl;
}
