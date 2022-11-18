///Declaracion de funciones

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void cargarMenu(int xPosTexto, int yPosTexto, int puntaje[]);
void cargarMenu2(int xPosTexto, int yPosTexto, int vDados[],int tam, int vPJ[], int comoNoJug[], int puntaje[], int jugador, char nombre[], bool &choise, int &cont);
void jugadorDeAUno(int puntaje[],char nombre1[]);
void accionesDeCursor(int &key, int puntaje[], int &salida,char nombre1[],char nombre2[]);
void accionesDeCursor2(int &key, int xPosTexto, int yPosTexto, int vDados[],int tam, int vPJ[], int comoNoJug[], int puntaje[], int jugador, char nombre[], bool &choise, int &cont, int &salir);
void mostrarNombre(char unNombre[],int jugador);
void mostrarTexto(const char* text, int posX, int posY);
void pedirNombres(char nombre[]);
int cantidadDeRondas();
void cargarDados(int vDados[], int tam);
void mostrarArray(int vDados[], int posX, int posY);
void comienzo(int vDados[], int tam, int cantRondas, int vPJ[], int comoNoJug[], int puntaje[], char nombre1[], int jugador);
void posibleCombinacion(int vDados[],int tam, int vPJ[]);
int jugadaAlNumero(int vDados[],int eleccion);
void ordenarDeMenorAMayor(int vDados[], int tam);
int escalera(int vDados[], int tam);
int armadoDeJuegos(int vDados[], int tam);
void ponerEnCero(int vDados[], int tam);
void ponerEnUno(int vDados[], int tam );
void hayOnoJugada(int vPJ[], int comoNoJug[], int vDados[], int puntaje[], int jugador);
void elegirJugada(int vPJ[],int comoNoJug[], int vDados[], int puntaje[], int jugador);
void CancelarJugada(int comoNoJug[]);
void tirarDados(int vDados[],int tam);
void volverAtirar(int vDados[],int tam, int vPJ[], int comoNoJug[], int puntaje[], int jugador, char nombre[]);
void cambiarDados(int vDados[]);
void menuElegirJugada(int vPJ[],int comNoJug[]);
void mostrarPuntaje(int puntaje[], int jugador);
void escalera2(int puntaje[], int jugador);
int jugadaAlNumero2(int vDados[], int eleccion, int puntaje[], int jugador);
void full( int puntaje[], int jugador);
void poker( int puntaje[], int jugador);
void generala( int puntaje[], int jugador);
void menuJuegos(int opciones);

//Funciones  jugador dos

void jugadorDeADos(int puntaje[],char nombre1[],char nombre2[]);
void comienzoJuegoDos(int vDados[], int tam, int cantRondas,int vPJ[], int comoNoJug[],int puntaje[], char nombre1[], char nombre2[], int comoNoJug2[]);
void EntreRondas(int contador1,char nombre1[], char nombre2[],int puntaje[]);
void Cargando(int vueltas);
void mostrarNombresyPuntos(char unNombre[],char unNombre2[],int puntaje[]);
void mostrarRonda(int ronda,int posX,int posY);
void mostrarProxTurno(int ronda,int posX,int posY,char unNombre[],char unNombre2[]);
void DibujarLinea(int EmpiezaX,int EmpiezaY,int TerminaX ,int TerminaY,int orientacion,int TopBotom,int tipo);
void DibujarCuadrado(int xE,int yE,int ancho,int largo,int tipo);
void MuestraPuntajes(char nombre1[], char nombre2[],int puntaje[]);
void DibujarDado(int PosX,int PosY,int Numero);
void DibujarPuntos(int Numero,int PosX,int PosY);
void MostrarDados(int vDados[],int posX,int posY);

#endif // FUNCIONES_H_INCLUDED
