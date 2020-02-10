#ifndef LEXER_ZLISP_LEXER_H
#define LEXER_ZLISP_LEXER_H
#include "lexer.h"
#include <map>
#include <cstdlib>
#include <regex>
#include <string>
#include <vector>
namespace lex{
enum LispTokenType{
  NUM,
  STR,
  SYM,
  LPAREN,
  RPAREN,
  INVALID
};

std::vector<Tokenizer::Token> lex(std::string source);
}
#endif