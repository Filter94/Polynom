#ifndef PolynomQ_h
#define PolynomQ_h
#include "Polynom.h"

/*
2) "Квадратный трехчлен". Инициализация символьной строкой и тройкой чисел. 
Методы:

   * нахождение корней многочлена;
   * разложение многочлена на множители (результат - пара новых многочленов или
     признак того, что исходный многочлен неприводим).
*/

struct pairOfRoots{
	long double first;
	long double second;
};

struct pairOfPolynoms{
	Polynom first;
	Polynom second;
};

struct badcoeffitients{
	badcoeffitients(){
	}
};

struct irreducible{
	irreducible(){
	}
};

class PolynomQ:public Polynom{
public:
	PolynomQ(){};
	PolynomQ(const PolynomQ& p){copy(p);}
//	PolynomQ& operator = (const PolynomQ &);
	PolynomQ(const long double,const long double,const long double);
	pairOfRoots computeRoots();
	pairOfPolynoms factorization();
};
#endif