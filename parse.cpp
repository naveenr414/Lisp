#include "node.h"
#include "parse.h"
#include "operator.h"
#include "functions.h"
#include <iostream>
#include <ctype.h>
#include <string> 
#include <vector>

Operator to_operator(std::string s)
{
  /* Identify what operator matches with a string 
     For example, + -> add 
  */ 
  
  int i = 0;
  while (operator_list[i] != NULL) 
  {
    for (int j = 0; j < operator_list[i]->num_symbols() ; j++ )
    {
      if (s == operator_list[i]->get_symbol(j))
      {
        return *operator_list[i];
      }
    }
    
    i++;
  }
  
  return *identity_operator;
}

Node* parse(std::string s) {
  int i = 0;
  
  // String is an expression 
  if (s[0] == '(') 
  {    
    // Parse the operator till white space 
    while(i++,s[i] != ' ') {}
    Operator op = to_operator(s.substr(1,i-1));
    i++;
    
    std::vector<std::string> string_operands;
    
    while(s.at(i) != ')') 
    {
      int start = i;
      
      if (s[i] != '(') 
      {
         while (i++,s[i] != ' ' && s[i] != ')') {}
      }
      else 
      {
         int left = 1;
         int right = 0;
         
         while (left != right) 
         {
           if (s[++i] == ')')
           {
             right++;
           }
           else if(s[i] == '(')
           {
             left++;
           }
         }
         
         i++;
      }
            
      string_operands.push_back(s.substr(start,i-start));
      while (s[i] == ' ') {i++;}
    }
        
    std::vector<Node*> operands;
    operands.reserve(string_operands.size());
    
    for(int j = 0; j < string_operands.size(); j++) 
    {
      operands.push_back(parse(string_operands.at(j)));
    }
                        
    Node* ret = new Node(op,operands);    
        
    return ret;
  }
  else
  {
    while(isdigit(s[i])){i++;}
        
    if (i != 0) 
    {
      // Number 
      Node* ret = new Node(std::stoi(s.substr(0,i),nullptr));
      return ret;
    }
    else 
    {
      // Token 
      Node* ret = new Node(s);
      return ret;
    }    
  }  
}