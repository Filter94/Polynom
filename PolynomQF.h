#ifndef PolynomQF_h
#define PolynomQF_h
#include "Polynom.h"

/*
3) "������������ ����� �� ���������� x,y,z". ������������� ������
���������� �������. ������:

   * ����� ����������� ��� ���;
   * ����� ����������� ��� ���.
*/

class PolynomQF:public Polynom{
public:
	bool isDiagonal();
	bool isSingular();
};
#endif