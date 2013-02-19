/*
 * str.cpp
 * Simple implementation of the string class
 * Based on the book Accelerated C++.
 * Uses the Vec class for memory implementation
 */
#include <iostream>
#include <cstring>
#include <cctype>
#include "vec.h"
#include "str.h"

using std::istream;		using std::ostream;
using std::isspace;

// overload the istream operator to work with Str
istream& operator>>(istream& is, Str& s)
{
	// start with a clear Str
	s.data.clear();

	// discard whitespace
	char c;
	while(is.get(c) && isspace(c))
		;

	if (is) { // steam is valid, and non-whitespace
		do s.data.push_back(c);
		while (is.get(c) && !isspace(c));

		// if 'is' still valid, we must have read whitespace
		if (is)
			is.unget();
	}

	return is; // so that we can use in multiple calls
}

// overload the + operator to define concatenations.
// this is done as nonmember function to enable lhs to be 
Str operator+(Str& l, Str& r)
{
	Str ret = l;
	// use the member function already defined
	ret += r;
	return ret;
}

