#include "operator.h"
#include <string> 
#include <functional>
#include <vector> 

Q::Q(int n,std::function<int(int[])> f, std::vector<std::string> s) : num_operands(n), func(f), symbols(s) { } 