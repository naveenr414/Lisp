#include "operator.h"
#include <string> 
#include <functional>
#include <vector> 

Q::Q() : num_operands(0) {}
Q::Q(int n,std::function<int(int[])> f, std::vector<std::string> s) : num_operands(n), func(f), symbols(s) { }

int Q::num_symbols () {
  return Q::symbols.size();
}  

std::string Q::get_symbol (int i) 
{
  return symbols.at(i);
}

int Q::run (int a[]) 
{
  return func(a);
}