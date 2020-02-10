#pragma once
#include "function.h"
#include "..//types.h"
#include "..//..//parser/astnode.h"
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

