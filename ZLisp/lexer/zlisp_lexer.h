#ifndef LEXER_ZLISP_LEXER_H
#define LEXER_ZLISP_LEXER_H
#include "lexer.h"
#include <map>
#include <cstdlib>
#include <regex>
#include <string>
#include <vector>
/**
* A specialized lexer specifically for zlisp code
*/
namespace lex{
enum LispTokenType{
  NUM,
  STR,
  SYM,
  LPAREN,
  RPAREN,
  COMMENT,
  INVALID
};

std::vector<Tokenizer::Token> lex(std::string source);
}
#endif