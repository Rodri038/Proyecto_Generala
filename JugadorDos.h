#ifndef JUGADORDOS_H_INCLUDED
#define JUGADORDOS_H_INCLUDED
#include "Funciones.h"
#include "JugadorUno.h"

void comienzoJuegoDos(int vDados[], int tam, int cantRondas,int vPJ[], int comoNoJug[],int puntaje[], int &nroTiradas, bool &salida, char nombre1[], char nombre2[], int tecla, int comoNoJug2[]){
    int contador=1;
    mostrarTexto("Nombre jugador UNO", 52, 9);
    pedirNombres(nombre1);
    rlutil::cls();
    mostrarTexto("Nombre jugador DOS", 52, 9);
    pedirNombres(nombre2);
    rlutil::cls();
    ponerEnUno(comoNoJug, 10);
    ponerEnUno(comoNoJug2, 10);
    ponerEnCero(puntaje, 2);

do{
    mostrarNombre(nombre1);
    mostrarPuntaje(puntaje, 0);
    volverAtirar(vDados, tam, vPJ, comoNoJug, puntaje, 0, nroTiradas, salida, nombre1, tecla);
    cout<<"Ronda numero : "<<contador<<endl;
    getch();
    rlutil::cls();
    contador++;
    mostrarNombre(nombre2);
    mostrarPuntaje(puntaje, 1);
    volverAtirar(vDados, tam, vPJ, comoNoJug2, puntaje, 1, nroTiradas, salida, nombre2, tecla);
    cout<<"Ronda numero : "<<contador<<endl;
    getch();
    rlutil::cls();
    contador++;
    }while(contador <= cantRondas);
}

#endif // JUGADORDOS_H_INCLUDED
