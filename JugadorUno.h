///Definicion de funciones
#ifndef JUGADORUNO_H_INCLUDED
#define JUGADORUNO_H_INCLUDED
#include "funciones.h"

char nombre[20];

//Funcion poner en cero array
void ponerEnCero(int Array[], int tam){
    int i;
   for(i=0; i<=tam-1; i++){
    Array[i] = 0;
   }
}

void pedirNombres(char nombre[]){
    cout<<"Ingrese su nombre para comenzar a jugar: "<<endl;
    //cin.getline(jugador1, 20, '\n');
    cin>>nombre;
}

//da comienzo a la partida
void comienzo(char nombre[], int vDados[], int tam){
    int tiradas=1;
    bool juegoEscalera;
    ponerEnCero(vDados, 5);
    cout<<"             Bienvenido  "<<nombre<<" a mi juego de generala, jugamos?               "<<endl;
    while(tiradas<=3){
        cargarDados(vDados, 5);
        mostrarDados(vDados, 5);
        //detectar que tipo de juegos se armaron
        ordenarDeMenorAMayor(vDados, 5);
        juegoEscalera = escalera(vDados, 5);
        juegoEscalera ? cout<<"Armaste Escalera" : cout<<"No armaste escalera";
        tiradas++;
    }
    tiradas=1;
}

//carga los numeros del array y genera un numero aleatorio por cada posicion
void cargarDados(int vDados[], int tam){
    int i;
        for(i = 0; i<=tam-1; i++){
            vDados[i]= rand() % 6+1;
        }
}

//muestra los numeros del array
void mostrarDados(int vDados[], int tam){
    int i;
        for(i = 0; i<=tam-1; i++){
            cout<<" "<<vDados[i]<<" ";
            }
        cout<<" "<<endl;
        cin.get();
}


///Combinaciones de juegos:


//funcion para jugar al numero, recibe un vector, y retorna los puntos de acuerdo a la eleccion del numero
int jugadaAlNumero(int vDados[]){
    int eleccion, i, cant=0, puntos;
    cout<<"Elejiste la opcion numero, a que numero jugas tus puntos?: ";
    cin>>eleccion;
        for(i =0; i<=4;i++){
            if(eleccion == vDados[i]) cant++;
        }
        eleccion == 1 ? puntos=cant : puntos = eleccion*cant;
        return puntos;
}

//funcion ordenar numeros
void ordenarDeMenorAMayor(int vDados[], int tam){
    int i,z,aux=0;
        for(i = 0; i <=tam-1; i++){
            for(z = 0; z <=tam-1; z++){
                if(vDados[i]<vDados[z]){
                    aux=vDados[i];
                    vDados[i]=vDados[z];
                    vDados[z]= aux;
                }
            }
        }
}

//funcion para  detectar el juego escalera
bool escalera(int vDados[], int tam){
    int i, valor;
    bool juego=true;
        valor=vDados[0];
        for(i = 1; i <=tam-1;i++){
            vDados[i]>valor ? valor=vDados[i] : juego=false;
        }
        return juego;
}





#endif // JUGADORUNO_H_INCLUDED
