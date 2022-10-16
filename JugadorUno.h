///Definicion de funciones
#ifndef JUGADORUNO_H_INCLUDED
#define JUGADORUNO_H_INCLUDED
#include "funciones.h"
int vDadosAzar[5];

void pedirNombres(char nombre[]){
    cout<<"Ingrese su nombre para comenzar a jugar: "<<endl;
    //cin.getline(jugador1, 20, '\n');
    cin>>nombre;
    cout<<"Bienvenido "<<nombre<<endl;
}

void azarDeDados(){
    cargarDados(vDadosAzar);
    mostrarDados(vDadosAzar);
}

void cargarDados(int vDadosAzar[]){
    int i;
        for(i = 0; i<=4; i++){
            vDadosAzar[i]= rand() % 6+1;
        }
}

void mostrarDados(int vDadosAzar[]){
    int i;
        for(i = 0; i<=4; i++){
            cout<<" "<<vDadosAzar[i]<<" ";
            }
        cout<<" "<<endl;
        cin.get();
}






#endif // JUGADORUNO_H_INCLUDED
