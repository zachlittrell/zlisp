#include <string>
#include <variant>
#include <iostream>
#include "types.h"
#include "lisp_type.h"
#include <functional>
#include "functions/function.h"
#include <cstdlib>
namespace eval{
	LispVal::LispVal(): LispVal((std::pair<LispVal,LispVal>*) nullptr){
		
	}
  LispVal const LispVal::NIL;
  LispVal::~LispVal() {

  }
  
  LispVal::LispVal( const double num): type(NUM), val(num){}
  
  LispVal::LispVal(const std::string str): type(STR), val(str){}

  LispVal::LispVal( const Function* fn) : type(FUNC),  val(std::shared_ptr<const Function>(fn)) {}

  LispVal::LispVal(const std::pair<LispVal, LispVal>* pair) : type(PAIR), val(std::shared_ptr<const std::pair<LispVal,LispVal>>(pair)) {}

  LispVal::LispVal(const LispVal& old) : type(old.type), val(old.val) {
  
  }

  LispVal::LispVal(const LispVal&& old) : type(old.type), val(std::move(old.val))  {
      
  }
   
  double LispVal::equal(const LispVal& other) {
	  if (other.type != type) return 0;
	  switch (type) {
	  case LispType::NUM: 
		  return other.getnum() == getnum();
      case LispType::STR:
	      return other.getstr() == getstr();
	  case LispType::FUNC:
		  return other.getfunc() == getfunc();
	  case LispType::PAIR: {
		  auto ptr1 = getpair();
		  auto ptr2 = other.getpair();
          if (!ptr1) {
              if (ptr2)
                  return false;
              return true;
          }
          else if (!ptr2) {
              return false;
          }
          auto p1 = *ptr1;
          auto p2 = *ptr2;
		  return std::get<0>(p1).equal(std::get<0>(p2)) && std::get<1>(p1).equal(std::get<1>(p2));
		 }
	  }
	  return 0;
  }

  double LispVal::getnum() const{
    return std::get<double>(val);
  }

  std::string LispVal::getstr() const{
    return std::get<std::string>(val);
  }

  std::shared_ptr<const std::pair<LispVal, LispVal>> LispVal::getpair() const {
	  return std::get<std::shared_ptr<const std::pair<LispVal, LispVal>>>(val);
  }

  std::shared_ptr<const Function> LispVal::getfunc() const{
    return std::get<std::shared_ptr<const Function>>(val);
  }

  std::string LispVal::show() const {
	  switch (type) {
	  case LispType::FUNC: {
		  auto f = getfunc();

		  return getfunc()->show();
	  }
	  
	  case LispType::NUM: return std::to_string(getnum());
	  case LispType::STR: return getstr();
	  
	  }
	  return "nil";
  }



  std::ostream& operator<<(std::ostream &stream, const LispVal &value) {
    stream << "LispVal(";
    switch(value.type){
      case NUM:
      stream<<value.getnum();
      break;
      case STR:
      stream<<value.getstr();
      break;
      case FUNC:
      stream<<value.getfunc();
      break;
	  case PAIR: {
          auto ptr = value.getpair();
          if (!ptr) {
              stream << "nil";
              break;
          }
		  auto p = *ptr;
		  stream << "(" << std::get<0>(p) << "," << std::get<1>(p) << ")";
		  break;
	  }
      default:break;
    }
    stream<<")";
    return stream;
  }
}