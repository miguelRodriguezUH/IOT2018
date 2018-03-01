#ifndef Regla2E_H
#define Regla2E_H
//#include<Arduino.h>
#include"Etiqueta.h"

class Regla2E
{
    public:
		Regla2E();
		Regla2E( Etiqueta &etiq1_, Etiqueta &etiq2_, Etiqueta &consecuente_);
		Etiqueta getEtiqueta1();
		Etiqueta getEtiqueta2();
		Etiqueta getConsecuente();

    private:
		Etiqueta etiq1;       //Etiqueta1 Ejempolo EJE X
		Etiqueta etiq2;       //Etiqueta2 Ejempolo Eje Y
		Etiqueta consecuente; //RESULTADO
};

#endif // Regla2E_H
