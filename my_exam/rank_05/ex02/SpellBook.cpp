#include "SpellBook.hpp"
#include "ASpell.hpp"
#include "Fireball.hpp"
#include "Fwoosh.hpp"
#include "Polymorph.hpp"

SpellBook::SpellBook()
{

}

SpellBook::~SpellBook()
{

}
const std::map<std::string, ASpell*>& SpellBook::getSpell() const
{
  return spell_map_;
}

//that COPIES a spell in the book
void SpellBook::learnSpell(ASpell* spell)
{
  spell_map_.insert(std::pair<std::string, ASpell*>(spell->getName(), spell));
}

// that deletes a spell from the book, except  if it isn't there
void SpellBook::forgetSpell(std::string const & spell_name)
{
  std::map<std::string, ASpell*>::iterator it = spell_map_.find(spell_name);

  if (it == spell_map_.end())
    return;

  spell_map_.erase(spell_name);
}

// that receives a string corresponding to the name of a spell, creates it, and returns it.
ASpell* SpellBook::createSpell(std::string const & spell_name)
{
  if (spell_name == "Fireball")
    return new Fireball();
  else if (spell_name == "Fwoosh")
    return new Fwoosh();
  else if (spell_name == "Polymorph")
    return new Polymorph();
  return NULL;
}