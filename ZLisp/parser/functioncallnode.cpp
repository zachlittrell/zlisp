#include "astnode.h"
#include "../evaluator/types.h"
#include "functioncallnode.h"
#include "..//evaluator/symbol_table.h"
#include <vector>
#include <iostream>
namespace parse{
  FunctionCallNode::FunctionCallNode(const int location, const std::vector<std::shared_ptr<ASTNode>>& args):
	  ASTNode(location),//,
  head(args[0]),
  arguments(args.begin()+1,args.end())
  {

  }
  FunctionCallNode::~FunctionCallNode() {
	
  }

  eval::LispVal FunctionCallNode::evaluate() {
	  auto head_ = head->evaluate();
	  if (head_.type != eval::LispType::FUNC) {
		  throw "Cannot call as function:" + head_.type;
	  }
	  return head_.getfunc()->evaluate(arguments);
   }

   void  FunctionCallNode::show(std::ostream& stream) const {
	  stream << "FunctionCallNode(";
	  stream << location << " ";
	  stream << *(this->head) << " ";
	  for (auto& arg : arguments)
		  stream << *arg << " ";

	  stream << ")";

  }
}