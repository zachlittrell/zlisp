#include "lambda_function.h"
#include "function.h"
#include "..//..//parser/astnode.h"
#include "..//..//parser/functioncallnode.h"
#include "..//..//parser/symbolnode.h"
#include "..//symbol_table.h"
#include <algorithm>
namespace eval {
	const Function* LambdaFunction::lambdaFunction() {
		static const Function* l = new LambdaFunction();
		return l;
	}
	LambdaFunction::LambdaFunction() : Function({ LispType::FUNC,LispType::ANY }, nullptr) {

		
	}
	const LispVal LambdaFunction::evaluate(const std::vector<std::shared_ptr<parse::ASTNode>>& args) const {
		if (args.size() < 2) throw "Lambda functions require a parameter list and body";
		if (auto fncall = dynamic_cast<parse::FunctionCallNode*>(args[0].get())) {
			std::vector<std::string> symbols;
			std::vector<LispType> types;
			LispType typehint = LispType::ANY;

			if (auto param1 = dynamic_cast<parse::SymbolNode*>(fncall->head.get())) {
				if (param1->symbol[0] == '^') {
					auto typestr = param1->symbol.substr(1);
					typehint = stringToLispType(typestr);
				}
				else {
					symbols.push_back(param1->symbol);
					types.push_back(typehint);
				}

				for (auto& node : fncall->arguments) {
					if (auto param = dynamic_cast<parse::SymbolNode*>(node.get())) {
						if (param->symbol[0] == '^') {
							//It's a typehint! 
							auto typestr = param->symbol.substr(1);
							typehint = stringToLispType(typestr);
						}
						else {
							symbols.push_back(param->symbol);
							types.push_back(typehint);
							typehint = LispType::ANY;
						}
					}
					else {
						throw "Lambda function parameters must be symbols or typehints.";
					}
				}
				if (types.size() == 0) {
					//We got here because the parameters must have been all type hints
					//In the current spec, that's fine.
				}
				std::vector<std::shared_ptr<parse::ASTNode>> body(args.begin()+1, args.end());
				const auto sz = body.size();
				auto const& enclosedVars = closureVariables();
				return LispVal(new Function(types, [symbols, body, enclosedVars,sz](auto& vec) {
					if (sz == 0) {
						return LispVal::NIL;
					}
					const auto argsz = vec.size();
					//Add enclosed vars
					for (auto const& pair : enclosedVars) {
						addToLookupTable(pair.first, pair.second, true);
					}
					//Add parameters
					for (unsigned int i = 0; i < argsz; i++) {
						addToLookupTable(symbols[i], vec[i],true);
					}
					auto i=0;
					for (i = 0; i < sz-1; i++)
						body[i]->evaluate();
					const auto& v = body[i]->evaluate();

					//Pop off parameters
					for (unsigned int i = 0; i < argsz; i++) {
						popSymbol(symbols[i]);
					}
					//Pop off vars
					for (auto const& pair : enclosedVars) {
						popSymbol(pair.first);
					}
					return v;
				}));
			}
			else {
				throw "Lambda function parameters must be symbols";
			}


		}
		else {
			throw "Lambda function parameters must be enclosed with parentheses.";
		}

	}
}