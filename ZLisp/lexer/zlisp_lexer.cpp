#include "zlisp_lexer.h"
#include "lexer.h"
#include <cstdlib>
#include <map>
#include <vector>
#include <regex>
#include <vector>
#include <tuple>
namespace lex{
const std::vector<std::pair<std::string, int> > lexeme_to_lisp_token({
  {R"("(\.|[^\"\\])*")", LispTokenType::STR},
  {R"(-?\d+(\.\d+)?)",LispTokenType::NUM},
  {R"([A-Za-z_=<>?-]+)",LispTokenType::SYM},
  {R"(\()",LispTokenType::LPAREN},
  {R"(\))",LispTokenType::RPAREN},
  {R"(\S+)",LispTokenType::INVALID}
});

std::vector<Tokenizer::Token> lex(std::string source){
  Tokenizer tokenizer(lexeme_to_lisp_token);;
  
  
  return tokenizer.tokenize(source);
}
}