#include "Fwoosh.hpp"

// test
#include <iostream>

Fwoosh::Fwoosh()
  // : ASpell("Fwoosh", "shed")
  : ASpell("Fwoosh", "fwooshed")
{

}

ASpell* Fwoosh::clone() const
{
  return new Fwoosh();
}

void Fwoosh::printTest() const
{
  std::cout << "I'm a child class!" << std::endl;
}