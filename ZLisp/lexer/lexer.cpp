#include "lexer.h"
#include <cstdlib>
#include <vector>
#include <regex>
#include <tuple>
#include <iostream>
#include <sstream>

namespace lex{

Tokenizer::Token::Token(int type, std::string value, int location): type(type),
                value(value),
                location(location){}

Tokenizer::Tokenizer(const std::vector<std::pair<std::string,int> >& lexeme_to_tokentype){
  if (lexeme_to_tokentype.size()==0){
    pattern=std::regex("");
    return;
  }
  std::ostringstream regex;
  int group = 1;
  for (auto it = lexeme_to_tokentype.begin();
       it != lexeme_to_tokentype.end();
       it++){
         auto lexeme = std::get<0>(*it);
         auto type = std::get<1>(*it);
         if (it != lexeme_to_tokentype.begin()){
           regex<<"|";
         }
         regex<<"(" << lexeme <<")";
         this->group_to_type[group]=type;
         group++;
         group+= std::regex(lexeme).mark_count();

       }
  this->max_group = group;
  this->pattern=std::regex(regex.str());

}

std::vector<Tokenizer::Token> Tokenizer::tokenize(std::string input) {
  std::vector<Tokenizer::Token> tokens;
  auto match = std::sregex_iterator(input.begin(),input.end(),pattern);
  auto end = std::sregex_iterator();
  for (; match!=end; match++){
    for (auto pair : group_to_type){
      auto result = *match;
      auto submatch = result[pair.first];
      if (submatch.length() != 0){
        tokens.push_back(Tokenizer::Token(pair.second,submatch.str(),result.position(pair.first)));
        break;
      }
    }
  }
  return tokens;
}
}