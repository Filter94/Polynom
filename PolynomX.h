#ifndef PolynomX_h
#define PolynomX_h
#include "Polynom.h"

/*
1) "Многочлен от переменной x".  Новый метод:

   * вычисление производной многочлена (результат - новый многочлен).
*/

class PolynomX:public Polynom{
	public:
			PolynomX(){};
			PolynomX(const PolynomX& p){Polynom::copy(p);}
			//PolynomX& operator = (const PolynomX &);
			PolynomX getDerivative()const;
};
#endif