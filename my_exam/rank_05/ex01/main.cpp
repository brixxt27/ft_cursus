#include "Warlock.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"

int main()
{
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  ASpell* fw = fwoosh->clone();
  ATarget* bb = bob.clone();

  std::cout << "fw's name is " << fw->getName() << std::endl;
  std::cout << "bb's name is " << bb->getType() << std::endl;

  // richard.learnSpell(fwoosh);

  // richard.introduce();
  // richard.launchSpell("Fwoosh", bob);
  // richard.launchSpell("aa", bob);

  // richard.forgetSpell("Fwoosh");
  // richard.launchSpell("Fwoosh", bob);

  delete fwoosh;
  delete fw;
}