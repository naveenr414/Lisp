#ifndef NODE_H
#define NODE_H

#include "operator.h"
#include <vector> 
#include <string> 
#include "environment.h"

class Node
{
  public:
    Node(int v);
    Node (std::string t);
    Node(Operator o, std::vector<Node*> oper);
    void print_value();
    void evaluate(Environment* e);
    int get_value();
    std::string get_token();
  private: 
    int value;
    std::string token; 
    bool evaluated;
    bool is_token;
    Operator op;
    std::vector<Node*> operands;
};

#endif