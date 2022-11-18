#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Funciones.h"
#include "JugadorUno.h"
#include "JugadorDos.h"

void cargarMenu(int xPosTexto, int yPosTexto, int puntaje[]){
    int op = 1, y = 0;
    char jugador1[20] = {};
    char jugador2[20] = {};
    rlutil::hidecursor();

    do{
    mostrarTexto("Jugar de a uno", xPosTexto, yPosTexto);
    mostrarTexto("Jugar de a dos", xPosTexto, yPosTexto+1);
    mostrarTexto("Puntaje", xPosTexto, yPosTexto+2);
    mostrarTexto("Salir", xPosTexto, yPosTexto+3);
    //posicion en la que se dibuja el cursor
    rlutil::locate((xPosTexto - 2),yPosTexto + y);
    std::cout<<(char)175<<std::endl;

    switch(rlutil::getkey()){
    case 14:
        rlutil::locate((xPosTexto - 2),yPosTexto + y);//Arriba
        std::cout<<" "<<std::endl;
        y--;
        if(y <= 0) y = 0;
        break;
    case 15:
        rlutil::locate((xPosTexto - 2),yPosTexto + y);//Abajo
        std::cout<<" "<<std::endl;
        y++;
        if(y >= 3) y = 3;
        break;
    case 1://Enter
        accionesDeCursor(y, puntaje, op, jugador1, jugador2);
        break;
        }
    }while(op != 0);
}

void accionesDeCursor(int &key, int puntaje[], int &salida, char nombre1[], char nombre2[]){
     switch(key){
                    case 0:
                    jugadorDeAUno(puntaje, nombre1);
                    break;
                    case 1:
                    jugadorDeADos(puntaje, nombre1, nombre2);
                    break;
                    case 2:
                    MuestraPuntajes(nombre1,nombre2, puntaje);
                    break;
                    case 3:
                    salida = 0;
                    break;
        }
}
#endif // MENU_H_INCLUDED

