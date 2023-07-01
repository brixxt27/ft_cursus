#include <string>
#include <iostream>
#include <map>

class ASpell;
class ATarget;

class Warlock
{
public:
  Warlock(std::string name, std::string title);
  ~Warlock();

  const std::string& getName() const;
  const std::string& getTitle() const;
  void setTitle(const std::string& title);

  void introduce() const;

  void learnSpell(ASpell* spell);
  // If it's not a known spell, does nothing.
  void forgetSpell(std::string spell_name);
  // If it's not a known spell, does nothing.
  void launchSpell(std::string spell_name, ATarget& target);

private:
  std::string name_;
  std::string title_;
  std::map<std::string, ASpell*> spell_map;

  Warlock();
  Warlock operator=(const Warlock& rhs);
  Warlock(const Warlock& other);
};