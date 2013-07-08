#ifndef Polynom_h
#define Polynom_h
#include "List2.h"

/*����������� ����� "��������� �� ���������� x,y,z � �������������
��������������" � ��������:

   * ���������� �������� ���������� �� �������� ������;
   * ���������� ������� ���������� �� ������ ����������;
   * ������������� ���������� �� ������.

������ ���������������� ���������� �������, �� ���������� ������.
*/

using namespace std;

struct monom{
	int x,y,z;
	long double constant;
};

struct isEmpty{
	isEmpty(){}
};

class Polynom{
protected:
	List2<monom> list_;
	void copy(const Polynom& p){list_=p.list_;}
public:
	Polynom(){}
	Polynom(const Polynom& p){copy(p);}
	~Polynom(){}
	Polynom& operator = (const Polynom&);
	bool operator == (const Polynom&)const;
	bool operator != (const Polynom&)const;
	friend ostream& operator << (ostream&,const Polynom&);
	friend void operator >> (istream&, Polynom&);
	void add(const monom);
	void makeItEmpty();
	void erase(int i);
	bool isEmpty()const;
	int getDegree(char)const;
	long double getValueOn(const long double x,const long double y,const long double z)const;
};
#endif