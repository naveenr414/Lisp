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

Q* add_operator = new Q(add,{"ADD","+"});
Q* sub_operator = new Q(sub,{"SUB","-"});
Q* mul_operator = new Q(mul,{"MULTIPLY","*"});
Q* div_operator = new Q(divide,{"DIVIDE","/"});
Q* identity_operator = new Q(identity,{});

Q* operator_list[] = {add_operator,sub_operator,mul_operator,div_operator,identity_operator,NULL};
