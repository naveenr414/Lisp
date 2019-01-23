#include "functions.h"
#include "operator.h"

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

Operator* add_operator = new Operator(add,{"ADD","+"});
Operator* sub_operator = new Operator(sub,{"SUB","-"});
Operator* mul_operator = new Operator(mul,{"MULTIPLY","*"});
Operator* div_operator = new Operator(divide,{"DIVIDE","/"});
Operator* identity_operator = new Operator(identity,{});

Operator* operator_list[] = {add_operator,sub_operator,mul_operator,div_operator,identity_operator,NULL};
