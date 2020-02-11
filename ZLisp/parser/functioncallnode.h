#ifndef PARSER_FUNCTIONCALLNODE_H
#define PARSER_FUNCTIONCALLNODE_H
#include "astnode.h"
#include "../evaluator/types.h"
#include <vector>
#include "..//evaluator/functions/lambda_function.h"
#include <iostream>

namespace parse{
class FunctionCallNode : public ASTNode{
  public:
  FunctionCallNode(const int location, const std::vector<std::shared_ptr<ASTNode>>& args);
  ~FunctionCallNode();
  virtual  void show(std::ostream& stream) const;
  virtual eval::LispVal evaluate();
  private:
  std::shared_ptr<ASTNode> head;
  const std::vector<std::shared_ptr<ASTNode>> arguments; 
  friend class eval::LambdaFunction;
};
}
#endif