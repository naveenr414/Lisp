#include <iostream>
#include "repl.h"
#include "node.h"
#include <string> 
#include "parse.h"
#include "environment.h"

void run_repl()
{
  Environment e;
  e.add("x",5);
  
  std::string inp; 
  
  while (inp != "quit")
  {
    std::cout << "> ";
    getline(std::cin, inp);
    
    Node* n = parse(inp);
  
    n->evaluate(&e);
    n->print_value();
  }
}