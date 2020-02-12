
#include <map>
#include <stack>
#include "symbol_table.h"
#include "types.h"
#include "functions/io_functions.h"
#include "functions/num_functions.h"
#include "functions/if_function.h"
#include "functions/lambda_function.h"
#include "functions/def_function.h"
#include "functions/function.h"
#include "functions/core_functions.h"
#include "functions/list_functions.h"
#include "functions/do_function.h"
#include <set>
namespace eval {
	
	std::map<std::string, std::stack<LispVal>> lookupTable;

	std::map<std::string, int> enclosedCount;
	void addToLookupTable(const std::string key, const Function* fn, bool isEnclosedVariable) {
		addToLookupTable(key, LispVal(fn),isEnclosedVariable);
	}

	void addToLookupTable(const std::string key, const LispVal val, bool isEnclosedVariable) {
		auto& stack = lookupTable[key];
		stack.push(val);
		if (isEnclosedVariable) {
			enclosedCount[key] += 1;
		}
	}

	void initializeLookupTable(){
		addToLookupTable("if", IfFunction::iffunc());

		addToLookupTable("nil", LispVal::NIL);
		addToLookupTable("fn", LambdaFunction::lambdaFunction());
		addToLookupTable("nil?", isnil());
		addToLookupTable("println", println());
		addToLookupTable("mult", mult());
		addToLookupTable("div", div());
		addToLookupTable("mod", mod());
		addToLookupTable("subtr", subtr());
		addToLookupTable("add", add());
		addToLookupTable("<", lessthan());
		addToLookupTable(">", greaterthan());
		
		addToLookupTable("true", LispVal(1));
		addToLookupTable("false", LispVal(2));

		addToLookupTable("def", DefFunction::deffunction());
		addToLookupTable("do", DoFunction::dofunc());
		addToLookupTable("=", equal());

		addToLookupTable("list", list());
		addToLookupTable("fst", fst());
		addToLookupTable("snd", snd());
		addToLookupTable("pair", _pair());
		addToLookupTable("cons", cons());
		addToLookupTable("head", head());
		addToLookupTable("tail", tail());
		addToLookupTable("get", get());
		addToLookupTable("map", map());
		addToLookupTable("iterate", iterate());
		addToLookupTable("reduce", reduce());
		addToLookupTable("filter", filter());
		addToLookupTable("concat", concat());
		addToLookupTable("length", length());
	
	}
	LispVal lookup(const std::string key) {
		if (lookupTable.size() == 0) initializeLookupTable();
		auto val = lookupTable.find(key);
		if (val == lookupTable.end()) {
			throw "No symbol with name " + key;
		}
		return val->second.top();
	}

	void popSymbol(const std::string key) {
		auto& stack = lookupTable[key];
		stack.pop();
		auto const it = enclosedCount.find(key);
		if (it == enclosedCount.end()) return;
		it->second--;
		if (it->second == 0) {
			//Remove it, this symbol is completely gone.
			enclosedCount.erase(it);
		}
	}

	
	std::map<std::string, LispVal> closureVariables() {
		std::map<std::string, LispVal> vars;
		for (auto const& pair : enclosedCount) {
			vars.insert({ pair.first,lookup(pair.first) });
		//	vars[key] = lookup(key);
		}
		return vars;

	}
	
}