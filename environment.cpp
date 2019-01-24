#include <map>
#include <string> 
#include "environment.h"

Environment::Environment() {}
 
void Environment::add(std::string s, int a)
{
  m[s] = a;
}

int Environment::lookup(std::string s)
{
  return m[s];
}