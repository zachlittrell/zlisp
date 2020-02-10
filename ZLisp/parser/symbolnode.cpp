#include "astnode.h"
#include "../evaluator/types.h"
#include "symbolnode.h"
#include "..//evaluator/symbol_table.h"
#include <iostream>
namespace parse{
  SymbolNode::SymbolNode(const int location,const std::string &sym): ASTNode(location), symbol(sym){

  }
  eval::LispVal SymbolNode::evaluate() {
	  return eval::lookup(symbol);
  }
  void SymbolNode::show(std::ostream& stream) const {
	  stream << "SymbolNode(" << location << ")";
  }
}