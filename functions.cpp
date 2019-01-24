#include "functions.h"
#include "operator.h"
#include <algorithm> 

std::vector<int> run_operands(std::vector<Node*> operands, Environment* e)
{
  std::vector<int> values; 
  values.reserve(operands.size());
  
  for (int i = 0; i < operands.size(); i++) 
  {
    operands.at(i)->evaluate(e);
    values.push_back(operands.at(i)->get_value());
  }
  
  return values; 
}

int add(std::vector<Node*> operands, Environment* e)
{ 
  std::vector<int> a = run_operands(operands,e);

  int res = 0;
  for (int i = 0;i<a.size() ; i++)
  {
    res+=a.at(i);
  }
  return res;
}

int sub(std::vector<Node*> operands, Environment* e)
{
  std::vector<int> a = run_operands(operands,e);
  int res = a.at(0);
  for (int i = 1;i<a.size() ; i++)
  {
    res-=a.at(i);
  }
  return res;
}

int mul(std::vector<Node*> operands, Environment* e)
{
  std::vector<int> a = run_operands(operands,e);

  int res = 1;
  for (int i = 0;i<a.size() ; i++)
  {
    res*=a.at(i);
  }
  return res;
}

int divide(std::vector<Node*> operands, Environment* e)
{
  std::vector<int> a = run_operands(operands,e);

  int res = a.at(0);
  for (int i = 1;i<a.size() ; i++)
  {
    res/=a.at(i);
  }
  return res;
}

int identity(std::vector<Node*> operands, Environment* e)
{
  std::vector<int> a = run_operands(operands,e);

  return a.at(0);
}

int maximum(std::vector<Node*> operands, Environment* e)
{
  std::vector<int> a = run_operands(operands,e);

  int m = a.at(0);
  for (int i = 1;i<a.size();i++)
  {
    m = std::max(m,a.at(i));
  }
  
  return m;
}

int minimum(std::vector<Node*> operands, Environment* e)
{
  std::vector<int> a = run_operands(operands,e);

  int m = a.at(0);
  for (int i = 1;i<a.size();i++)
  {
    m = std::min(m,a.at(i));
  }
  
  return m;
}

int absolute(std::vector<Node*> operands, Environment* e)
{
  std::vector<int> a = run_operands(operands,e);

  return std::abs(a.at(0));
}

int rem(std::vector<Node*> operands, Environment* e)
{
  std::vector<int> a = run_operands(operands,e);

  return a.at(0)%a.at(1);
}

int define(std::vector<Node*> operands, Environment* e)
{
  std::string name = operands.at(0)->get_token();
  operands.at(1)->evaluate(e);
  
  int value = operands.at(1)->get_value();
  
  e->add(name,value);
  
  return value;
}

Operator* add_operator = new Operator(add,{"+"});

Operator* sub_operator = new Operator(sub,{"-"});
Operator* mul_operator = new Operator(mul,{"*"});
Operator* div_operator = new Operator(divide,{"/"});
Operator* max_operator = new Operator(maximum,{"max"});
Operator* min_operator = new Operator(minimum,{"min"});
Operator* rem_operator = new Operator(rem,{"rem"});
Operator* abs_operator = new Operator(absolute,{"abs"});
Operator* define_operator = new Operator(define,{"define"});
Operator* identity_operator = new Operator(identity,{});

Operator* operator_list[] = {add_operator,sub_operator,
                              mul_operator,div_operator,
                              max_operator,min_operator,
                              rem_operator,abs_operator,
                              define_operator,
                              identity_operator,NULL};
