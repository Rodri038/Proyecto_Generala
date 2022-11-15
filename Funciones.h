///Declaracion de funciones

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void menu();
void mostrarNombre(char unNombre[]);
void moverCursor(int posX, int posY, int cursor, int caracter);
void posicionDeCursor(int posX, int posY, int &posCursor, int tecla, int maxAbajo);
void accionesCursor(int posCursor, int tecla, bool &salida, int tam, int vDados[], int vPJ[], int comoNoJug[], int puntaje[], int jugador, int &nroTiradas, char nombre1[]);
void mostrarTexto(const char* text, int posX, int posY);
void pedirNombres(char nombre[]);
int cantidadDeRondas();
void cargarDados(int vDados[], int tam);
void mostrarArray(int vDados[], int posX, int posY);
void comienzo(int vDados[], int tam, int cantRondas, int vPJ[], int comoNoJug[], int puntaje[], int &nroTiradas, bool &salida, char nombre1[], int tecla, int jugador);
void posibleCombinacion(int vDados[],int tam, int vPJ[]);
int jugadaAlNumero(int vDados[],int eleccion);
void ordenarDeMenorAMayor(int vDados[], int tam);
int escalera(int vDados[], int tam);
int armadoDeJuegos(int vDados[], int tam);
void ponerEnCero(int vDados[], int tam);
void ponerEnUno(int vDados[], int tam );
void hayOnoJugada(int vPJ[], int comoNoJug[], int vDados[], int puntaje[], int jugador, int &nroTiradas, bool &salida);
void elegirJugada(int vPJ[],int comoNoJug[], int vDados[], int puntaje[], int jugador, int &nroTiradas, bool &salida);
void CancelarJugada(int comoNoJug[]);
void tirarDados(int vDados[],int tam);
void volverAtirar(int vDados[],int tam, int vPJ[], int comoNoJug[], int puntaje[], int jugador,  int &nroTiradas, bool &salida, char nombre[], int tecla);
void cambiarDados(int vDados[]);
void menuElegirJugada(int vPJ[],int comNoJug[]);
void mostrarPuntaje(int puntaje[], int jugador);
void escalera2(int puntaje[], int jugador);
int jugadaAlNumero2(int vDados[], int eleccion, int puntaje[], int jugador);
void full( int puntaje[], int jugador);
void poker( int puntaje[], int jugador);
void generala( int puntaje[], int jugador, int &nroTiradas, bool &salida);
void menuJuegos(int opciones);

//Funciones  jugador dos

void comienzoJuegoDos(int vDados[],int tam, int cantRondas, int vPJ[], int comoNoJug[],int puntaje[],int &nroTiradas, bool &salida, char nombre1[], char nombre2[], int tecla, int comNoJug2[]);


#endif // FUNCIONES_H_INCLUDED
