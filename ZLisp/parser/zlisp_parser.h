#ifndef PARSER_ZLISP_PARSER_H
#define PARSER_ZLISP_PARSER_H
#include <vector>
#include <cstdlib>
#include "../lexer/lexer.h"
#include "astnode.h"
#include <memory>
namespace parse{
  std::vector<std::shared_ptr<ASTNode> > parse(std::vector<lex::Tokenizer::Token>& tokens);
}

#endif