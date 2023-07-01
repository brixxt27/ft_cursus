#include "Warlock.hpp"
#include "ASpell.hpp"

Warlock::Warlock(std::string name, std::string title)
  : name_(name)
  , title_(title)
{
  std::cout << name_ << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
  std::cout << name_ << ": My job here is done!" << std::endl;
}

const std::string& Warlock::getName() const
{
  return name_;
}

const std::string& Warlock::getTitle() const
{
  return title_;
}

void Warlock::setTitle(const std::string& title)
{
  title_ = title;
}

void Warlock::introduce() const
{
  std::cout << name_ << ": I am " << name_ << ", " << title_ << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell)
{
  spell_map.insert(std::pair<std::string, ASpell*>(spell->getName(), spell));
}

// If it's not a known spell, does nothing.
void Warlock::forgetSpell(std::string spell_name)
{
  std::map<std::string, ASpell*>::iterator it = spell_map.find(spell_name);

  if (it == spell_map.end())
    return;

  spell_map.erase(spell_name);
}

// If it's not a known spell, does nothing.
void Warlock::launchSpell(std::string spell_name, ATarget& target)
{
  std::map<std::string, ASpell*>::iterator it = spell_map.find(spell_name);

  if (it == spell_map.end())
    return;

  it->second->launch(target);
}
