#include <string>
#include <map>

class ASpell;

class SpellBook
{
public:
  SpellBook();
  ~SpellBook();

  const std::map<std::string, ASpell*>& getSpell() const;

  //that COPIES a spell in the book
  void learnSpell(ASpell* spell); 

  // that deletes a spell from the book, except  if it isn't there
  void forgetSpell(std::string const & spell_name);

  // that receives a string corresponding to the name of a spell, creates it, and returns it.
  ASpell* createSpell(std::string const & spell_name);

private:
  std::map<std::string, ASpell*> spell_map_;

  SpellBook(const SpellBook& other);
  SpellBook operator=(const SpellBook& rhs);
};