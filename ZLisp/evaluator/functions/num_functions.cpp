#include "num_functions.h"
#include "function.h"
#include "../lisp_type.h"
namespace eval {
	const Function* convert_binary_num_function(const std::function<double(double, double)> fn) {
		return new Function({ LispType::NUM,LispType::NUM }, [fn](auto& args) { return LispVal(fn(args[0].getnum(),args[1].getnum())); });
	}
	const Function* add() {
		const static Function* add = convert_binary_num_function([](auto n1, auto n2) {return n1 + n2; });
		return add;
	}
	const Function* mult() {
		const static Function* mult = convert_binary_num_function([](auto n1, auto n2) {return n1 * n2; });
		return mult;
	}

	const Function* div() {
		const static Function* div = convert_binary_num_function([](auto n1, auto n2) {return n1 / n2; });
		return div;
	}

	const Function* subtr() {
		const static Function* subtr = convert_binary_num_function([](auto n1, auto n2) {return n1 - n2; });
		return subtr;
	}

	const Function* mod() {
		const static Function* mod = convert_binary_num_function([](auto n1, auto n2) {return ((int)n1) % ((int)n2); });
		return mod;
	}
	const Function* lessthan() {
		const static Function* lessthan = convert_binary_num_function([](auto n1, auto n2) {return n1 < n2; });
		return lessthan;
	}

	const Function* greaterthan() {
		const static Function* greaterthan = convert_binary_num_function([](auto n1, auto n2) {return n1 > n2; });
		return greaterthan;
	}

	
}