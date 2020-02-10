#ifndef PARSER_NUMNODE_H
#define PARSER_NUMNODE_H
#include "astnode.h"
#include "../evaluator/types.h"

#include <iostream>
namespace parse{
  class NumNode : public ASTNode{
    public:
     NumNode(const int location, const std::string &num);
	 ~NumNode() = default;
	 virtual  void show(std::ostream& stream) const;
	 virtual eval::LispVal evaluate();
    private:
      const eval::LispVal num;
  };
}
#endif