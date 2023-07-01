#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>

class Warlock
{
public:
  Warlock(std::string name, std::string title);
  ~Warlock();

  const std::string& getName() const;
  const std::string& getTitle() const;
  void setTitle(const std::string& title);

  void introduce() const;

private:
  Warlock();
  Warlock operator=(const Warlock& rhs);
  Warlock(const Warlock& other);

  std::string name_;
  std::string title_;
};

#endif