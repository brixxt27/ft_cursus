#include "ATarget.hpp"

class Dummy : public ATarget
{
public:
  Dummy();

  virtual ATarget* clone() const;
};