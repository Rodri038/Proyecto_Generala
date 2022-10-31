///TP-Generala
//Alumnos: Rodrigo Burns
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "rlutil.h"

using namespace std;

#include "jugadorUno.h"
#include "funciones.h"
#include "Menu.h"

int main(){;

menu();

<<<<<<< HEAD
return 0;
}
void menu(){
        bool exit=true;
        int opcion, puntaje=0, vDadosAzar[5];
        char jugador1[20], jugador2[20];
        //ignacio
        int vPJ[10],ComNoJug[10];

        while(exit){
                cout<<"---Elija una opcion---"<<endl;
                cout<<"---Jugar de a UNO---[1]"<<endl;
                cout<<"---Jugar de a DOS---[2]"<<endl;
                cout<<"---Puntaje---[3]"<<endl;
                cout<<"---Salir del juego---[4]"<<endl;
                cin>>opcion;
                switch(opcion){
                case 1:
                        comienzo(jugador1, vDadosAzar, 5);
                    break;
                case 2 :
                    break;
                case 3:
                    break;
                case 4:
                    exit=false;
                    break;
                default:
                    cout<<"Ingrese una opcion CORRECTA"<<endl;
                    cin>>opcion;
                break;
                }
 }
system("cls");
=======
>>>>>>> 63b0bf614f76ff4c418a0a4edb245d8692e93e8b
}




