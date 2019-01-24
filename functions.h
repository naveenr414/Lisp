#include "operator.h"
#include <vector> 
#include "node.h"
#include "environment.h"

std::vector<int> run_operands(std::vector<Node*> operands,Environment* e);  
int add(std::vector<Node*> operands,Environment* e);
int sub(std::vector<Node*> operands, Environment* e);
int mul(std::vector<Node*> operands, Environment* e);
int divide(std::vector<Node*> operands, Environment* e);
int identity(std::vector<Node*> operands, Environment* e);
int maximum(std::vector<Node*> operands, Environment* e);
int minimum(std::vector<Node*> operands, Environment* e);
int absolute(std::vector<Node*> operands, Environment* e);
int rem(std::vector<Node*> operands, Environment* e);
int define(std::vector<Node*> operands, Environment* e);

extern Operator* add_operator;
extern Operator* sub_operator;
extern Operator* mul_operator;
extern Operator* div_operator;
extern Operator* identity_operator;
extern Operator* max_operator;
extern Operator* min_operator;
extern Operator* abs_operator;
extern Operator* rem_operator;
extern Operator* define_operator;
extern Operator* operator_list[];