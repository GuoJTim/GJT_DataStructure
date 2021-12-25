#include "../CircularList/CircularListFull.h"
#include "../ChainIterator/ChainIterator.h"
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <sstream>
class Polynomial;

class Term {
	friend Polynomial;
	friend std::ostream& operator<<(std::ostream&, Polynomial&); // out stream
	friend std::istream& operator>>(std::istream&, Polynomial&); // input stream
	Term Set(float coef,int exp){
		this->coef = coef;
		this->exp = exp;
		return *this;
	}
private:
	float coef;
	int exp;
};

class Polynomial {
	friend std::ostream& operator<<(std::ostream&, Polynomial&); // out stream
	friend std::istream& operator>>(std::istream&, Polynomial&); // input stream
private:
	CircularList<Term> poly;

public:
	Polynomial();
	~Polynomial();
	Polynomial operator+(Polynomial&);
	Polynomial operator-(Polynomial&);
	Polynomial operator*(Polynomial&);
	Polynomial operator=(const Polynomial&);
	float Eval(float f);
};
#include "Polynomial.cpp"
#endif
