#include <cstdlib>
#include <tuple>
#include <vector>
#include <regex>
#include <memory>
#include <map>
#include <string>
#ifndef LEXER_LEXER_H
#define LEXER_LEXER_H
/**
* A generalized lexer/tokenizer class
*/
namespace lex{
class Tokenizer{
public:
struct Token{
  int type;
  std::string value;
  int location;
  Token(int type, std::string value, int location);
};

Tokenizer(const std::vector<std::pair<std::string,int> >& lexeme_to_tokentype);

std::vector<Token> tokenize(std::string input); 

private:
std::regex pattern;
int max_group;
std::map<int, int> group_to_type;

};
}

#endif //PARSER_H