#include "Warlock.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"

int main()
{
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  ASpell* fw = fwoosh->clone();
  // ATarget* bb = bob.clone();

  fw->printTest();

  ASpell* nfw = fw->clone();
  nfw->printTest();

  // richard.learnSpell(fwoosh);

  // richard.introduce();
  // richard.launchSpell("Fwoosh", bob);
  // richard.launchSpell("aa", bob);

  // richard.forgetSpell("Fwoosh");
  // richard.launchSpell("Fwoosh", bob);

  delete fwoosh;
  delete fw;
}