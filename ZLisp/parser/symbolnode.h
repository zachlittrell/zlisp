#ifndef PARSER_SYMBOLNODE_H
#define PARSER_SYMBOLNODE_H
#include "astnode.h"
#include "../evaluator/types.h"
#include "../evaluator/functions/lambda_function.h"
#include "..//evaluator/functions/def_function.h"
#include "functioncallnode.h"
#include <iostream>
/**
* Node for holding Symbols
*/
namespace parse{
  class SymbolNode : public ASTNode{
    public:
     SymbolNode(const int location, const std::string &symbol);
	 ~SymbolNode() = default;
	 virtual  void show(std::ostream& stream) const;
	 virtual eval::LispVal evaluate();
     private:
     const std::string symbol;
	 friend class eval::LambdaFunction;
	 friend class eval::DefFunction;
     friend class FunctionCallNode;
  };
}
#endif