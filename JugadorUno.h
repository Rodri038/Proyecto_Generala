///Definicion de funciones
#ifndef JUGADORUNO_H_INCLUDED
#define JUGADORUNO_H_INCLUDED
#include "Funciones.h"
#include "JugadorDos.h"

void jugadorDeAUno(int puntaje[],char nombre1[]){
    int cantRondas;
    int vDadosAzar[5];
    int comNoJug[10];
    int vPJ[10];
    char jugador1[20] = {};
    puntaje[0] = 0;
    cantRondas = cantidadDeRondas();
    pedirNombres(nombre1);
    rlutil::cls();
    comienzo(vDadosAzar, 5, cantRondas, vPJ, comNoJug, puntaje, nombre1, 0);
}

void ponerEnUno(int Array[], int tam ){
    int i;
   for(i=0; i<=tam-1; i++){
    Array[i] = 1;
   }
}

//da comienzo a la partida
int cantidadDeRondas(){
    int rondas=0;
    rlutil::cls();
    mostrarTexto("Cuantas Rondas jugamos?", 45, 14);
    rlutil::locate(56,15);
    rlutil::setColor(rlutil::COLOR::GREY);
    cin>> rondas;
    rlutil::cls();
    return rondas;
}

//menu de opciones principal
void mostrarTexto(const char* text, int posX, int posY){
    rlutil::setColor(rlutil::COLOR::GREY);
    rlutil::locate(posX, posY);
    cout<< text <<endl;
}

void comienzo(int vDados[], int tam, int cantRondas, int vPJ[], int comoNoJug[], int puntaje[], char nombre1[], int jugador){
    int contador=1;
    mostrarNombre(nombre1,1);
    ponerEnUno(comoNoJug, 10);
    ponerEnCero(puntaje, 2);
    mostrarPuntaje(puntaje, jugador);
do{
    volverAtirar(vDados, tam, vPJ, comoNoJug, puntaje, jugador, nombre1);
    cout<<"Ronda numero :"<<contador<<endl;
    getch();
    rlutil::cls();
    contador++;
    }while(contador <= cantRondas);
}

void volverAtirar(int vDados[],int tam, int vPJ[], int comoNoJug[], int puntaje[], int jugador, char nombre[]){
int contador =1;
bool eligio=false;
    tirarDados(vDados,tam);
while (contador<3){
    mostrarPuntaje(puntaje, jugador);
    mostrarNombre(nombre,1);
    ponerEnCero( vPJ, 10);
    posibleCombinacion( vDados, tam, vPJ);
    cargarMenu2(3, 15, vDados, tam, vPJ, comoNoJug, puntaje, 0, nombre, eligio, contador);
}
    if(!eligio) hayOnoJugada(vPJ, comoNoJug, vDados, puntaje, jugador);
    contador=1;
    eligio=false;
}

void cargarMenu2(int xPosTexto, int yPosTexto, int vDados[],int tam, int vPJ[], int comoNoJug[], int puntaje[], int jugador, char nombre[], bool &choise, int &cont){
    int op = 1, y = 0;
    rlutil::hidecursor();
    do{
    mostrarTexto("Volver a tirar o Cancelar Jugada", xPosTexto, yPosTexto);
    mostrarTexto("Volver a tirar", xPosTexto, yPosTexto+1);
    mostrarTexto("Cancelar", xPosTexto, yPosTexto+2);
    mostrarTexto("Elegir jugada", xPosTexto, yPosTexto+3);
    //posicion en la que se dibuja el cursor
    rlutil::locate((xPosTexto - 2),(yPosTexto +1) + y);
    std::cout<<(char)175<<std::endl;
    switch(rlutil::getkey()){
    case 14:
        rlutil::locate((xPosTexto - 2),(yPosTexto + 1) + y);//Arriba
        std::cout<<" "<<std::endl;
        y--;
        if(y <= 0) y = 0;
        break;
    case 15:
        rlutil::locate((xPosTexto - 2),(yPosTexto + 1) + y);//Abajo
        std::cout<<" "<<std::endl;
        y++;
        if(y >= 2) y = 2;
        break;
    case 1://Enter

        accionesDeCursor2(y, xPosTexto, yPosTexto, vDados, tam, vPJ, comoNoJug, puntaje, 0, nombre, choise, cont, op);
        break;
        }
    }while(op != 0);
}

void accionesDeCursor2(int &key, int xPosTexto, int yPosTexto, int vDados[],int tam, int vPJ[], int comoNoJug[], int puntaje[], int jugador, char nombre[], bool &choise, int &cont, int &salir){
switch(key){
                    case 0:
                        cambiarDados(vDados);
                        ponerEnCero(vPJ, 10);
                        rlutil::cls();
                        ordenarDeMenorAMayor(vDados, tam);
                        mostrarArray(vDados, 50, 10);
                        cont++;
                        posibleCombinacion(vDados, tam, vPJ);
salir=0;
                    break;
                    case 1:
                        choise = true;
                        CancelarJugada(comoNoJug);
                        cont = 3;
                        salir = 0;
                        rlutil::cls();
                    break;
                    case 2:
                        choise = true;
                        rlutil::cls();
                        mostrarPuntaje(puntaje, jugador);
                        mostrarNombre(nombre,1);
                        ordenarDeMenorAMayor(vDados, tam);
                        mostrarArray(vDados, 50, 10);
                        ponerEnCero(vPJ, 10);
                        posibleCombinacion(vDados, tam, vPJ);
                        hayOnoJugada(vPJ, comoNoJug, vDados, puntaje, jugador );
                        rlutil::cls();
                        cont = 3;
                        salir = 0;
                    break;
        }
    }
void tirarDados(int vDados[], int tam){
    ponerEnCero(vDados,tam);
    //ponerEnUno(vDados, tam);//solo para probar jugar Generala
    cargarDados(vDados, tam);
    ordenarDeMenorAMayor(vDados, tam);
    mostrarArray(vDados, 50, 12);
}
//Funcion poner en cero array

void ponerEnCero(int vDados[], int tam ){
    int i;
   for(i=0; i<=tam-1; i++){
    vDados[i] = 0;
   }
}

//carga los numeros del array y genera un numero aleatorio por cada posicion
void cargarDados(int vDados[], int tam){
    int i;
        srand(time(NULL));
        for(i = 0; i<=tam-1; i++){
            vDados[i] = rand() % 6 + 1;
    }
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

void mostrarArray(int vDados[], int posX, int posY){
    rlutil::setColor(rlutil::COLOR::GREY);
    for(int i = 0; i <5; i++){
        rlutil::locate(posX, posY);
        MostrarDados( vDados,posX,posY);
        //cout<<vDados[i]<<endl;
      //  cout<<" "<<endl;
      //  posX+5;
    }
}

void posibleCombinacion(int vDados[], int tam, int vPJ[]){
  int i;
  for (i = 0; i <tam ; i++){
    if(vDados[i]==1)vPJ[0]=1;
     if(vDados[i]==2)vPJ[1]=1;
      if(vDados[i]==3)vPJ[2]=1;
       if(vDados[i]==4)vPJ[3]=1;
        if(vDados[i]==5)vPJ[4]=1;
         if(vDados[i]==6)vPJ[5]=1;
            }
            if( escalera( vDados, tam) == 25) vPJ [6] = 1;
            if( armadoDeJuegos( vDados,  tam) == 30) vPJ [7] =1;
            if( armadoDeJuegos( vDados,  tam) == 40) vPJ [8] =1;
            if( armadoDeJuegos(vDados,  tam) == 50) vPJ [9] =1;
}

//funcion para  detectar el juego Escalera
int escalera(int vDados[], int tam){
    int i, valor, puntos=25;
    bool juego=true;
    valor = vDados[0];
    for(i = 1; i <=tam-1;i++){
        vDados [i] == valor + 1 ? valor=vDados[i] : juego=false;// 1 2 3 4 5
        }
    if(juego){
    return puntos;
    }
}


void escalera2( int puntaje[], int jugador){
    int  puntos=25;
    puntaje[jugador] += puntos;
}

//Funcion para detectar los juegos de Full-Poker-Generala
int armadoDeJuegos(int vDados[], int tam){
    int i, igualesAnterior=0, iguales=0, cantIguales=1, auxiliar, puntos=0;
    auxiliar = vDados[0];
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
    iguales += igualesAnterior;
    if(iguales == 5&&cantIguales==1){
        puntos = 50;
    }else if(iguales == 5&& cantIguales == 2){
        puntos = 30;
    }else if(iguales == 4&& cantIguales == 2){
        puntos = 40;
    }
    return puntos;
}

void full( int puntaje[],int jugador){
 int  puntos=30;
    puntaje[jugador] += puntos;
}

void poker( int puntaje[], int jugador){
 int  puntos=40;
    puntaje[jugador] += puntos;
}

void generala( int puntaje[], int jugador){
 int  puntos=50;
        puntaje[jugador] += puntos;
}


//funcion para elegir cambiar dados
void cambiarDados(int vDados[]){
        int i, cantidad, posicion;
        mostrarTexto("Cuantos dados desea cambiar? ", 40, 2);
        rlutil::locate(40, 3);
        cin>>cantidad;
    while (cantidad>5){
        mostrarTexto("Solo hay 5 dados             ", 40, 2);
        mostrarTexto("Cuantos dados desea cambiar?    ", 40, 3);
        rlutil::locate(40, 4);
        cin>>cantidad;
    }
        mostrarTexto("En que posiciones desea cambiar los dados?", 40, 2);
        mostrarTexto("                                     ", 40, 3);
        mostrarTexto("                  ", 40, 4);
    for(i = 0; i <cantidad; i++){
        srand(time(NULL));
        rlutil::locate(40, 4);
        cin>>posicion;
     while (posicion>5){
        mostrarTexto("Solo hay 5 pocisiones                      ", 40, 2);
        mostrarTexto("En que posiciones desea cambiar los dados? ", 40, 3);
        rlutil::locate(40, 4);
        cin>>posicion;
        }
        vDados[posicion-1] = rand() % 6 + 1;
    }
}

//funcion para detectar si hay o no hay una posible jugada
void hayOnoJugada(int vPJ[], int comoNoJug[], int vDados[], int puntaje[], int jugador){
    bool hayJugada = false;
    int i;
for (i=0;i<=9;i++){
        if(vPJ[i]==1&&comoNoJug[i]==1) hayJugada=true;
                  }
hayJugada ? elegirJugada(vPJ,comoNoJug, vDados, puntaje, jugador) : CancelarJugada(comoNoJug);
}

void menuElegirJugada(int vPJ[],int comoNoJug[]){
    int i;
    for(i = 0; i <= 9; i++){
        if(vPJ[i] == 1&&comoNoJug[i]==1){
            menuJuegos(i);
        }
    }
}

//f para elegir una jugada que sea posible
void elegirJugada(int vPJ[],int comoNoJug[], int vDados[], int puntaje[], int jugador){
    int jugada=0;
    rlutil::locate(2, 15);
    cout<<"elija una jugada  "<<endl;
    menuElegirJugada(vPJ,comoNoJug);
    //mostrarJugadasPosibles(vPJ);
    cin>>jugada;
    while (vPJ[jugada-1]!=1||comoNoJug[jugada-1]!=1){
        rlutil::locate(1, 15);
        cout<<"eligio una jugada que no era posible"<<endl;
        cout<<"elija una jugada       "<<endl;
        menuElegirJugada(vPJ,comoNoJug);
        cin>>jugada;
    }
switch(jugada){
                case 1:
                    jugadaAlNumero2(vDados , jugada, puntaje, jugador ),comoNoJug[jugada-1]=0;
                    break;
                case 2 :
                    jugadaAlNumero2(vDados,jugada, puntaje, jugador),comoNoJug[jugada-1]=0;
                    break;
                case 3:
                    jugadaAlNumero2(vDados,jugada, puntaje, jugador ),comoNoJug[jugada-1]=0;
                    break;
                case 4:
                    jugadaAlNumero2(vDados,jugada, puntaje, jugador),comoNoJug[jugada-1]=0;
                    break;
                case 5:
                    jugadaAlNumero2(vDados,jugada, puntaje, jugador ),comoNoJug[jugada-1]=0;
                    break;
                case 6:
                     jugadaAlNumero2(vDados,jugada, puntaje, jugador),comoNoJug[jugada-1]=0;
                    break;
                case 7:
                      escalera2(puntaje, jugador),comoNoJug[jugada-1]=0;
                    break;
                case 8:
                      full( puntaje, jugador),comoNoJug[jugada-1]=0;
                    break;
                case 9:
                      poker( puntaje, jugador),comoNoJug[jugada-1]=0;
                    break;
                case 10:
                      generala(puntaje, jugador),comoNoJug[jugada-1]=0;
                 break;
    }
}

//funcion para jugar al numero, recibe un vector, y retorna los puntos de acuerdo a la eleccion del numero
int jugadaAlNumero(int vDados[], int eleccion){
int  i, cant=0, puntos;
    for(i = 0; i <= 4; i++){
            if(eleccion == vDados[i]) cant++;
        }
        if(eleccion <= 6){
        puntos = eleccion * cant;
        }else{
        cant = 0;
        }
        return puntos;
}

int jugadaAlNumero2(int vDados[], int eleccion, int puntaje[], int jugador){
int  i, cant=0, puntos;
    for(i = 0; i <= 4; i++){
            if(eleccion == vDados[i]) cant++;
        }
        if(eleccion <= 6){
        puntos = eleccion * cant;
        puntaje[jugador] += puntos;
        }else{
        cant = 0;
        }
        return puntos;
}

void pedirNombres(char nombre[]){
    mostrarTexto("Ingrese su nombre para comenzar a jugar: ", 40, 10);
    rlutil::setColor(rlutil::COLOR::GREY);
    rlutil::locate(40, 11);
    cin.ignore();
    cin.getline(nombre, 20, '\n');
}

//f para tachar jugada , cuando no hay jugada posible
void CancelarJugada(int comoNoJug[]){
int i , jugada;
//cout<<"no hay una jugada posible "<<endl;
 rlutil::cls();
 rlutil::locate(2, 15);
cout<<"Elija que jugada tachar"<<endl;
for (i = 0; i<= 9 ; i++){
        if(comoNoJug[i]==1){//cout<<"jugada "<< i + 1 <<endl;
        menuJuegos(i);
        }
    }
cin>>jugada;
while(comoNoJug[jugada-1]!=1){
        rlutil::locate(2, 15);
    cout<<"eligio una jugada que ya se jugo o ya fue tachada"<<endl;
    cout<<"elija que jugada tachar"<<endl;
for (i = 0; i<= 9 ; i++){
        if(comoNoJug[i]==1){//cout<<"jugada "<< i + 1 <<endl;
        menuJuegos(i);
        }
    }
cin>>jugada;
}
comoNoJug[jugada-1]=0;
}

void mostrarPuntaje(int puntaje[], int jugador){
    if(jugador==0){ mostrarTexto("PUNTAJE: ", 2, 1);
    rlutil::locate(10, 1);
    cout<<puntaje[jugador]<<endl;

    }else{mostrarTexto("PUNTAJE: ", 2, 1);
    rlutil::locate(10, 1);
    cout<<puntaje[jugador]<<endl;

    }

}
void mostrarNombre(char unNombre[],int jugador){
    if(jugador==1){
      rlutil::locate(2, 2);
    cout<<unNombre<<endl;

    }else{
    rlutil::locate(2, 2);
    cout<<unNombre<<endl;
    }

    }


void menuJuegos(int opciones){
    switch(opciones){
            case 0:
                cout<<"jugada al numero: "<< opciones + 1<<"          "<<endl;
            break;
            case 1:
                cout<<"jugada al numero: "<< opciones + 1<<"          "<<endl;
            break;
            case 2:
                cout<<"jugada al numero: "<< opciones + 1<<"          "<<endl;
            break;
            case 3:
                cout<<"jugada al numero: "<< opciones + 1<<"          "<<endl;
            break;
            case 4:
                cout<<"jugada al numero: "<< opciones + 1<<"          "<<endl;
            break;
            case 5:
                cout<<"jugada al numero: "<< opciones + 1<<"          "<<endl;
            break;
            case 6:
                cout<<"jugada a Escalera: "<<opciones +1<<"          "<<endl;
            break;
            case 7:
                cout<<"jugada a Full: "<<opciones +1<<"          "<<endl;
            break;
            case 8:
                cout<<"jugada a Poker: "<<opciones +1<<"          "<<endl;
            break;
            case 9:
                cout<<"jugada a Generala: "<<opciones +1<<"          "<<endl;
            break;
            }
}


#endif // JUGADORUNO_H_INCLUDED
