#include "operator.h"
#include <string> 
#include <functional>
#include <vector> 

Q::Q() {}
Q::Q(std::function<int(int[])> f, std::vector<std::string> s) : func(f), symbols(s) { }

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