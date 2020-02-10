#include "core_functions.h"
#include "function.h"
#include "..//zlisp_evaluator.h"
namespace eval {

	const Function* equal() {
		const static Function* eq = new Function({ LispType::ANY,LispType::ANY }, [](auto& v) {return v[0].equal(v[1]); });
		return eq;
	}

	const LispVal isnil() {
		return eval::eval("(fn (_x) (= _x nil))");
	}
	/*
	const Function* comp() {
		const static Function* comp = new Function({ LispType::FUNC,LispType::FUNC }, [](std::vector<LispVal>& v) {return new Function({ LispType::ANY }, [](auto& v2) {return  });
		return comp;
	}*/
	
}