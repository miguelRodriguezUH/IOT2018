#include "Regla2E.h"
Regla2E::Regla2E(){

}
Regla2E::Regla2E(Etiqueta &etiq1_, Etiqueta &etiq2_,Etiqueta &consecuente_){
	etiq1 = etiq1_;
    etiq2 = etiq2_;
    consecuente = consecuente_;
}
Etiqueta Regla2E::getEtiqueta1(){
	return etiq1;
}
Etiqueta Regla2E::getEtiqueta2(){
	return etiq2;
}
Etiqueta Regla2E::getConsecuente(){
	return consecuente;
}
