#include <string>
#include <iostream>

class Warlock
{
public:
  Warlock(std::string name, std::string title);
  ~Warlock();

  std::string getName() const;
  std::string getTitle() const;
  void setTitle(const std::string& title);

  void introduce() const;

private:
  Warlock();
  Warlock operator=(const Warlock& rhs);
  Warlock(const Warlock& other);

  std::string name_;
  std::string title_;
};