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