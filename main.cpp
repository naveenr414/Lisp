#include <iostream>
#include "node.h" 
#include "parse.h"
#include "operator.h"

using namespace std;

int main() {
  Node* n_three = parse("(+ 5 (- 3 (/ 8 7)))");
  
  n_three->evaluate();
  n_three->print_value();
    
  return 0;
}