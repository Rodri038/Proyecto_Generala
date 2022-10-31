///Prototipos de funciones
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "jugadorUno.h"

void menu();
void pedirNombres(char nombre[]);
void cargarDados(int vDadosAzar[], int tam);
void mostrarDados(int vDadosAzar[], int tam);
void comienzo(char nombre[], int vDados[], int tam);
int jugadaAlNumero(int vDados[]);
void ordenarDeMenorAMayor(int vDados[], int tam);
bool escalera(int vDados[], int tam);
void ponerEnCero(int Array[], int tam);
void PosibleCombinacion(int vDados[],int tam,int vPJ[]);
void ponerEnCero( int vPJ[]);
void hayOnoJugada(int vPJ[]);
void elegirJugada(int vPJ[],int ComNoJug[]);
void CancelarJugada(int ComNoJug[]);
#endif // FUNCIONES_H_INCLUDED
