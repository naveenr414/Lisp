#include "functions.h"
#include "operator.h"
#include <algorithm> 

int add(std::vector<int> a)
{ 
  int res = 0;
  for (int i = 0;i<a.size() ; i++)
  {
    res+=a.at(i);
  }
  return res;
}

int sub(std::vector<int> a)
{
  int res = a.at(0);
  for (int i = 1;i<a.size() ; i++)
  {
    res-=a.at(i);
  }
  return res;
}

int mul(std::vector<int> a)
{
  int res = 1;
  for (int i = 0;i<a.size() ; i++)
  {
    res*=a.at(i);
  }
  return res;
}

int divide(std::vector<int> a)
{
  int res = a.at(0);
  for (int i = 1;i<a.size() ; i++)
  {
    res/=a.at(i);
  }
  return res;
}

int identity(std::vector<int> a)
{
  return a.at(0);
}

int maximum(std::vector<int> a)
{
  int m = a.at(0);
  for (int i = 1;i<a.size();i++)
  {
    m = std::max(m,a.at(i));
  }
  
  return m;
}

int minimum(std::vector<int> a)
{
  int m = a.at(0);
  for (int i = 1;i<a.size();i++)
  {
    m = std::min(m,a.at(i));
  }
  
  return m;
}

int absolute(std::vector<int> a)
{
  return std::abs(a.at(0));
}

int rem(std::vector<int> a)
{
  return a.at(0)%a.at(1);
}

Operator* add_operator = new Operator(add,{"+"});
Operator* sub_operator = new Operator(sub,{"-"});
Operator* mul_operator = new Operator(mul,{"*"});
Operator* div_operator = new Operator(divide,{"/"});
Operator* max_operator = new Operator(maximum,{"max"});
Operator* min_operator = new Operator(minimum,{"min"});
Operator* rem_operator = new Operator(rem,{"rem"});
Operator* abs_operator = new Operator(absolute,{"abs"});
Operator* identity_operator = new Operator(identity,{});

Operator* operator_list[] = {add_operator,sub_operator,
                              mul_operator,div_operator,
                              max_operator,min_operator,
                              rem_operator,abs_operator,
                              identity_operator,NULL};
