#ifndef Controlador_difuso_H
#define Controlador_difuso_H
//#include<Arduino.h>
#include"REGLAS_FUZZY.h"

class Controlador_difuso
{
public:
    Controlador_difuso();
    float Controlador(float Medida1, float Medida2, float Medida3=0,float Medida4=0);

private:
    float calculaGE(Etiqueta e, float ej);
    void calcularConsecuente(Etiqueta e, float h,float valores[]);
    int defuzzy(int size, float h[], int etiquetaCod[]);
	REGLAS_FUZZY reglas_difuso;
};

#endif // Controlador_difuso_H
