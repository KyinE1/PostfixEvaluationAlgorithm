#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

struct node {
	int value;
	node* next;
	
	node(int value, node* next = nullptr) {
		this->value = value;
		this->next = next; 
	}
};

class mystack {
	private:
		node* stack_top_pointer;
		size_t stack_size;
	
	public:
		mystack();
		mystack(const mystack&);  
		~mystack();
		mystack&operator=(const mystack&);
		size_t size() const;
		bool empty() const;
		void clear();
		const int& top() const;
		void push(int);
		void pop();
		void clone(const mystack&); 
};

#endif
