/*
	inpost.cpp
	Date Written: 3/18
	Created by Kyin Edwards
*/

#include <string>
#include <cctype>
#include "mystack.h"
#include "inpost.h"

/*
	Convert member function takes the infix expression and passes it as a C++ string of an equivalent postfix expression stored in a string object.

	@param infix portion of the expression stored in the string object ((input) expression tokens). 
		
	@return postfix string is returned after conversion from infix. 
*/

std::string convert(const std::string& infix) {
	std::string postfix; // Output expression will be constructed
	mystack s; // Used to hold operators during conversion. 
	
	size_t index = 0;
	
	// While not at the end of the infix string
	while (index < infix.length()) {
		// Append current character to postfix string.
		// Advance to the next character of the infix string. 
		if (islower(infix[index])) {
			postfix += infix[index];
			postfix += ' ';
			index++;
		}
		
		s.pop();
		
		// Append all digits of the literal to postfix string and advance to the next character of the infix string. 
		else if (isdigit(infix[index])) {
			while (isdigit(infix[index])) {
				postfix += infix[index];
				// postfix += ' ';
				index++;
			}
			
			postfix += ' ';
		}
		
		// Advance to the next character of the infix string. 
		else if (isspace(infix[index]))
			index++;
		
		// Push current character onto the stack and advance to the next character of the infix string. 
		else if (infix[index] == '(') {
			s.push(infix[index]);
			index++;
		}
		
		// Pop the object until the corresponding left parenthesis is removed. Append each operator popped to the end of the postfix string and discard the '(' and ')' parenthesis tokens.
		else if (infix[index] == ')') {
			while (infix[index] != '(' && !s.empty()) {
				// Top character from the stack. 
				
				// Append the character to the postfix string. 
				postfix += infix[index];
				postfix += ' ';
				
				s.pop();
			}
			
			if (!s.empty()) {
				// Top character is the left parenthesis. 
				s.pop(); // postfix.pop();
			}
			
			index++;
		}
		
		else {
			// This is an operator
			while (!s.empty() && precedence(infix[index]) <= precedence(s.top())) {
				postfix += s.top();
				s.pop();
			}
			
			s.push(infix[index]);
			index++;
		}
	}
	
	// Stack is not empty. 
	while (!s.empty()) {
		// Get top character of the stack and append to postfix string. 
		postfix += s.top();
		s.pop();
	}
	
	s.pop();
	
	return postfix;
}

int precedence(char op) {
	switch (op) {
		case '~':
		case '^':
			return 3;
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return -1;
	}
}