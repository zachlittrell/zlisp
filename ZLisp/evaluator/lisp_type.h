#ifndef EVALUATOR_LISP_TYPE_H
#define EVALUATOR_LISP_TYPE_H
#include <string>
/**
* Enum for possible types of LispVals.
* This should likely be moved into types.h
*/
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