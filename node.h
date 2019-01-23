#ifndef NODE_H
#define NODE_H

#include "operator.h"
#include <vector> 

class Node
{
  public:
    Node(int v);
    Node(Operator o, std::vector<Node*> oper);
    void print_value();
    void evaluate();
    int get_value();
  private: 
    int value;
    bool evaluated;
    Operator op;
    std::vector<Node*> operands;
};

#endif