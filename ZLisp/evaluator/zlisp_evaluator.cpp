#include "zlisp_evaluator.h"
#include "..//parser/astnode.h"
#include "..//parser/zlisp_parser.h"
#include "..//lexer/zlisp_lexer.h"
#include "types.h"
#include <vector>
#include <memory>
namespace eval {
	
	const LispVal eval(std::vector<std::shared_ptr<parse::ASTNode>>& tree) {
		if (tree.empty()) return LispVal::NIL;
		int i;
		for (i = 0; i < tree.size() - 1; i++) tree[i]->evaluate();
		return tree[i]->evaluate();
	}

	const LispVal eval(std::string code) {
		auto tokens = lex::lex(code);
		auto tree = parse::parse(tokens);
		return eval(tree);
	}
	

}