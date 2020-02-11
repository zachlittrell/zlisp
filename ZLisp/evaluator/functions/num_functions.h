#pragma once
#include "function.h"
#include <vector>
#include <functional>
/**
* Functions for working with numbers
*/
namespace eval {
	/**
	* Helper function that takes a function pointer for a binary num function and makes a LispVal wrapper.
	*/
	const Function* convert_binary_num_function(const std::function<double(double, double)> fn);
	const Function* add();
	const Function* lessthan();
	const Function* greaterthan();
}