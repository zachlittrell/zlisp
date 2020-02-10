#include "astnode.h"
#include "../evaluator/types.h"
#include "numnode.h"
#include <string>
#include <iostream>
namespace parse{
  NumNode::NumNode(int location, const std::string &num): ASTNode(location), num(eval::LispVal( std::stod(num)))
  {

  }

  eval::LispVal NumNode::evaluate() {
	  return num;
  }
   void  NumNode::show(std::ostream& stream) const {
	  stream << "NumNode(";
	  stream << location;
	  stream << " ";
	//  stream << node.evaluate();
	  stream << ")";


  }
}