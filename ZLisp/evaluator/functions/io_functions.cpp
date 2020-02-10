
#include "function.h"
#include <functional>
#include "io_functions.h"
namespace eval {
	const Function* println() {
		const static Function* println = new Function({ LispType::ANY }, [](auto& vals) {
			std::cout << vals[0].show() << std::endl;
			return vals[0]; });
		return println;
	}
	
}