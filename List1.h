#ifndef List_h
#define List_h

#include <iostream>

using namespace std;

template <typename T> class List{
public:
	List();//crt
	~List();//dsry
	List(const List&);//cpy
	List& operator = (const List&);//=
	bool operator == (const List&)const;
	friend ostream& operator << (ostream&,const List&);
	void addToBegin(const T);
	void add(const T);
	void makeItEmpty();
	void toBegin()const;
	void toNext()const;
	void toEnd()const;
	bool isEmpty()const;
	bool isInEnd()const;
	void erase();
	T& getCurrent();
	T getCurrent() const;
private:	
	struct Lelem{
		Lelem* next_;
		T data_;
	};
	Lelem* tail_;
	Lelem* head_;
	mutable Lelem* temp_;
	void copy(const List&);
};

template <typename T>

List<T>::List(){
	head_ =nullptr;
	temp_ =nullptr;
	tail_ =nullptr;
}

template <typename T>

List<T>::~List(){
	makeItEmpty();
}

template <typename T>

List<T>::List(const List<T>& list){
	copy(list);
}

template <typename T>

List<T>& List<T>::operator = (const List<T>& list){
	if (this!=&list){
		makeItEmpty();
		copy(list);
	}
	return *this;
}

template <typename T>
bool List<T>::operator == (const List& list)const {
	toBegin();
	list.toBegin();
	bool sameStatment=isInEnd()==list.isInEnd();
	bool dataIsEquals=temp_->data_==list.temp_->data_;
	while(sameStatment&&dataIsEquals){
		toNext();
	}
	return (sameStatment&&dataIsEquals);
}

template<typename T>

ostream& operator << (ostream& out,const List<T>& list){
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

void List<T>::addToBegin(const T type){
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
	head_=a;
}

template <typename T>

void List<T>::add(const T type){
	Lelem* a=new Lelem ;
	a->data_=type;
	if(head_){
		if(temp_){
			a->next_=temp_->next_;
			temp_->next_=a;
			if(!a->next_){
				tail_=a;
			}
		}
		else{
			throw std::out_of_range("End of list.");
		}
	}
	else{
		head_=a;
		temp_=a;
		tail_=a;
		temp_->next_=nullptr;
	}
}


template <typename T>

void List<T>::makeItEmpty(){
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

void List<T>::toBegin() const{
	temp_=head_;
}

template <typename T>

void List<T>::toNext()const {
	if(temp_)
		temp_=temp_->next_;
	else
		throw std::out_of_range("End of list.");
}

template <typename T>

void List<T>::toEnd()const{
	temp_=tail_;
}

template <typename T>

bool List<T>::isEmpty()const{
	return !head_;
}

template <typename T>

bool List<T>::isInEnd()const{
	return temp_==tail_;
}
template <typename T>

void List<T>::erase(){//Удаляет элемент temp_, перемещает temp_ за удаленный или temp_==nullptr если temp_ в конце.
	if(temp_){
		Lelem *a,*b;
		b=head_;
		if(head_!=temp_){
		while(b->next_!=temp_){
			b=b->next_;
		}
		}
		else{
			head_=head_->next_;
		}
		a=temp_->next_;
		b->next_=a;
		delete temp_;
		temp_=a;
		if (!a){
			tail_=b;
			temp_=b;
		}
		if(head_->next_==nullptr){
		delete head_;
		tail_=nullptr;
		temp_=nullptr;
		head_=nullptr;
		}
		}
	else{throw std::logic_error("Current element is bad.");
	}
}

template <typename T>

T List<T>::getCurrent()const{
	if (!temp_){throw std::logic_error("Current element is bad.");
	}
	return temp_->data_;
}


template <typename T>

T& List<T>::getCurrent(){
	if (!temp_){throw std::logic_error("Current element is bad.");
	}
	return temp_->data_;
}

template <typename T>

void List<T>::copy(const List<T>& list){
	Lelem* a=list.head_;
	while(a){
		toEnd();
		add(a->data_);
		a=a->next_;
	}
	temp_=head_;
}
#endif 