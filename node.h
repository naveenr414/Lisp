#ifndef NODE_H
#define NODE_H

enum class Operator{ADD, SUBTRACT, MULTIPLY, DIVIDE};

class Node
{
  public:
    Node(int v);
    Node(Operator o, Node* op_one, Node* op_two);
    void print_value();
    void evaluate();
    int get_value();
  private: 
    int value;
    bool evaluated;
    Operator op;
    Node* operand_one;
    Node* operand_two;
};

#endif