#include "lisp_type.h"
#include <string>

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
}