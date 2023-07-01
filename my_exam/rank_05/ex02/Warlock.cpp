#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

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
  book_.learnSpell(spell);
}

// If it's not a known spell, does nothing.
void Warlock::forgetSpell(std::string spell_name)
{
  book_.forgetSpell(spell_name);
}

// If it's not a known spell, does nothing.
void Warlock::launchSpell(std::string spell_name, ATarget& target)
{
  const std::map<std::string, ASpell*> spells = book_.getSpell();

  std::map<std::string, ASpell*>::const_iterator cit = spells.find(spell_name);
  
  if (cit == spells.end())
    return ;
  
  cit->second->launch(target);
}

/**
  std::map<std::string, ASpell*>::iterator it = spell_map_.find(spell_name);

  if (it == spell_map_.end())
    return;

  it->second->launch(target);
 */