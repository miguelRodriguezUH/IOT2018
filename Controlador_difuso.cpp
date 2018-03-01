#include "Controlador_difuso.h"
Controlador_difuso::Controlador_difuso() {
}
float Controlador_difuso::Controlador(float Medida1, float Medida2, float Medida3, float Medida4) {
  int tamano_reglas;

  tamano_reglas = reglas_difuso.size();

  int cont_hmin = 0;
  int cont_etiquetas = 0;

  float hmin[tamano_reglas];
  int etiquetasCod[tamano_reglas];

  for (int n = 0; n < tamano_reglas; n++) {
    Regla2E r2e;

    r2e = reglas_difuso.getRegla(n);
    char* Nombre = r2e.getConsecuente().getNombre();
    char NombreLocal[10];
    for(int l=0;l<10;l++){
      NombreLocal[l]=Nombre[l];
    }

    float h1 = calculaGE(r2e.getEtiqueta1(), Medida1);
    float h2 = calculaGE(r2e.getEtiqueta2(), Medida2);
    if (h1 != 0 && h2 != 0) {
      //Inicio parte nueva
      int etiquetaNum = -1;
      char charActual;

      int aux = 0;
      char camion[] = "Camion";
      int contCamion = 0;
      bool bCamion = false;
      char coche[] = "Coche";
      int contCoche = 0;
      bool bCoche = false;
      char bicicleta[] = "Bicicleta";
      int contBicicleta = 0;
      bool bBicicleta = false;
      char suelo[] = "Suelo";
      int contSuelo = 0;
      bool bsuelo = false;

      while (!bCamion && !bCoche && !bBicicleta && !bsuelo && aux < 10) {
        if (NombreLocal[aux] == camion[contCamion]) {
          contCamion++;
          if (contCamion == 6) {
            bCamion = true;
            etiquetaNum = 4;
          }
        }
        if (NombreLocal[aux] == coche[contCoche]) {
          contCoche++;
          if (contCoche == 5) {
            bCoche = true;
            etiquetaNum = 3;
          }
        }
        if (NombreLocal[aux] == bicicleta[contBicicleta]) {
          contBicicleta++;
          if (contBicicleta == 9) {
            bBicicleta = true;
            etiquetaNum = 2;
          }
        }
        if (NombreLocal[aux] == suelo[contSuelo]) {
          contSuelo++;
          if (contSuelo == 5) {
            bsuelo = true;
            etiquetaNum = 1;
          }
        }
        aux++;
      }
      if (etiquetaNum != -1) {
        etiquetasCod[cont_etiquetas] = etiquetaNum;
        cont_etiquetas++;
        float minInt = h1 < h2 ? h1 : h2;
        hmin[cont_hmin] = minInt;
        cont_hmin++;
      }
    }
  }
  return defuzzy(cont_hmin, hmin, etiquetasCod);
}

float Controlador_difuso::calculaGE(Etiqueta e, float ej) {
  if ((e.getX0() == e.getX1()) && (ej <= e.getX1()))
    return 1;
  else if ((e.getX2() == e.getX3()) && (ej >= e.getX3()))
    return 1;
  else if ((e.getX1() <= ej) && (ej <= e.getX2()))
    return 1;
  else if ((e.getX0() < ej) && (ej <= e.getX1()))
    return (ej - e.getX0()) / (e.getX1() - e.getX0());
  else if ((e.getX2() < ej) && (ej <= e.getX3()))
    return (ej - e.getX3()) / (e.getX2() - e.getX3());
  else
    return 0;
}
void Controlador_difuso::calcularConsecuente(Etiqueta e, float h, float valores[]) {

  float x4 = e.getX0() + ((e.getX1() - e.getX0()) * h);
  float x5 = e.getX3() - ((e.getX3() - e.getX2()) * h);

  //float valores[2];
  valores[0] = x4;
  valores[1] = x5;

}
int Controlador_difuso::defuzzy(int size, float h[], int etiquetaCod[]) {
  int etiquetaSuelo = 1;
  int etiquetaBicicleta = 2;
  int etiquetaCoche = 3;
  int etiquetaCamion = 4;

  float sumaPonderadaSuelo = 0;
  float sumaPonderadaBicicleta = 0;
  float sumaPonderadaCoche = 0;
  float sumaPonderadaCamion = 0;

  float sumaMax1=0,sumaMax2=0;

  int etiquetaMax1=0,etiquetaMax2=0;

  for (int k = 0; k < size; k++) {
    if (etiquetaCod[k] == etiquetaSuelo) {
      sumaPonderadaSuelo = sumaPonderadaSuelo + h[k];
    } else if (etiquetaCod[k] == etiquetaBicicleta) {
      sumaPonderadaBicicleta = sumaPonderadaBicicleta + h[k];
    } else if (etiquetaCod[k] == etiquetaCoche) {
      sumaPonderadaCoche = sumaPonderadaCoche + h[k];
    } else if (etiquetaCod[k] == etiquetaCamion) {
      sumaPonderadaCamion = sumaPonderadaCamion + h[k];
    }
  }
  
  if(sumaPonderadaSuelo>=sumaPonderadaBicicleta){
    etiquetaMax1=etiquetaSuelo;
    sumaMax1=sumaPonderadaSuelo;
  }else{
    etiquetaMax1=etiquetaBicicleta;
    sumaMax1=sumaPonderadaBicicleta;
  }

  if(sumaPonderadaCoche>=sumaPonderadaCamion){
    etiquetaMax2=etiquetaCoche;
    sumaMax2=sumaPonderadaCoche;
  }else{
    etiquetaMax2=etiquetaCamion;
    sumaMax2=sumaPonderadaCamion;
  }

  if(sumaMax1>=sumaMax2){
    etiquetaMax1=etiquetaMax1;
  }else{
    etiquetaMax1=etiquetaMax2;
  }
  return etiquetaMax1;
}
