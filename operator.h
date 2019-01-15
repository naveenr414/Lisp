#ifndef OPERATOR_H
#define OPERATOR_H

#include <string> 
#include <functional>
#include <vector>

class Q
{
  private: 
    std::function<int(int[])> func;
    std::vector<std::string> symbols;
    
  public:
    Q();
    Q(std::function<int(int[])> f, std::vector<std::string> s); 
    int num_symbols();
    std::string get_symbol(int i);
    int run(int a[]);
};

#endif