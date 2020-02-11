#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <streambuf>
#include "lexer/lexer.h"
#include "lexer/zlisp_lexer.h"
#include "parser/zlisp_parser.h"
#include "parser/astnode.h"

int main(int argc, char* argv[]) {
	
	try 
	{
		std::ifstream t(argv[1]);
		std::string code((std::istreambuf_iterator<char>(t)),
			             std::istreambuf_iterator<char>());
		
		auto lex = lex::lex(code);
		
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