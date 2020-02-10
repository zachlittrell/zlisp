#include <vector>
#include "../types.h"
#include "function.h"

#include "..//..//parser/astnode.h"
#include "../lisp_type.h"
#include <functional>
#include <sstream>
#include <string>
namespace eval{
	Function::Function(const std::vector<LispType>& params, const std::function<LispVal(std::vector<LispVal>&)> fn):fn(fn),parameters(params){

	}

	const std::string Function::show() const{
		std::stringstream ss;
		ss << "Function that takes:";
		for (LispType param : this->parameters) {
			ss << " " << lispTypeName(param);
		}
		return ss.str();
	}
	const LispVal Function::evaluate(const std::vector<std::shared_ptr<parse::ASTNode>>& args) const {
		const auto argsz = args.size();
		bool is_vararg = parameters.size() == 1 && parameters[0] == LispType::VARARG;
		if (!is_vararg && argsz != this->parameters.size()) {
			std::stringstream ss;
			ss << "Attempted to call function with " << args.size() << " arguments when " << parameters.size() << " required.";
			throw ss.str();
		}

		std::vector<LispVal> arguments;
		for (unsigned int i = 0; i < argsz; i++) {
			auto& node = args[i];
			const LispVal& v = node->evaluate();
			if (!is_vararg) {
				const auto& param = parameters[i];
				if (param != LispType::ANY && v.type != param) {
					//Wrong type
					std::stringstream ss;
					ss << "Parameter " << i << " requires " << lispTypeName(parameters[i]) << " but received " << lispTypeName(v.type) << ".";
					throw ss.str();
				}
			}
			arguments.push_back(v);
		}
		return fn(arguments);
	}

}