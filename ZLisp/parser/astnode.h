#ifndef PARSER_ASTNODE_H
#define PARSER_ASTNODE_H
#include "../evaluator/types.h"
#include <iostream>
namespace eval {
	class LispVal;
	class Function;
}
namespace parse{
class ASTNode{
  public:
  const int location;
  ASTNode(int location);
  ~ASTNode() = default;
  virtual eval::LispVal evaluate();
  friend std::ostream& operator<<(std::ostream& stream, const ASTNode& node);
  virtual void show  (std::ostream& stream) const;
};
}
#endif