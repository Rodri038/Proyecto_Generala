///Prototipos de funciones
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "jugadorUno.h"

void menu();
void posicionDeCursor(int posX, int posY, int &posCursor, int tecla);
void accionesCursor(int posCursor, int tecla, bool &salida, int tam,int vDados[], int vPJ[], int comoNoJug[]);
void mostrarTexto(const char* text, int posX, int posY);
void pedirNombres(char nombre[]);
int cantidadDeRondas();
void cargarDados(int vDadosAzar[], int tam);
void mostrarArray(int vDados[], int posX, int posY);
void comienzo(int vDados[], int tam, int cantRondas,int vPJ[], int comoNoJug[]);
int jugadaAlNumero(int vDados[],int eleccion );
void ordenarDeMenorAMayor(int vDados[], int tam);
int escalera(int vDados[], int tam);
int armadoDeJuegos(int vDados[], int tam);
void ponerEnCero(int Array[], int tam);
void PosibleCombinacion(int vDados[],int tam,int vPJ[]);
void hayOnoJugada(int vPJ[], int comoNoJug[], int vDados[]);
void elegirJugada( int vDados[], int vPJ[],int ComNoJug[]);
void menuElegirJugada(int vPJ[]);
void CancelarJugada(int ComNoJug[]);
void tirarDados(int vDados[],int tam);
void volverAtirar(int vDados[],int tam,int vPJ[], int comoNoJug[]);
void cambiarDados(int vDados[]);
void mostrarJugadasPosibles(int vPJ[]);

#endif // FUNCIONES_H_INCLUDED
