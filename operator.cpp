#include "operator.h"
#include <string> 
#include <functional>
#include <vector> 
#include "node.h"
#include "environment.h"

Operator::Operator() {}
Operator::Operator(std::function<int(std::vector<Node*>,Environment*)> f, std::vector<std::string> s) : func(f), symbols(s) { }

int Operator::num_symbols () 
{
  return Operator::symbols.size();
}  

std::string Operator::get_symbol (int i) 
{
  return symbols.at(i);
}

int Operator::run (std::vector<Node*> a, Environment* e) 
{
  return func(a,e);
}