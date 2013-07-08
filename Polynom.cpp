#ifndef Polynom_
#define Polynom_
#include "EnterPolynom.h"
#include <string>

Polynom& Polynom::operator = (const Polynom& p){
	if (list_!=p.list_){
		makeItEmpty();
		copy(p);
	}
	return *this;
}

bool operator == (const monom& m1,const monom& m2){
	return (m1.x==m2.x)&&(m1.y==m2.y)&&(m1.z==m2.z)&&(m1.constant==m2.constant);
}

bool Polynom::operator == (const Polynom& p)const {
	return p.list_==list_;
}

bool Polynom::operator != (const Polynom& p)const {
	return p.list_!=list_;
}

ostream&  operator << (ostream& out,const Polynom& p){
	monom mh;
	if(!p.list_.isEmpty()){
		p.list_.toBegin();
		while(!p.list_.isAfterEnd()){
			mh=p.list_.getCurrent();
			if(mh.constant){
				if(!p.list_.isInBegin()&&(p.list_.getCurrent().constant>0))
					out<<'+';
				if((mh.constant!=1||(!mh.x&&!mh.y&&!mh.z)))
					out<<mh.constant;
				if(mh.x){
					out<<'x';
					if(mh.x!=1)
						out<<'^'<<mh.x;
				}
				if(mh.y){
					out<<"y";
					if(mh.y!=1)
						out<<'^'<<mh.y;
				}
				if(mh.z){
					out<<"z";
					if(mh.z!=1)
						out<<'^'<<mh.z;
				}
			}
			p.list_.toNext();
		}	
	}
	else{
		throw isEmpty();
	}
	p.list_.toEnd();
	return out;
}

void operator >> (istream& in,Polynom& p){
	yylex(p);
}

void Polynom::add(const monom m){
	if(m.constant){
		if(isEmpty()){
			list_.addToBegin(m);
			return;
		}
		monom mh;
		string m2="\0";
		string m1="\0";
		int o=0;
		list_.toBegin();
		mh=list_.getCurrent();
		m1=to_string(m.x)+to_string(m.y)+to_string(m.z);//"xyz" моном полинома p
		while(!list_.isAfterEnd()){
			mh=list_.getCurrent();
			m2=to_string(mh.x)+to_string(mh.y)+to_string(mh.z);//"xyz" моном полинома this
			o=m1.compare(m2);
			if(o>0){
				if(!list_.isInBegin()){
					list_.toPrevious();
					list_.add(m);
				}
				else{
					list_.addToBegin(m);
				}
				return;
			}
			else
				if(!o){
					list_.getCurrent().constant+=m.constant;
					if(!list_.getCurrent().constant){
						list_.erase();
					}
					return;
				}
				try{
					list_.toNext();
				}
				catch(...){
				}
		}
		list_.toEnd();
		list_.add(m);
	}
}

void Polynom::makeItEmpty(){
	list_.makeItEmpty();
}

void Polynom::erase(int i){
	list_.toBegin();
	for(int j=0;j<i;j++){
		list_.toNext();
	}
	list_.erase();
}

bool Polynom::isEmpty()const{
	return list_.isEmpty();
}

int Polynom::getDegree(char c)const{
	int i=0;
	if(!isEmpty()){
		list_.toBegin();
		switch(c){
		case 'x':{
			while(!list_.isAfterEnd()){
				if(list_.getCurrent().x>i){
					i=list_.getCurrent().x;
				}
				list_.toNext();
			}
			break;
				 }
		case 'y':{
			while(!list_.isAfterEnd()){
				if(list_.getCurrent().y>i){
					i=list_.getCurrent().y;
				}
				list_.toNext();
			}
			break;
				 }
		case 'z':{
			while(!list_.isAfterEnd()){
				if(list_.getCurrent().z>i){
					i=list_.getCurrent().z;
				}
				list_.toNext();
			}
			break;
				 }
		default:{
			return -1;
				}
		}
	}
	else{
		return -1;
	}
	list_.toEnd();
	return i;
}

long double Polynom::getValueOn(const long double xvalue,const long double yvalue,const long double zvalue)const{
	long double result=0;
	long double monomvalue=1;
	if(!list_.isEmpty()){
		list_.toBegin();
		while(!list_.isAfterEnd()){
			monomvalue=1;
			if(list_.getCurrent().constant){
				for(int i=0;i<list_.getCurrent().x;i++){
					monomvalue*=xvalue;
				}
				for(int i=0;i<list_.getCurrent().y;i++){
					monomvalue*=yvalue;
				}
				for(int i=0;i<list_.getCurrent().z;i++){
					monomvalue*=zvalue;
				}
				monomvalue*=list_.getCurrent().constant;
				result+=monomvalue;
			}
			list_.toNext();
		}
		list_.toEnd();
	}
	return result;
}
#endif