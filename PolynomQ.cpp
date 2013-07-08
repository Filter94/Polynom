#ifndef PolynomQ_
#define PolynomQ_
#include "PolynomQ.h"

/*PolynomQ& PolynomQ::operator = (const PolynomQ& p){
	if (list_!=p.list_){
		makeItEmpty();
		copy(p);
	}
	return *this;
}
*/

PolynomQ::PolynomQ(const long double a,const long double b,const long double c){
	monom m;
	m.x=2;
	m.y=0;
	m.z=0;
	m.constant=a;
	add(m);
	m.x--;
	m.constant=b;
	add(m);
	m.x--;
	m.constant=c;
	add(m);
}

pairOfRoots PolynomQ::computeRoots(){
	pairOfRoots p;
	int O;
	long double C;
	list_.toBegin();
	long double a=0,b=0,c=0;
	while(!list_.isAfterEnd()){
		O=list_.getCurrent().x;
		C=list_.getCurrent().constant;
		switch(O){
		case 0:{
			c=C;
			break;
			   }
		case 1:{
			b=C;
			break;
			   }
		case 2:{
			a=C;
			break;
			   }
		}
		list_.toNext();
	}
	long double D;
	D=b*b-4*a*c;
	if(a&&D>=0){
		p.first=(-b-sqrt(D))/(2*a);
		p.second=(-b+sqrt(D))/(2*a);
	}
	else{
		if(a){
			throw badcoeffitients();
		}
		else{
			p.first=-c/b;
			p.second=p.first;
		}
	}
	return p;
}

pairOfPolynoms PolynomQ::factorization(){
	pairOfRoots p;
	pairOfPolynoms P;
	long double a=1;
	try{
	p=computeRoots();
	Polynom First,Second;
	monom m;
	m.x=1;
	m.y=0;
	m.z=0;
	m.constant=1;
	P.first.add(m);
	if(p.first!=p.second){
	list_.toBegin();
	if(list_.getCurrent().x==2){
	a=list_.getCurrent().constant;
	}
	m.constant=a;
	}
	else{
		m.constant=0;
	}
	P.second.add(m);
	m.x=0;
	m.constant=-p.first;
	P.first.add(m);
	if(p.first!=p.second){
	m.constant=-p.second*a;
	}
	else{
		m.constant=1;
	}
	P.second.add(m);
	}
	catch (badcoeffitients){
		throw irreducible();
	}
	return P;
}
#endif