#ifndef PolynomX_h
#define PolynomX_h
#include "Polynom.h"

/*
1) "��������� �� ���������� x".  ����� �����:

   * ���������� ����������� ���������� (��������� - ����� ���������).
*/

class PolynomX:public Polynom{
	public:
			PolynomX(){};
			PolynomX(const PolynomX& p){Polynom::copy(p);}
			//PolynomX& operator = (const PolynomX &);
			PolynomX getDerivative()const;
};
#endif