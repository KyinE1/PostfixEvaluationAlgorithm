#include <string>
#include <cctype>
#include "mystack.h"
#include "inpost.h"

/** Convert infix expression.
 *
 * @param infix: Portion of the expression stored in the string object. 
 * @return: Conversion from infix. 
 */
std::string convert(const std::string& infix) {
	size_t index = 0;
	std::string postfix; 
	mystack s;  

	
	// Get to the end of the infix string.
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
			
			// Top character is the left parenthesis. 			
			if (!s.empty()) {
				s.pop();
			}
			
			index++;
		}
	
		// This is an operator		
		else {
			while (!s.empty() && precedence(infix[index]) <= precedence(s.top())) {
				postfix += s.top();
				s.pop();
			}
			
			s.push(infix[index]);
			index++;
		}
	}
	
	// Get top character of the stack and append to postfix string. 	 
	while (!s.empty()) {
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
