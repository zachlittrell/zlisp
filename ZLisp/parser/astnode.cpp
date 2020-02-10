
#include "../evaluator/types.h"
#include "astnode.h"
#include <iostream>

namespace parse{
  ASTNode::ASTNode(int location):location(location){
  }
  eval::LispVal ASTNode::evaluate(){
     return eval::LispVal::NIL;
  }
  std::ostream& operator<<(std::ostream& stream, const ASTNode& node) {
	  node.show(stream);
	  return stream;

  }
   void ASTNode::show (std::ostream& stream) const{
	  stream << "ASTNode(" << location << ")";
  }
}
