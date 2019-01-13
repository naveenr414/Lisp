#include "node.h" 
#include "operator.h"
#include <iostream>

Node::Node(int v) : value(v), evaluated(true) { }
Node::Node(Q o, Node* op_one, Node* op_two) : evaluated(false), op(o), operand_one(op_one), operand_two(op_two) { }

void Node::print_value() 
{
  std::cout << value << "\n";
}

void Node::evaluate() 
{
  int value_one;
  int value_two;
  
  if (!evaluated) 
  {
    operand_one->evaluate();
    operand_two->evaluate();
    
    value_one = operand_one->get_value();
    value_two = operand_two->get_value();
    
    int values[] = {value_one,value_two};
    
    value = op.run(values);
  }
}

int Node::get_value() 
{ 
  return value;
}