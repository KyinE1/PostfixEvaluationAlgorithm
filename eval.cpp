/*
	eval.cpp
	Date Written: 3/18
	Created by Kyin Edwards
*/

#include "eval.h"

/*
	Evaluates postfix expression passed by the result of the convert function and returns the calculated value. 
	
	@param postfix passed by inpost.cpp. The expression to be evaluated (contains the postfix expression tokens).
		
	@return the top element of the stack.
	
	@note 
		postfix is a valid expression with no leading whitespace. 
		All operators/operands have atleat one space between them.
		postfix can contain any of the operators. 
		All constants are integers. 
		All exponents are >= 0.
*/
int evaluate(const std::string& postfix) {
    std::string op;
    std::stringstream ss(postfix); // Create a stringstream object from the postfix string.		
	mystack eval_stack; // Holds operands during evaluation.
	int result; 

    // You can now read from the stringstream as if it were standard input. The end of the string will be treated as the end of input.
    while (ss >> op) {
        // op is a C++ string containing the next operator/operand in the postfix expression.
		if (islower(op[0])) {
			// If op[0] is lowercase, subtract 'a' and push to stack. 
			result = op[0] - 'a';
			eval_stack.push(result);			
		}
		
		// If first character is a digit, convert the string to an int and push result onto stack.  
		else if (isdigit(op[0])) {
			result = std::stoi(op);
			eval_stack.push(result);
		}
		
		// If first character is the tilda, get top item on stack as operand, pop the stack, multiply the operand by -1 and push the result onto the stack.  
		else if (op[0] == '~') {
			// Top item on stack as operand.
			result = eval_stack.top();
			eval_stack.pop();
			// Mult by -1.
			result = (result * -1);
			eval_stack.push(result);
		}
		
		// This is a binary operator. 
		else {
			int right_operand, left_operand;
			
			right_operand = eval_stack.top(); // Get top item on stack as right operand.
			// eval_stack.pop();
			left_operand = eval_stack.top();// Get top item on stack as left operand.
			// eval_stack.pop();
		
			// Math based on operator symbol.
			if (op[0] == '^')
				result = pow(left_operand, right_operand);
			
			else if (op[0] == '/')
				if (right_operand == 0) {
					std::cout << "*** Division by 0 ***\n";
					result = 0;
				}
					
				else
					result = left_operand / right_operand;
					
			else if (op[0] == '*')
				result = left_operand * right_operand;
				
			else if (op[0] == '+')
				result = left_operand + right_operand;
			
			else if (op[0] == '-')
				result = left_operand - right_operand;

			eval_stack.push(result);
		}
    }
	
	return eval_stack.top(); // Return top element of the stack.
}