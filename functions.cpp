#include "functions.h"
#include "operator.h"

int add(int a[])
{ 
  return a[0]+a[1];
}

int sub(int a[])
{
  return a[0]-a[1];
}

int mul(int a[])
{
  return a[0]*a[1];
}

int divide(int a[])
{
  return a[0]/a[1];
}

int identity(int a[])
{
  return a[0];
}

Operator* add_operator = new Operator(add,{"ADD","+"});
Operator* sub_operator = new Operator(sub,{"SUB","-"});
Operator* mul_operator = new Operator(mul,{"MULTIPLY","*"});
Operator* div_operator = new Operator(divide,{"DIVIDE","/"});
Operator* identity_operator = new Operator(identity,{});

Operator* operator_list[] = {add_operator,sub_operator,mul_operator,div_operator,identity_operator,NULL};
