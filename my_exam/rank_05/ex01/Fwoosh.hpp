#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
public:
  Fwoosh();

  virtual ASpell* clone() const;

  // test function
  void printTest() const;
};

#endif