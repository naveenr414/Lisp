#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <map> 
#include <string> 

class Environment
{
  private: 
    std::map<std::string, int> m;
  public:
    Environment();
    void add(std::string s, int a);
    int lookup(std::string s); 
};

#endif 