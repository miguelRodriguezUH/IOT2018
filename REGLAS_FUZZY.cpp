#include "REGLAS_FUZZY.h"
REGLAS_FUZZY::REGLAS_FUZZY(){

	//Etiquetas Ultrasonido
	//Rango de medida us de 0 a 500 cm 
	//Esto es lo que hay que ajustar una vez filtrado los valores 
	Etiqueta MuyCerca_us =  Etiqueta("MuyCerca", 0,0,15,20);
	Etiqueta Cerca_us =  Etiqueta("Cerca",15,20,30,35);
	Etiqueta Medio_us =  Etiqueta("Medio",30,35,40,46);
	Etiqueta Lejos_us =  Etiqueta("Lejos",40,46,500,500);
	
	//Etiquetas LDR o fotoresistor
	//Rango de medida us de 0 a 1024 
	//Esto es lo que hay que ajustar una vez filtrado los valores 
	/*Etiqueta MuyPoco_ldr =  Etiqueta("MuyPoco", 0,0,90,110);
	Etiqueta Poco_ldr =  Etiqueta("Poco",90,110,560,600);
	Etiqueta Medio_ldr =  Etiqueta("Medio",560,600,870,900);
	Etiqueta Mucho_ldr =  Etiqueta("Mucho",870,900,1024,1024);*/

    Etiqueta MuyPoco_ldr =  Etiqueta("MuyPoco", 0,0,150,225);
  Etiqueta Poco_ldr =  Etiqueta("Poco",150,225,300,700);
  Etiqueta Medio_ldr =  Etiqueta("Medio",300,700,800,900);
  Etiqueta Mucho_ldr =  Etiqueta("Mucho",800,900,1024,1024);

	//SALIDA
	Etiqueta Suelo =  Etiqueta("Suelo",0,0,0.142,0.284);
	Etiqueta Bicicleta =  Etiqueta("Bicicleta",0.142,0.284,0.426,0.568);
	Etiqueta Coche =  Etiqueta("Coche",0.426,0.568,0.71,0.852);
	Etiqueta Camion =  Etiqueta("Camion",0.71,0.852,1,1);


	//{Ultrasonido,LDR,SALIDA}
	Reglas[0] =  Regla2E(MuyCerca_us,MuyPoco_ldr,Camion);
	Reglas[1] =  Regla2E(MuyCerca_us,Poco_ldr,Camion);
	Reglas[2] =  Regla2E(MuyCerca_us,Medio_ldr,Coche);
	Reglas[3] =  Regla2E(MuyCerca_us,Mucho_ldr,Suelo);
	
	Reglas[4] =  Regla2E(Cerca_us,MuyPoco_ldr,Coche);
	Reglas[5] =  Regla2E(Cerca_us,Poco_ldr,Coche);
	Reglas[6] =  Regla2E(Cerca_us,Medio_ldr,Coche);
	Reglas[7] =  Regla2E(Cerca_us,Mucho_ldr,Bicicleta);
	
	Reglas[8] =  Regla2E(Medio_us,MuyPoco_ldr,Coche);
	Reglas[9] =  Regla2E(Medio_us,Poco_ldr,Coche);
	Reglas[10] =  Regla2E(Medio_us,Medio_ldr,Bicicleta);
	Reglas[11] =  Regla2E(Medio_us,Mucho_ldr,Suelo);

	Reglas[12] =  Regla2E(Lejos_us,MuyPoco_ldr,Suelo);
	Reglas[13] =  Regla2E(Lejos_us,Poco_ldr,Suelo);
	Reglas[14] =  Regla2E(Lejos_us,Medio_ldr,Suelo);
	Reglas[15] =  Regla2E(Lejos_us,Mucho_ldr,Suelo);
}

int REGLAS_FUZZY::size(){
	return 16;/*16 reglas posee*/
}

Regla2E REGLAS_FUZZY::getRegla(int pos){
   if(pos<size())
    {
        return Reglas[pos];
    }
    else return Regla2E();

}
