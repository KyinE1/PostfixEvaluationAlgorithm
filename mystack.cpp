/*
	mystack.cpp
	Date Written: 3/18
	Created by Kyin Edwards
*/

#include "mystack.h"

/*
	Default Constructor.  
*/ 
mystack::mystack() {
	stack_size = 0;
	stack_top_pointer = nullptr;
}

/*
	Copy constructor for mystack class initializes a new mystack object to the same string as the existing mystack object x.
	
	@param x object of the mystack class.
*/
mystack::mystack(const mystack& x) {
	// if (stack_size == 0)
		// stack_top_pointer = nullptr;
		
	// Set the new stack object's list to empty.  
	stack_top_pointer = nullptr;
	
	// Copy the other stack's size. 
	stack_size = x.stack_size;
	
	// Copy the other stack's linked list. 
	clone(x);
}

/*
	The destructor makes a call to the clear() method. 
*/
mystack::~mystack() {
	clear();
}

/*
	Assigns one mystack object (x) to the object that called the member function (pointed to by this).
	
	@param x object of the mystack class. 
	
	@return address of the object x.  
*/
mystack& mystack::operator=(const mystack& x) {
	// Check for self-assignment.
    if (this != &x) {
        // Left stack object is made empty. 
        clear();

        // Copy the other stack's size. 
        stack_size = x.stack_size;
		
		// Copy the other stack's linked list. 
		clone(x);
    }
	
	// Return this object (return *this).
	return *this;
}

/*
	Get the size of the stack.  
	
	@return the stack_size. 
*/
size_t mystack::size() const {
	return stack_size;
}

/*
	Evaluates if the stack_size is empty. 
	
	@return true if the stack_size is 0, else false. 
*/
bool mystack::empty() const {
	return (stack_size == 0);
}

/*
	Reset the stack_size to default value and delete all nodes in the stack's link list.
*/
void mystack::clear() {
	// As long as the stack is not empty, pop() method is called. 
	while (!empty())
		pop();
}		

/*
	Return value in the top node of the stack (first node in the linked list pointed to by the stack_top_pointer).
		
	@return the stack_top_pointer->value (pointer to value).
*/
const int& mystack::top() const {
	return stack_top_pointer->value;
}

/*
	Push integer value onto the top of the stack. 
*/
void mystack::push(int value) {
	// Allocation of a new stack node needs to call the struct.
	node* new_node = new node(value, stack_top_pointer);

	new_node->value = value;
	new_node->next = stack_top_pointer;
	
	stack_top_pointer = new_node;
	
	stack_size = stack_size + 1; 
}

/*
	Pop the top item off of the stack and delete the node that contained it (the top item is removed from the stack).
*/
void mystack::pop() {
	// Temp node pointer.
	node* delete_node = stack_top_pointer;
	stack_top_pointer = stack_top_pointer->next;
	
	// Delete the node. 
	delete delete_node; // Or delete[] delete_node.
	
	stack_size = stack_size - 1; // Or stack_size--;
}

/*
	Copies linked list from the stack x to this object.
	
	@param x object of the mystack class. 
*/
void mystack::clone(const mystack& x) {
	node* last = nullptr;
	node* ptr = x.stack_top_pointer; 
	
	while (ptr != nullptr) {
		// Allocation of a new stack node needs to call the stuct. 
		node* new_node = new node(ptr->value);
		
		if (last == nullptr)
			stack_top_pointer = new_node;
			
		else
			last->next = new_node; 
			
		last = new_node;
		ptr = ptr->next; 
	}
}