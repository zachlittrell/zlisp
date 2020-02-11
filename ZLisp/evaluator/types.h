#ifndef EVALUATOR_TYPES_H
#define EVALUATOR_TYPES_H
#include <string>
#include <variant>
#include "functions/function.h"
#include "lisp_type.h"
#include <memory>
/**
* The basic unit of ZLisp. A LispVal represents one of four types: a num, a string, a function, or a pair.
*/
namespace parse {
	class ASTNode;
}
namespace eval{
class Function;
 
class LispVal{
  public:
  const static LispVal NIL ;
  LispType type;
  LispVal();
  ~LispVal();
  LispVal( const double val);
  LispVal(const std::string val);
  LispVal( const Function* fn);
  LispVal(const std::pair<LispVal, LispVal>* pair);
  LispVal(const LispVal &val);
  LispVal(const LispVal&& val);
  double equal(const LispVal& val2);
  std::string show() const;
  double getnum() const;
  std::string getstr() const;
 std::shared_ptr<const std::pair<LispVal, LispVal>> getpair() const;
  std::shared_ptr<const Function> getfunc() const;
  private:
  const std::variant<double, std::string, std::shared_ptr<const std::pair<LispVal,LispVal>>, std::shared_ptr<const Function>> val;
  
};
}
#endif