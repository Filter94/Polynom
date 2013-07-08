#ifndef List2_h
#define List2_h

#include <iostream>

using namespace std;

template <typename T> class List2{
public:
	List2();//crt
	~List2();//dsry
	List2(const List2&);//cpy
	List2& operator = (const List2&);//=
	bool operator == (const List2&)const;
	bool operator != (const List2&)const;
	friend ostream& operator << (ostream&,const List2&);
	void addToBegin(const T);
	void add(const T);
	void makeItEmpty();
	void toBegin()const;
	void toNext()const;
	void toPrevious()const;
	void toEnd()const;
	bool isEmpty()const;
	bool isInEnd()const;
	bool isAfterEnd()const;
	bool isInBegin()const;
	void erase();
	T& getCurrent();
	T getCurrent() const;
private:	
	struct Lelem{
		Lelem* previous_;
		Lelem* next_;
		T data_;
	};
	Lelem* tail_;
	Lelem* head_;
	mutable Lelem* temp_;
	void copy(const List2&);
};

template <typename T>

List2<T>::List2(){
	head_ =nullptr;
	temp_ =nullptr;
	tail_ =nullptr;
}

template <typename T>

List2<T>::~List2(){
	makeItEmpty();
}

template <typename T>

List2<T>::List2(const List2<T>& list){
	copy(list);
}


template <typename T>

bool List2<T>::operator == (const List2& list)const {
	if(!isEmpty()){
		toBegin();
		list.toBegin();
		bool sameStatment=isInEnd()==list.isInEnd();
		bool dataIsEquals=temp_->data_==list.temp_->data_;
		while(sameStatment&&dataIsEquals&&!isInEnd()){
			sameStatment=isInEnd()==list.isInEnd();
			dataIsEquals=temp_->data_==list.temp_->data_;
			toNext();
		}
		return (sameStatment&&dataIsEquals);
	}
	else{
		return list.isEmpty();
	}
}

template <typename T>

bool List2<T>::operator != (const List2& list)const {
	if(!isEmpty()){
		toBegin();
		list.toBegin();
		bool sameStatment=isInEnd()==list.isInEnd();
		bool dataIsEquals=temp_->data_==list.temp_->data_;
		while(sameStatment&&dataIsEquals&&!isInEnd()){
			sameStatment=isInEnd()==list.isInEnd();
			dataIsEquals=temp_->data_==list.temp_->data_;
			toNext();
		}
		return !(sameStatment&&dataIsEquals);
	}
	else{
		return !list.isEmpty();
	}
}

template <typename T>

List2<T>& List2<T>::operator = (const List2<T>& list){
	if (this!=&list){
		makeItEmpty();
		copy(list);
	}
	return *this;
}

template<typename T>

ostream& operator << (ostream& out,const List2<T>& list){
	if(!list.isempty())
	{
		list.tobegin();
		out<<list.getCurrent();
		while(!list.inEnd())
		{
			list.toNext();
			out<<' '<<list.getCurrent();
		}
	}
	return out;
}

template <typename T>

void List2<T>::addToBegin(const T type){
	Lelem* a=new Lelem ;
	a->data_=type;
	if(!head_){
		temp_=a;
		tail_=a;
		a->next_=0;
	}
	else{
		a->next_=head_;
	}
	a->previous_=0;
	head_=a;
}

template <typename T>

void List2<T>::add(const T type){
	Lelem* a=new Lelem ;
	a->data_=type;
	if(head_){
		if(temp_){
			a->previous_=temp_;
			a->next_=temp_->next_;
			temp_->next_=a;
			a->previous_=temp_;
			if(!a->next_){
				tail_=a;
			}
		}
		else{
			throw std::out_of_range("List is no more");
		}
	}
	else{
		head_=a;
		temp_=a;
		tail_=a;
		temp_->next_=nullptr;
		temp_->previous_=nullptr;
	}
}


template <typename T>

void List2<T>::makeItEmpty(){
	temp_=head_;
	Lelem* a;
	while (temp_){
		a=temp_->next_;
		delete temp_;
		temp_=a;
	}
	head_=nullptr;
	tail_=nullptr;
}

template <typename T>

void List2<T>::toBegin() const{
	temp_=head_;
}

template <typename T>

void List2<T>::toNext()const {
	if(temp_)
		temp_=temp_->next_;
	else
		throw std::out_of_range("Out of range.");
}

template <typename T>

void List2<T>::toPrevious()const{
	if(temp_)
		temp_=temp_->previous_;
	else
		throw std::out_of_range("Out of range.");
}

template <typename T>

void List2<T>::toEnd()const{
	temp_=tail_;
}

template <typename T>

bool List2<T>::isEmpty()const{
	return !head_;
}

template <typename T>

bool List2<T>::isAfterEnd()const{
	return !temp_;
}

template <typename T>

bool List2<T>::isInEnd()const{
	return temp_==tail_;
}

template <typename T>

bool List2<T>::isInBegin()const{
	return temp_==head_;
}

template <typename T>

void List2<T>::erase(){//Удаляет элемент temp_, перемещает temp_ за удаленный или temp_==nullptr если temp_ в конце.
	if(temp_){
		Lelem *a,*b;
		b=temp_->previous_;
		a=temp_->next_;
		if(isInBegin()){
			head_=a;
		}
		if(isInEnd()){
			tail_=b;
		}
		delete temp_;
		if(b){
			b->next_=a;
		}
		if(a){
			a->previous_=b;
		}
		else{
			temp_=b;
		}
	}
	else{throw std::logic_error("Current element is bad.");
	}
}

template <typename T>

T List2<T>::getCurrent()const{
	if (!temp_){throw std::logic_error("Current element is bad.");
	}
	return temp_->data_;
}


template <typename T>

T& List2<T>::getCurrent(){
	if (!temp_){throw std::logic_error("Current element is bad.");
	}
	return temp_->data_;
}

template <typename T>

void List2<T>::copy(const List2<T>& list){
	if(!list.isEmpty()){
		list.toBegin();
		add(list.getCurrent());
		toEnd();
		while(!list.isInEnd()){
			list.toNext();
			add(list.getCurrent());
			toEnd();
		}
		temp_=head_;
	}
}
#endif 