///Definicion de funciones
#ifndef JUGADORUNO_H_INCLUDED
#define JUGADORUNO_H_INCLUDED
#include "funciones.h"

//menu de opciones principal
void mostrarTexto(const char* text, int posX, int posY){
    rlutil::setColor(rlutil::COLOR::GREY);
    rlutil::locate(posX, posY);
    cout<< text <<endl;
}

void mostrarArray(int vVector[], int posX, int posY){
    rlutil::setColor(rlutil::COLOR::GREY);
    for(int i = 0; i <5; i++){
        rlutil::locate(posX, posY);
        cout<<vVector[i]<<endl;
        cout<<" "<<endl;
        posX+=3;
    }
}

void posicionDeCursor(int posX, int posY, int &posCursor, int tecla){
                    switch(tecla){
                    case 15: //Abajo es 14 ASCII
                        rlutil::locate(posX, (posY + posCursor));
                        cout<<" "<<endl;
                        posCursor++;
                        if(posCursor >3) posCursor = 3;
                        break;
                    case 14://Arriba es 15 ASCII
                        rlutil::locate(posX, (posY + posCursor));
                        cout<<" "<<endl;
                        posCursor--;
                        if(posCursor < 0) posCursor = 0;
                    default :
                        break;
                    }
                }

void accionesCursor(int posCursor, int tecla, bool &salida, char nombre[],  int vDados[], int tam){
            int cantRondas;
            if(tecla == 1){
                switch(posCursor){
                    case 0:
                    rlutil::cls();
                        pedirNombres(nombre);
                        cantRondas = cantidadDeRondas();
                        comienzo(nombre, vDados, tam, cantRondas);
                        cin.get();
                        mostrarTexto("Volver a tirar o jugar alguna jugada disponible?",50, 2);
                        mostrarTexto("Volver a tirar", 50, 3);
                        mostrarTexto("Jugadas disponibles", 50, 4);
                        rlutil::cls();
                        break;
                    case 1:
                    cout<<"Me presionaste en jugador 2"<<endl;
                        break;
                    case 2:
                    cout<<"Me presionaste en puntaje"<<endl;
                        break;
                    case 3:
                        cout<<"Me presionaste en Salir, Adios!!"<<endl;
                        salida=false;
                        break;
            default:
            break;
        }
    }
}

//Funcion poner en cero array
void ponerEnCero(int Array[], int tam){
    int i;
   for(i=0; i<=tam-1; i++){
    Array[i] = 0;
   }
}

void pedirNombres(char nombre[]){
    rlutil::cls();
    mostrarTexto("Ingrese su nombre para comenzar a jugar: ", 40, 10);
    rlutil::setColor(rlutil::COLOR::GREY);
    rlutil::locate(55, 11);
    cin>>nombre;
}

int cantidadDeRondas(){
    int rondas=0;
    rlutil::cls();
    mostrarTexto("Cuantas Rondas jugamos?", 40, 2);
    rlutil::locate(50,3);
    rlutil::setColor(rlutil::COLOR::GREY);
    cin>> rondas;
    rlutil::cls();
    return rondas;
}

//da comienzo a la partida
void comienzo(char nombre[], int vDados[], int tam, int cantRondas){
    int rondas, contador=1;
    int juegos, escaleraGame;
    do{
    ponerEnCero(vDados, 5);
    cargarDados(vDados, 5);
    mostrarArray(vDados, 50, 11);
    ordenarDeMenorAMayor(vDados, 5);
    escaleraGame = escalera(vDados, 5);
    juegos = armadoDeJuegos(vDados, 5);
    if(escaleraGame==25){
            cout<<"Formaste Escalera"<<endl;
    }else if(juegos==30){
            cout<<"Formaste Full"<<endl;
    }else if(juegos==40){
            cout<<"Formaste Poker"<<endl;
    }else if(juegos==50){
            cout<<"Formaste Generala"<<endl;
    };
    system("pause");
    rlutil::cls();
    contador++;
    }while(contador<=cantRondas);
}


//carga los numeros del array y genera un numero aleatorio por cada posicion
void cargarDados(int vDados[], int tam){
    int i;
        srand(time(NULL));
        for(i = 0; i<=tam-1; i++){
            vDados[i] = rand() % 6 + 1;
        }
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

//funcion ordenar numeros de menor a mayor
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

//funcion para  detectar el juego Escalera
int escalera(int vDados[], int tam){
    int i, valor, puntos=25;
    bool juego=true;
        valor=vDados[0];
        for(i = 1; i <=tam-1;i++){
            vDados[i]==(valor+1) ? valor=vDados[i] : juego=false;
        }
        if(juego) return puntos;
}

//Funcion para detectar los juegos de Full-Poker-Generala
int armadoDeJuegos(int vDados[], int tam){
    int i, igualesAnterior=0, iguales=0, cantIguales=1, auxiliar, puntos=0;
    auxiliar=vDados[0];
    for(i = 1; i <= tam-1; i++){
        if(vDados[i]==auxiliar){
            if(iguales==0){
                iguales+=2;
            }else{
                iguales++;
            }
        }else{
            auxiliar=vDados[i];
            cantIguales++;
            igualesAnterior=iguales;
            iguales=0;
        }
    }
    iguales+=igualesAnterior;
    if(iguales==5&&cantIguales==1){
        puntos=50;
    }else if(iguales==5&&cantIguales==2){
        puntos=30;
    }else if(iguales==4&&cantIguales==2){
        puntos=40;
    }
    return puntos;
}


void cabiarPoscionDados(int vDados, int tam, ){
    int i, cantDados, posicion;
    cout<<"cuantos dados queres cambiar"<<endl;
    cin<<cantDados;
    cout<<"que posicion de dado cambiar?"<<endl;
    for(i = 0; i<=canDados, i++){
        cin>>posicion;
        vDados[posicion-1] = rand() % 6;
    }
}










#endif // JUGADORUNO_H_INCLUDED
