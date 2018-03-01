#include "Etiqueta.h"
Etiqueta::Etiqueta(){
}
Etiqueta::Etiqueta(char* Nombre_, float x0_, float x1_, float x2_, float x3_){
        for(int i=0;i<10;i++){
            Nombre[i]=Nombre_[i];
        }
        x0 = x0_;
        x1 = x1_;
        x2 = x2_;
        x3 = x3_;
}
char* Etiqueta::getNombre(){
	return Nombre;
}
float Etiqueta::getX0(){
	 return x0;
}
float Etiqueta::getX1(){
	 return x1;
}
float Etiqueta::getX2(){
	 return x2;
}
float Etiqueta::getX3(){
	 return x3;
}
