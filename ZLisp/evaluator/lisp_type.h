#ifndef EVALUATOR_LISP_TYPE_H
#define EVALUATOR_LISP_TYPE_H
#include <string>
namespace eval{
 enum LispType{
    NUM,
    STR,
    FUNC,
	PAIR,
    ANY, //This is a generic type for functions such as println
    VARARG//This is for vararg functions
  };
 std::string const lispTypeName(LispType type);
}
#endif