#include "operator.h"

int add(int a[]);
int sub(int a[]);
int mul(int a[]);
int divide(int a[]);
int identity(int a[]);

extern Operator* add_operator;
extern Operator* sub_operator;
extern Operator* mul_operator;
extern Operator* div_operator;
extern Operator* identity_operator;
extern Operator* operator_list[];