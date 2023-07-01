#include "ASpell.hpp"

class Fwoosh : public ASpell
{
public:
  Fwoosh();

  ASpell* clone() const;
  // virtual ASpell* clone() const;
};