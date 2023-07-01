#include "ATarget.hpp"
#include "ASpell.hpp"
#include <iostream>

ATarget::ATarget(std::string type)
  : type_(type)
{

}

ATarget::~ATarget()
{

}

const std::string ATarget::getType() const
{
  return type_;
}

void ATarget::getHitBySpell(const ASpell& spell) const
{
  std::cout << type_ << " has been " << spell.getEffects() << "!" << std::endl;
}

ATarget* ATarget::clone() const
{
  return new ATarget(type_);
}
