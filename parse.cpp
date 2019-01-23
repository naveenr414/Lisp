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
  
  // Expression
  if (s[i] == '(') 
  {
    if (s[1] == ' ') {
      i++;
    }
    
    while(i++,s[i] != ' ') {}
    Operator op = to_operator(s.substr(1,i-1));
    i++;
    
    std::string string_operands[2];
    
    for (int j = 0; j<2; j++ ) 
    {
      int start = i;
      
      if (s[i] != '(') 
      {
         while (i++,s[i] != ' ') {}
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
            
      string_operands[j] = s.substr(start,i-start);
      while (i++,s[i] == ' ') {}
    }
    
            
    Node* operand_one = parse(string_operands[0]);
    Node* operand_two = parse(string_operands[1]);
        
    Node* ret = new Node(op,operand_one,operand_two);    
        
    return ret;
  }
  else
  {
    while(i++, isdigit(s[i])){}
    
    Node* ret = new Node(std::stoi(s.substr(0,i),nullptr));
    
    return ret;
  }
  
  Node* ret = new Node(0);
  return ret;
}