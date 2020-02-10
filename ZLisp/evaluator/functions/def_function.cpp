#pragma once
#include "function.h"
#include "def_function.h"
#include "..//..//parser/symbolnode.h"
#include "..//symbol_table.h"
namespace eval {
	DefFunction::DefFunction() :Function({ LispType::ANY,LispType::ANY },nullptr) {
		
	}
	const LispVal DefFunction::evaluate(const std::vector<std::shared_ptr<parse::ASTNode>>& args) const {
		if (args.size() != 2) throw "Def requires 2 arguments. Received " + args.size();
		if (auto sym = dynamic_cast<parse::SymbolNode*>(args[0].get())) {
			addToLookupTable(sym->symbol, args[1].get()->evaluate());
			return lookup(sym->symbol);
		}
		else {
			throw "Def requires a symbol for its first arguments.";
		}

	}
	const Function* DefFunction::deffunction() {
		const static Function* deffunction = new DefFunction();
		return deffunction;
	}
	 
}

