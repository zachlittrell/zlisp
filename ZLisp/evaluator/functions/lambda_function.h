#pragma once
#include "function.h"
#include <vector>
#include "..//..//parser///astnode.h"
#include <map>
namespace eval {
	class LambdaFunction : public Function {
	public:
		LambdaFunction();
		virtual const LispVal evaluate(const std::vector<std::shared_ptr<parse::ASTNode>>& args) const;
		static const Function* lambdaFunction();
	private:


	};
}