#include "node.h"
#include "parse.h"
#include <string> 
#include <iostream>
#include <ctype.h>

Operator to_operator(std::string s)
{
  
  if (s == "ADD" || s == "+") 
  {
    return Operator::ADD;
  }
  else if (s == "SUBTRACT" || s == "-") 
  {
    return Operator::SUBTRACT;
  }
  else if (s == "MULTIPLY" || s == "*") 
  {
    return Operator::MULTIPLY;
  }
  else if (s == "DIVIDE" || s == "/") 
  {
    return Operator::DIVIDE;
  }
  
  return Operator::ADD;
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