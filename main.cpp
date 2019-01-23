#include <iostream>
#include <string> 
#include <vector> 
#include "node.h" 
#include "parse.h"

using namespace std;

int main() {
  Node* n_three = parse("(+ 3 3 3)");
  
  n_three->evaluate();
  n_three->print_value();
  
    
  return 0;
}