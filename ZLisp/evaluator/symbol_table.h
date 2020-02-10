#pragma once
#ifndef EVALUATOR_SYMBOL_TABLE_H
#define EVALUATOR_SYMBOL_TABLE_H

#include <map>
#include "types.h"
#include "functions/io_functions.h"
#include "functions/function.h"
namespace eval {

	LispVal lookup(std::string key);
	void addToLookupTable(std::string key, const Function* fn, bool isEnclosedVariable=false);
	void addToLookupTable(std::string key, LispVal fn, bool isEnclosedVariable=false);
	void initializeLookupTable();
	void popSymbol(const std::string key);
	std::map<std::string, LispVal> closureVariables();

};
#endif