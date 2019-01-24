#include <iostream>
#include "repl.h"
#include "node.h"
#include <string> 
#include "parse.h"

void run_repl()
{
  while (true)
  {
    std::string inp; 
    std::cout << "> ";
    getline(std::cin, inp);
    
    Node* n = parse(inp);
  
    n->evaluate();
    n->print_value();
  }
}