#pragma once
#ifndef EVALUATOR_SYMBOL_TABLE_H
#define EVALUATOR_SYMBOL_TABLE_H

#include <map>
#include "types.h"
#include "functions/io_functions.h"
#include "functions/function.h"
/**
* The global lookup table for symbols, both global and local.
*/
namespace eval {

	LispVal lookup(std::string key);
	void addToLookupTable(std::string key, const Function* fn, bool isEnclosedVariable=false);
	void addToLookupTable(std::string key, LispVal fn, bool isEnclosedVariable=false);
	void initializeLookupTable();

	void popSymbol(const std::string key);
	/**
	* Returns a submap of currently lexically scoped variables
	* that should be captured by any closure.
 	*/
	std::map<std::string, LispVal> closureVariables();

};
#endif