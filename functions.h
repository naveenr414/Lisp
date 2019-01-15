#include "operator.h"

int add(int a[]);
int sub(int a[]);
int mul(int a[]);
int divide(int a[]);
int identity(int a[]);

extern Q* add_operator;
extern Q* sub_operator;
extern Q* mul_operator;
extern Q* div_operator;
extern Q* identity_operator;
extern Q* operator_list[];