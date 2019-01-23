#include "operator.h"
#include <string> 
#include <functional>
#include <vector> 

Operator::Operator() {}
Operator::Operator(std::function<int(int[])> f, std::vector<std::string> s) : func(f), symbols(s) { }

int Operator::num_symbols () {
  return Operator::symbols.size();
}  

std::string Operator::get_symbol (int i) 
{
  return symbols.at(i);
}

int Operator::run (int a[]) 
{
  return func(a);
}