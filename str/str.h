/* str.h
 * Simple implementation of the string class
 * Based on the book Accelerated C++.
 * Uses the Vec class for memory implementation
 */
#ifndef STR_H
#define STR_H

#include <iostream>
#include <cstring>
#include <cctype>
#include "vec.h"

class Str {
	// overload the istream input operator
	friend std::istream& operator>>(std::istream&, Str&);
public:
	typedef Vec<char>::size_type size_type;
	Str() { } // allow the Vec default constructor to do the work.
	Str(size_type n, char c) : data(n, c) { }
	Str(const char* cp) {
		std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
	}
	template <class In> Str(In b, In e) {
		std::copy(b, e, std::back_inserter(data));
	}

	Str& operator+=(const Str& s) {
		std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
		return *this;
	}

	char& operator[](size_type i) { return data[i]; }
	const char& operator[](size_type i) const { return data[i]; }

private:
	Vec<char> data;
};

// non-member operator so that the concat can occur on eithier side
// and to enable multiple concats to occur, each giving a new Str
Str operator+(const Str&, const Str&); 

// implement this as nonmember since it does not change the state of
// any members and because ostream must be on lhs 
std::ostream& operator<<(std::ostream&, const Str&);

// TODO implememt any conversion to bool etc and some clear/erase ops

#endif
