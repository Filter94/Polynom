#ifndef PolynomQF_h
#define PolynomQF_h
#include "Polynom.h"

/*
3) "Квадратичные формы от переменных x,y,z". Инициализация только
символьной строкой. Методы:

   * форма диагональна или нет;
   * форма невырождена или нет.
*/

class PolynomQF:public Polynom{
public:
	bool isDiagonal();
	bool isSingular();
};
#endif