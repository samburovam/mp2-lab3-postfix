#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"
#include <iostream>
#include <vector>

using namespace std;

class TPostfix
{
	string infix;
	string postfix;
	double* value; 
	TStack<char> stackOperation; 
	TStack<string> stackArguments; 
	TStack<double> stackValue; 
	TStack<double> stackValuePostfix; 

public:
	TPostfix();
	TPostfix(string _infix);
	string GetInfix();
	string GetPostfix();
	bool IsCorrect(); 
	void ToPostfix();
	double Calculate(); 
};

#endif
