#include <vector>
#include <cstdlib>
#include <stack>
#include <string>
#include "../lexer/lexer.h"
#include "../lexer/zlisp_lexer.h"

#include "zlisp_parser.h"
#include "astnode.h"
#include "numnode.h"
#include "symbolnode.h"
#include "functioncallnode.h"
#include "strnode.h"
#include <memory>

namespace parse{
   std::vector<std::shared_ptr<ASTNode> > parse (std::vector<lex::Tokenizer::Token>& tokens){
   std::stack<std::vector<std::shared_ptr<ASTNode>> > tree;
   std::stack<int> functionlocs;
   std::vector<std::shared_ptr<ASTNode>> instructions;
   for (auto token : tokens){
     switch(token.type){
      case lex::INVALID:
      throw "Invalid token " + token.value + " at " + std::to_string(token.location);
      //Invalid token 
      case lex::COMMENT:
          break;
      case lex::LPAREN:
      tree.push(std::vector<std::shared_ptr<ASTNode>>());
      functionlocs.push(token.location);
      break;
      case lex::RPAREN:{
      if (tree.empty()){
              throw "Extra ) at " + std::to_string(token.location);
        //nothing to pop, throw exception
      }
      //make functional call node
      auto v = tree.top();
      int loc = functionlocs.top();
      tree.pop();
      functionlocs.pop();
      //Is it empty?
      if (v.empty()){
        throw "Empty function call at " + std::to_string(loc);
        //TODO throw error
      }
      std::shared_ptr<ASTNode> fn(new FunctionCallNode(loc,v));
      if (tree.empty())
        instructions.push_back(fn);
      else 
        tree.top().push_back(fn);      
      break;
      }
      case lex::NUM:{
	  std::shared_ptr<ASTNode> nn(new NumNode(token.location, token.value));
      if (tree.empty())
        instructions.push_back(nn);
      else 
        tree.top().push_back(nn);
      break;
     }
      case lex::SYM:{
	  std::shared_ptr<ASTNode> sn(new SymbolNode(token.location, token.value));
      if (tree.empty())
        instructions.push_back(sn);
      else 
        tree.top().push_back(sn);
      break;
      }
      case lex::STR:{
      std::shared_ptr<ASTNode> stn(new StrNode(token.location, token.value));
      if (tree.empty())
        instructions.push_back(stn);
      else 
        tree.top().push_back(stn);
      break;
     }
     }
   }
   if (!tree.empty()){
     //You need to add a right paren
     throw "Missing ) at end of program.";
   }
   return instructions;
  }
}

