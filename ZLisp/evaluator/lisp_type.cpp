#include "lisp_type.h"
#include <string>
#include <map>

namespace eval {
	std::string const lispTypeName(LispType type) {
		switch (type) {
		case LispType::STR: return "String";
		case LispType::NUM: return "Number";
		case LispType::FUNC: return "Function";
		case LispType::PAIR: return "Pair";
		case LispType::VARARG: return "Any number of values";
		default: return "Anything";
		}
	}
	std::map<std::string, LispType> lisptype_names({
		{"str",LispType::STR},
		{"num",LispType::NUM},
		{"func",LispType::FUNC},
		{"pair",LispType::PAIR},
		{"any",LispType::ANY} });
	LispType const stringToLispType(std::string& str) {
		auto t = lisptype_names.find(str);
		return (t == lisptype_names.end()) ? LispType::ANY : lisptype_names[str];
	}
}