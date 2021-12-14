#include "mystack.h"

/** Constructor. */ 
mystack::mystack() {
	stack_size = 0;
	stack_top_pointer = nullptr;
}

/** Copy constructor. Sets attributes of the stack.
 *
 * @param x: mystack class object.
 */
mystack::mystack(const mystack& x) {  
	stack_top_pointer = nullptr;
	stack_size = x.stack_size; 
	clone(x);
}

/** Destructor. */
mystack::~mystack() {
	clear();
}

/** Assigns one mystack object (x) to the object that called the member function.
 *
 * @param x: mystack class object. 
 * @return: Address of the object.  
*/
mystack& mystack::operator=(const mystack& x) {
    if (this != &x) {
        clear();
        stack_size = x.stack_size; 
		clone(x);
    }
	
	// Return this object.
	return *this;
}

/** Accessor method. */
size_t mystack::size() const {
	return stack_size;
}

/** Evaluates if the stack_size is empty.
 * 
 * @return: True if the size is 0.  
 */
bool mystack::empty() const {
	return (stack_size == 0);
}

/** Reset the size to default value and delete all nodes in the stack's linked list. */
void mystack::clear() {
	while (!empty())
		pop();
}		

/** Get the first node's value from the stack.
 *
 * @return: Value of the top of the stack.
 */
const int& mystack::top() const {
	return stack_top_pointer->value;
}

/** Push integer value onto the top of the stack. */
void mystack::push(int value) {
	node* new_node = new node(value, stack_top_pointer);

	new_node->value = value;
	new_node->next = stack_top_pointer;
	stack_top_pointer = new_node;
	stack_size = stack_size + 1; 
}

/** Pop the top item off of the stack and delete the node that contained it. */
void mystack::pop() {
	node* delete_node = stack_top_pointer;
	stack_top_pointer = stack_top_pointer->next;
	 
	delete delete_node; 
	stack_size = stack_size - 1;
}

/** Copies linked list from the stack to this object.
 *	
 * @param x: Object of the mystack class. 
 */
void mystack::clone(const mystack& x) {
	node* last = nullptr;
	node* ptr = x.stack_top_pointer; 
	
	while (ptr != nullptr) {
		node* new_node = new node(ptr->value);
		
		if (last == nullptr)
			stack_top_pointer = new_node;			
		else
			last->next = new_node; 
			
		last = new_node;
		ptr = ptr->next; 
	}
}
