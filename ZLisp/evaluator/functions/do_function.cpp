#include "do_function.h"
#include "..//types.h"
#include "..//..//parser/astnode.h"
#include <vector>
namespace eval {
	DoFunction::DoFunction() : Function({ LispType::ANY}, nullptr) {}
	const Function* DoFunction::dofunc() {
		return  new DoFunction();
	}
	const LispVal DoFunction::evaluate(const std::vector<std::shared_ptr<parse::ASTNode>>& args) const {
		if (args.empty()) return LispVal::NIL;
		int i = 0;
		
		for (; i < args.size()-1; i++) {
			args[i]->evaluate();
		}
		return args[i]->evaluate();
	}


}