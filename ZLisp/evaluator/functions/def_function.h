#pragma once
#include "function.h"
#include "..//types.h"
#include "..//..//parser/astnode.h"
/**
* Functions related to defining values
*/
namespace eval {
	class DefFunction :
		public Function
	{
	public:
		DefFunction();
		virtual const LispVal evaluate(const std::vector<std::shared_ptr<parse::ASTNode>>& args) const;
		const static Function* deffunction();
	};
}

