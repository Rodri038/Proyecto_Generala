///TP-Generala
//Alumnos: Rodrigo Burns
#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

#include "jugadorUno.h"
#include "funciones.h"

int main(){;

menu();

return 0;
}

void menu(){
        bool exit=true;
        int opcion, puntaje=0, vDadosAzar[5], rondas;
        char jugador1[20], jugador2[20];
       do{
                cout<<"---Elija una opcion---"<<endl;
                cout<<"---Jugar de a UNO---[1]"<<endl;
                cout<<"---Jugar de a DOS---[2]"<<endl;
                cout<<"---Puntaje---[3]"<<endl;
                cout<<"---Salir del juego---[4]"<<endl;
                cin>>opcion;

                switch(opcion){
                case 1:
                        pedirNombres(jugador1);
                        cout<<"Cantidad de rondas???"<<endl;
                        cin>>rondas;
                        /*while(contaRondas<rondas){
                            comienzo(jugador1, vDadosAzar, 5);
                        }*/
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
 }while(exit);
system("cls");
}


