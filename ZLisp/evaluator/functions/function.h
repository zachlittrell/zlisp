#ifndef EVALUATOR_FUNCTIONS_FUNCTION_H
#define EVALUATOR_FUNCTIONS_FUNCTION_H
#include <vector>
#include <string>
#include <functional>
#include "../lisp_type.h"
#include "../types.h"
#include <memory>
#include "..//..//parser/astnode.h"
namespace parse {
	class ASTNode;
};
namespace eval{
	class LispVal;
class Function{
	
  public:
  Function(const std::vector<LispType>& parameters, const std::function<LispVal( std::vector<LispVal>&)> fn);
  Function(const Function& fn)=default;
  const std::function<LispVal(std::vector<LispVal>&)> fn;
  const std::vector<LispType> parameters;
  virtual const LispVal evaluate(const std::vector<std::shared_ptr<parse::ASTNode>>& args) const;
  const std::string show() const;
  private:

	  
};
}
#endif