#ifndef NODE_H
#define NODE_H

#include "operator.h"

class Node
{
  public:
    Node(int v);
    Node(Q o, Node* op_one, Node* op_two);
    void print_value();
    void evaluate();
    int get_value();
  private: 
    int value;
    bool evaluated;
    Q op;
    Node* operand_one;
    Node* operand_two;
};

#endif