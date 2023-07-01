#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(std::string name, std::string effects)
  : name_(name)
  , effects_(effects)
{

}

ASpell::~ASpell()
{

}

std::string ASpell::getName() const
{
  return name_;
}

std::string ASpell::getEffects() const
{
  return effects_;
}

ASpell* ASpell::clone() const
{
  return  new ASpell(name_, effects_);
}

void ASpell::launch(const ATarget& target) const
{
  target.getHitBySpell(*this);
}