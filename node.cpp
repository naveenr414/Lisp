#include "node.h" 
#include "operator.h"
#include <iostream>
#include <vector> 

Node::Node(int v) : value(v), evaluated(true) { }
Node::Node(Operator o,std::vector<Node*> oper) : evaluated(false), op(o), operands(oper) { }

void Node::print_value() 
{
  std::cout << value << "\n";
}

void Node::evaluate() 
{
  if (!evaluated) 
  {
    std::vector<int> values; 
    values.reserve(operands.size());
    
    for (int i = 0; i < operands.size(); i++) 
    {
      operands.at(i)->evaluate();
      values.push_back(operands.at(i)->get_value());
    }
        
    value = op.run(values);
  }
}

int Node::get_value() 
{ 
  return value;
}