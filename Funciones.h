///Declaracion de funciones
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "jugadorUno.h"

void menu();
void mostrarNombre(char unNombre[]);
int moverCursor(int posX, int posY, int cursor, int caracter);
void posicionDeCursor(int posX, int posY, int &posCursor, int tecla);
void accionesCursor(int posCursor, int tecla, bool &salida, int tam, int vDados[], int vPJ[], int comoNoJug[], int puntaje[], int &jugador, int &nroTiradas, char nombre1[]);
void mostrarTexto(const char* text, int posX, int posY);
void pedirNombres(char nombre1[]);
int cantidadDeRondas();
void cargarDados(int vDados[], int tam);
void mostrarArray(int vDados[], int posX, int posY);
void comienzo(int vDados[], int tam, int cantRondas, int vPJ[], int comoNoJug[], int puntaje[], int &jugador, int &nroTiradas, bool &salida, char nombre1[]);
void posibleCombinacion(int vDados[],int tam, int vPJ[], int puntaje[], int &jugador);
int jugadaAlNumero(int vDados[],int eleccion);
void ordenarDeMenorAMayor(int vDados[], int tam);
int escalera(int vDados[], int tam);
int armadoDeJuegos(int vDados[], int tam);
void ponerEnCero(int vDados[], int tam);
void ponerEnUno(int vDados[], int tam );
void hayOnoJugada(int vPJ[], int comoNoJug[], int vDados[], int puntaje[], int &jugador, int &nroTiradas, bool &salida);
void elegirJugada(int vPJ[],int comoNoJug[], int vDados[], int puntaje[], int &jugador, int &nroTiradas, bool &salida);
void CancelarJugada(int comoNoJug[]);
void tirarDados(int vDados[],int tam);
void volverAtirar(int vDados[],int tam, int vPJ[], int comoNoJug[], int puntaje[], int &jugador, int &nroTiradas, bool &salida, char nombre1[]);
void cambiarDados(int vDados[]);
void menuElegirJugada(int vPJ[],int comNoJug[]);
void mostrarPuntaje(int puntaje[], int &jugador);
int escalera2(int puntaje[], int &jugador);
int jugadaAlNumero2(int vDados[], int eleccion, int puntaje[], int &jugador);
void full( int puntaje[], int &jugador);
void poker( int puntaje[], int &jugador);
void generala( int puntaje[], int &jugador);
#endif // FUNCIONES_H_INCLUDED
