#ifndef PARSE_H
#define PARSE_H

#include "node.h"
#include "operator.h"
#include <string> 

Node* parse(std::string s); 
Q to_operator(std::string s);

#endif