#ifndef OPERATOR_H
#define OPERATOR_H

class Node;

#include <string> 
#include <functional>
#include <vector>
#include "environment.h"

class Operator
{
  private: 
    std::function<int(std::vector<Node*>,Environment*)> func;
    std::vector<std::string> symbols;
    
  public:
    Operator();
    Operator(std::function<int(std::vector<Node*>,Environment*)> f, std::vector<std::string> s); 
    int num_symbols();
    std::string get_symbol(int i);
    int run(std::vector<Node*>,Environment* e);
};

#endif