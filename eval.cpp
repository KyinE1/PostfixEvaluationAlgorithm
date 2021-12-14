#include "eval.h"

/** Evaluates postfix expression.
 * 
 * @param postfix: The expression to be evaluated.
 * @return: Calculated value.
 * @note: 
 * 		All operators/operands have atleat one space between them.
 * 		All constants are integers. 
 * 		All exponents are >= 0.
 */
int evaluate(const std::string& postfix) {
    std::string op;
    std::stringstream ss(postfix);		
	mystack eval_stack; 
	int result; 

    // You can now read from the stringstream as if it were standard input. The end of the string will be treated as the end of input.
    while (ss >> op) {
	        
		// If op is lowercase, subtract 'a' and push to stack.         
		if (islower(op[0])) {
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
			result = eval_stack.top();
			eval_stack.pop();
			result = (result * -1);
			eval_stack.push(result);
		}
		
		// This is a binary operator. 
		else {
			int right_operand, left_operand;
			
			right_operand = eval_stack.top();
			left_operand = eval_stack.top();
		
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
	
	return eval_stack.top();
}
