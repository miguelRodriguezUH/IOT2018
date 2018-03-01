#ifndef REGLAS_FUZZY_H
#define REGLAS_FUZZY_H
//#include<Arduino.h>
#include"Regla2E.h"

class REGLAS_FUZZY
{
    public:
		REGLAS_FUZZY();
		int size();
		Regla2E getRegla(int pos);

    private:
		Regla2E Reglas[16]; //4 reglas
};

#endif // REGLAS
