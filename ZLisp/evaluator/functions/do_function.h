#pragma once
#include "function.h"
#include "..//types.h"
#include "..//..//parser/astnode.h"
/**
* The DoFunction is a special function
* that allow a series of lisp vals to be executed in sequence.
* Such as:
* (do (println "First") (println "Second") (println "Third"))
*/
namespace eval {
	class DoFunction :
		public Function {
	public:
		static const Function* dofunc();
		virtual const LispVal evaluate(const std::vector<std::shared_ptr<parse::ASTNode>>& args) const;
	private:
		DoFunction();


	};

}

