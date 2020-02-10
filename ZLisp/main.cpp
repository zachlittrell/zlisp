#include <iostream>
#include <cstdlib>
#include "linkedlist.h"
#include "lexer/lexer.h"
#include "lexer/zlisp_lexer.h"
#include "parser/zlisp_parser.h"
#include "parser/astnode.h"
int main() {
	
	try 
	{
		
		auto lex = lex::lex(R"(
(map println (list 1 2 3 4)
)");
		
	auto parse = parse::parse(lex);
	for (auto& node : parse) {
		//std::cout << *node << std::endl;
		node->evaluate();
	}
}
	catch (const std::string& ex) {
		std::cerr<<ex<<std::endl;
	}
	catch (const char* ex) {
		std::cerr << ex<<std::endl;
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what();
	}
  system("pause");
  return 0;
}