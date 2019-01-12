#ifndef PARSE_H
#define PARSE_H

#include "node.h"
#include <string> 

Node* parse(std::string s); 
Operator to_operator(std::string s);

#endif