#ifndef PARSER_STRNODE_H
#define PARSER_STRNODE_H
#include "astnode.h"
#include "../evaluator/types.h"
#include <iostream>
namespace parse{
  class StrNode : public ASTNode{
    public:
     StrNode(const int location, const std::string &str);
	 ~StrNode() = default;
	 virtual eval::LispVal evaluate();
	 virtual  void show(std::ostream& stream) const;
    private:
      const eval::LispVal str;
  };
}
#endif