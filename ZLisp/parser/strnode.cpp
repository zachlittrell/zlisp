#include "astnode.h"
#include "../evaluator/types.h"
#include "strnode.h"
#include <iostream>
namespace parse{
  StrNode::StrNode(const int location,const std::string& str)
  :ASTNode(location), str(eval::LispVal(str.substr(1, str.length()-2))){

  }
  eval::LispVal StrNode::evaluate() {
	  return str;
  }
   void StrNode::show(std::ostream& stream) const {
	  stream << "StrNode(";
	  stream << location;
	  stream << ")";

  }
}