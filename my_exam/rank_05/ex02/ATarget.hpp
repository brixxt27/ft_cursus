#include <string>

class ASpell;

class ATarget
{
public:
  ATarget(std::string type);
  virtual ~ATarget();

  const std::string getType() const;

  void getHitBySpell(const ASpell& spell) const;

  virtual ATarget* clone() const;

private:
  std::string type_;

  ATarget();
  ATarget(const ATarget& other);
  ATarget operator=(const ATarget& rhs);
};