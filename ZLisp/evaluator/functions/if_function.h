#pragma once
#include "function.h"
#include "..//types.h"
#include "..//..//parser/astnode.h"
/**
* IfFunction captures the if-then-else construct.
* (if conditional val-for-true val-for-false)
*/
namespace eval {
	class IfFunction :
		public Function{
	public:
	 static const Function* iffunc();
	 virtual const LispVal evaluate(const std::vector<std::shared_ptr<parse::ASTNode>>& args) const;
	private:
		IfFunction();


	};

}

