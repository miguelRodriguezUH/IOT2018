#ifndef Etiqueta_H
#define Etiqueta_H

class Etiqueta
{
    public:
      Etiqueta();
	  Etiqueta(char* Nombre_, float x0_, float x1_, float x2_, float x3_);
	 // Etiqueta& operator= (const Etiqueta& et);
	  char* getNombre();
	  float getX0();
	  float getX1();
	  float getX2();
	  float getX3();

    private:
	   char Nombre[10];
	   float x0;
	   float x1;
	   float x2;
	   float x3;

};

#endif // Etiqueta
