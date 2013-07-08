#ifndef PolynomX_
#define PolynomX_
#include "PolynomX.h"

/*
PolynomX& PolynomX::operator = (const PolynomX& p){
	if (list_!=p.list_){
		makeItEmpty();
		copy(p);
	}
	return *this;
}
*/

PolynomX PolynomX::getDerivative()const{
	PolynomX p;
	monom mh;
	mh.x=0;
	mh.y=0;
	mh.z=0;
	mh.constant=0;
	if(!isEmpty()){
		list_.toBegin();
		while(!list_.isAfterEnd()){
			mh.constant=list_.getCurrent().x*list_.getCurrent().constant;
			mh.x=list_.getCurrent().x;
			if(mh.x)
				mh.x--;
			if(mh.constant)
			p.add(mh);
			list_.toNext();
		}
		list_.toEnd();
		return p;
	}
	else
		throw std::logic_error("There's no monoms.");
}	
#endif