#include "Polynomial.h"

std::ostream& operator<<(std::ostream& os,Polynomial &p){
	for (CircularList<Term>::ChainIterator it = p.poly.begin(); it != p.poly.end();it++){
		if (it != p.poly.begin()) {
			if (it->coef > 0) os << "+";
		}
		if (it->exp == 0){
			os << it->coef;
		}else{
			os << it->coef << "X^" << it->exp;
		}
	}
	os << std::endl;
	return os;
}


std::istream& operator>>(std::istream& is, Polynomial& poly) {
	Term temp;
	float coef;
	int exp;
	is >> coef >> exp;
	poly.poly.InsertTail(temp.Set(coef,exp));
	
	return is;
}

Polynomial::Polynomial() {
	//sentinel is in the circular list
}
Polynomial Polynomial::operator+(Polynomial &b){
	Term temp;
	CircularList<Term>::ChainIterator ai = poly.begin(), bi = b.poly.begin();
	Polynomial c;
	while(ai != poly.end() && bi != b.poly.end()){
		if (ai->exp == bi->exp){
			float sum = ai->coef + bi->coef;
			if(sum) c.poly.InsertTail(temp.Set(sum,ai->exp));
			ai++;
			bi++;
		}else if (ai->exp < bi->exp){
			c.poly.InsertTail(temp.Set(bi->coef,bi->exp));
			bi++;
		}else{
			c.poly.InsertTail(temp.Set(ai->coef,ai->exp));
			ai++;
		}
	}
	while(ai != poly.end()){
		c.poly.InsertTail(temp.Set(ai->coef,ai->exp));
		ai++;
	}
	while (bi != b.poly.end()){
		c.poly.InsertTail(temp.Set(bi->coef,bi->exp));
		bi++;
	}
	return c;
}
Polynomial Polynomial::operator=(const Polynomial &b){
	//do copy
	Polynomial np;
	np.poly = CircularList<Term>(b.poly); 
	return np;	
}
Polynomial Polynomial::operator-(Polynomial &b){
	Term temp;
	CircularList<Term>::ChainIterator ai = poly.begin(), bi = b.poly.begin();
	Polynomial c;
	while(ai != poly.end() && bi != b.poly.end()){
		if (ai->exp == bi->exp){
			float sum = ai->coef - bi->coef;
			if(sum) c.poly.InsertTail(temp.Set(sum,ai->exp));
			ai++;
			bi++;
		}else if (ai->exp < bi->exp){
			c.poly.InsertTail(temp.Set(bi->coef,bi->exp));
			bi++;
		}else{
			c.poly.InsertTail(temp.Set(ai->coef,ai->exp));
			ai++;
		}
	}
	while(ai != poly.end()){
		c.poly.InsertTail(temp.Set(ai->coef,ai->exp));
		ai++;
	}
	while (bi != b.poly.end()){
		c.poly.InsertTail(temp.Set(bi->coef,bi->exp));
		bi++;
	}
	return c;
}
Polynomial Polynomial::operator*(Polynomial &b){
	Term temp;
	CircularList<Term>::ChainIterator ai, bi ;
	Polynomial c;
	std::map<int, float> tempTermArray; //map find logn same as binary search
	// exp -> coef and which is sorted
	for (ai = poly.begin();ai != poly.end();ai++){
		for (bi = b.poly.begin();bi != b.poly.end();bi++){
			int exp = ai->exp + bi->exp;
			float coef = ai->coef * bi->coef;
			if (tempTermArray.find(exp) == tempTermArray.end()) {
				tempTermArray[exp] = coef;
			}
			else tempTermArray[exp] += coef;
		}
	}
	for (std::map<int, float>::reverse_iterator it = tempTermArray.rbegin(); it != tempTermArray.rend(); it++) {
		c.poly.InsertTail(temp.Set(it->second, it->first));
	}

	return c;
}

float Polynomial::Eval(float f) {
	float result = 0.0;
	for (CircularList<Term>::ChainIterator it = poly.begin();it != poly.end(); it++) {
		result += it->coef * pow(f,it->exp);
	}
	return result;
}

Polynomial::~Polynomial(){
	
}
