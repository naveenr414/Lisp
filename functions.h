#include "operator.h"
#include <vector> 

int add(std::vector<int> a);
int sub(std::vector<int> a);
int mul(std::vector<int> a);
int divide(std::vector<int> a);
int identity(std::vector<int> a);

extern Operator* add_operator;
extern Operator* sub_operator;
extern Operator* mul_operator;
extern Operator* div_operator;
extern Operator* identity_operator;
extern Operator* operator_list[];