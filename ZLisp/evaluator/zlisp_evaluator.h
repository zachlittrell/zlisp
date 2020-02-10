#pragma once
#ifndef EVALUATOR_ZLISP_EVALUATOR_H
#define EVALUATOR_ZLISP_EVALUATOR_H
#include "types.h"
#include <vector>
#include "../parser/astnode.h"
namespace eval {

	const LispVal eval(std::vector<std::shared_ptr<parse::ASTNode>>& tree);
	const LispVal eval(std::string code);

}

#endif
