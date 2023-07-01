#include "ASpell.hpp"

class Fwoosh : public ASpell
{
public:
  Fwoosh();

  virtual ASpell* clone() const;

  // test function
  void printTest() const;
};