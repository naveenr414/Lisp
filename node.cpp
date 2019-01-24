#include "node.h" 
#include "operator.h"
#include <iostream>
#include <vector> 
#include <string> 
#include "environment.h"

Node::Node(int v) : value(v), evaluated(true), is_token(false) { }
Node::Node(std::string t) : value(0), evaluated(false), is_token(true),token(t) {}
Node::Node(Operator o,std::vector<Node*> oper) : evaluated(false), op(o), operands(oper), is_token(false) { }

void Node::print_value() 
{
  std::cout << value << "\n";
}

void Node::evaluate(Environment* e) 
{
  if (!evaluated) 
  {  
    if(is_token)
    {
      value = e->lookup(token);
    }
    else 
    {
      value = op.run(operands,e);
    }
  }
}

int Node::get_value() 
{ 
  return value;
}

std::string Node::get_token()
{
  return token;
}