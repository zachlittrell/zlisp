#include "astnode.h"
#include "../evaluator/types.h"
#include "functioncallnode.h"
#include "..//evaluator/symbol_table.h"
#include <vector>
#include <iostream>
#include "symbolnode.h"
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
	  try {
		  auto returnobj = head_.getfunc()->evaluate(arguments);
		  return returnobj;
	  }
	  catch (const char* err) {
		  std::string newerr(err);
		  appendstacktrace(newerr);
		  throw newerr;
	  }
	  catch (std::string err) {
		  appendstacktrace(err);
		  throw err;

	  }
   }
  const std::string anonymous_func_name("anonymous function");
  void FunctionCallNode::appendstacktrace(std::string& err) {
	  const std::string* name;
	  if (auto symnode = dynamic_cast<SymbolNode*>(head.get())) {
		   name = &(symnode->symbol);
	  }
	  else {
		  name = &anonymous_func_name;
	  }
	  err.append("\nIn call to ").append(*name).append(":").append(std::to_string(location));
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