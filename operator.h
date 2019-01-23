#ifndef OPERATOR_H
#define OPERATOR_H

#include <string> 
#include <functional>
#include <vector>

class Operator
{
  private: 
    std::function<int(std::vector<int>)> func;
    std::vector<std::string> symbols;
    
  public:
    Operator();
    Operator(std::function<int(std::vector<int>)> f, std::vector<std::string> s); 
    int num_symbols();
    std::string get_symbol(int i);
    int run(std::vector<int>);
};

#endif