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

void mostrarArray(int vDados[], int posX, int posY){
    rlutil::setColor(rlutil::COLOR::GREY);
    for(int i = 0; i <5; i++){
        rlutil::locate(posX, posY);
        cout<<vDados[i]<<endl;
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

void accionesCursor(int posCursor, int tecla, bool &salida){
            if(tecla == 1){
                switch(posCursor){
                    case 0:
                    rlutil::cls();
                    cout<<"Me presionaste en jugador 1"<<endl;
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


//preguntar que es vPJ[]

/*
void PosibleCombinacion(int vDados[],int tam,int vPJ[]){
  int i;
  for (i=0;i<tam;i++){
    if(vDados[i]==1)vPJ[0]=1;
     if(vDados[i]==2)vPJ[1]=1;
      if(vDados[i]==3)vPJ[2]=1;
       if(vDados[i]==4)vPJ[3]=1;
        if(vDados[i]==5)vPJ[4]=1;
         if(vDados[i]==6)vPJ[5]=1;
         if(bool escalera(int vDados[], int tam)==true)vPJ[6]=1;
         //funcion detectar full poker generala
    }
}

//funcion para detectar si hay o no hay una posible jugada
void hayOnoJugada(int vPJ[]){
    bool hayJugada=false;
    int i;
    for (i=0;i<=9;i++){
            if(vPJ[i]==1)hayJugada=true;
                      }
    hayJugada ? elegirJugada(int vPJ[],int ComNoJug[]) : cancelarJugada(int ComNoJug[]);
}

//f para elegir una jugada que sea posible
void elegirJugada(int vPJ[],int ComNoJug[]){
    int jugada;
    cout<<"elija una jugada"<<endl;
    for (i=0;i<=9;i++){
        if(vPJ[i]==1)cout<<"jugada"<<i+1<<endl;
    }
    cin>>jugada;
system("clear");
while (vPJ[jugada-1]!=1&&ComNoJug[jugada-1]!=1){
    cout<<"eligio una jugada que no era posible"<<endl;
    cout<<"elija una jugada"<<endl;
    for (i=0;i<=9;i++){
        if(vPJ[i]==1)cout<<"jugada"<<i+1<<endl;
    }
    cin>>jugada;
system("clear");
}
switch(jugada){
                case 1:

                    break;
                case 2 :  int jugadaAlNumero(int vDados[]),ComNoJug[jugada-1]=0;
                    break;
                case 3:  int jugadaAlNumero(int vDados[]),ComNoJug[jugada-1]=0;
                    break;
                case 4:  int jugadaAlNumero(int vDados[]),ComNoJug[jugada-1]=0;
                    break;
                case 5: int jugadaAlNumero(int vDados[]),ComNoJug[jugada-1]=0;
                    break;
                case 6:  int jugadaAlNumero(int vDados[]),ComNoJug[jugada-1]=0;
                    break;
                case 7:  int escalerapuntos(int vDados[]),ComNoJug[jugada-1]=0;
                    break;
                case 8:  int fullpuntos(int vDados[]),ComNoJug[jugada-1]=0;
                    break;
                case 9:  int pokerpuntos(int vDados[]),ComNoJug[jugada-1]=0;
                    break;
                case 10  int generalapuntos(int vDados[]),ComNoJug[jugada-1]=0;

                break;
    }
}
*/









#endif // JUGADORUNO_H_INCLUDED
