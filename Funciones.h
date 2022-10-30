///Prototipos de funciones
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "jugadorUno.h"

void menu();
void posicionDeCursor(int posX, int posY, int &posCursor, int tecla);
void accionesCursor(int posCursor, int tecla, bool &salida);
void mostrarTexto(const char* text, int posX, int posY);
void pedirNombres(char nombre[]);
int cantidadDeRondas();
void cargarDados(int vDadosAzar[], int tam);
void mostrarArray(int vDados, int posX, int posY);
void comienzo(char nombre[], int vDados[], int tam, int cantRondas);
int jugadaAlNumero(int vDados[]);
void ordenarDeMenorAMayor(int vDados[], int tam);
int escalera(int vDados[], int tam);
int armadoDeJuegos(int vDados[], int tam);
void ponerEnCero(int Array[], int tam);



#endif // FUNCIONES_H_INCLUDED
