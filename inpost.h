/*
	inpost.h
	Date Written: 3/18
	Created by Kyin Edwards
*/

#ifndef INPOST_H
#define INPOST_H

#include <iostream>
#include <iomanip>
#include <cstddef>
#include <string>

/*
	Declares the member functions used for the conversion of infix expression to an equivalent postfix expression. The convert() function is found in the inpost header file.   
*/

std::string convert(const std::string&);
int precedence(char);

#endif