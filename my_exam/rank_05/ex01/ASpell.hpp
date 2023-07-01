#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <string>

class ATarget;

class ASpell
{
public:
  ASpell(std::string name, std::string effects);
  virtual ~ASpell();

  std::string getName() const;
  std::string getEffects() const;

  ASpell* clone() const;
  // virtual ASpell* clone() const;

  void launch(const ATarget& target) const;

  // example of polymorphism
  virtual void printTest() const;

protected:
  std::string name_;
  std::string effects_;

  ASpell();
  ASpell(const ASpell& other);
  ASpell operator=(const ASpell& rhs);
};

#endif