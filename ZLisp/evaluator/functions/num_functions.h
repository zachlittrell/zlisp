#pragma once
#include "function.h"
#include <vector>
#include <functional>
namespace eval {
	const Function* convert_binary_num_function(const std::function<double(double, double)> fn);
	const Function* add();
	const Function* lessthan();
	const Function* greaterthan();
}