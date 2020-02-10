#include "if_function.h"
#include "..//types.h"
#include "..//..//parser/astnode.h"
#include <vector>
namespace eval {
	IfFunction::IfFunction() : Function({ LispType::NUM,LispType::ANY, LispType::ANY }, nullptr) {}
	
	  const Function* IfFunction::iffunc() {
		return  new IfFunction();
	}
	const LispVal IfFunction::evaluate(const std::vector<std::shared_ptr<parse::ASTNode>>& args) const {
		if (args.size() != 3) {
			throw "If requires 3 arguments. Received " + args.size();
		}
		auto const& condition = args[0]->evaluate();
		if (condition.type != LispType::NUM) {
			throw "If requires a num for its conditional. Received " + lispTypeName(condition.type);
		}
		return condition.getnum() == 0 ? args[2]->evaluate() : args[1]->evaluate();
	}
}