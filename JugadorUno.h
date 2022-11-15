///Definicion de funciones
#ifndef JUGADORUNO_H_INCLUDED
#define JUGADORUNO_H_INCLUDED
#include "Funciones.h"
#include "JugadorDos.h"

int cursor2 = 0;

void posicionDeCursor(int posX, int posY, int &posCursor, int tecla, int maxAbajo){
                    switch(tecla){
                    case 15: //Abajo es 14 ASCII
                        rlutil::locate(posX, (posY + posCursor));
                        cout<<" "<<endl;
                        posCursor++;
                        if(posCursor > (maxAbajo - 1) ) posCursor = (maxAbajo - 1);
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

void ponerEnUno(int Array[], int tam ){
    int i;
   for(i=0; i<=tam-1; i++){
    Array[i] = 1;
   }
}

void accionesCursor(int posCursor, int tecla, bool &salida, int tam, int vDados[], int vPJ[], int comoNoJug[], int puntaje[], int &nroTiradas, char nombre1[], char nombre2[], int comoNoJug2[]){//vPJ =  vector de posible jugada
    int cantRondas;
            if(tecla == 1){
                switch(posCursor){
                    case 0:
                        rlutil::cls();
                        puntaje[0] = 0;
                        cantRondas = cantidadDeRondas();
                        pedirNombres(nombre1);
                        rlutil::cls();
                        comienzo(vDados, tam, cantRondas, vPJ, comoNoJug, puntaje, nroTiradas, salida, nombre1, tecla, 0);
                        break;
                    case 1:
                        cantRondas = cantidadDeRondas();
                        comienzoJuegoDos(vDados ,tam,cantRondas, vPJ, comoNoJug , puntaje, nroTiradas, salida, nombre1 ,nombre2, tecla, comoNoJug2);
                        break;
                    case 2:
                        mostrarPuntaje(puntaje, 0);
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

void comienzo(int vDados[], int tam, int cantRondas, int vPJ[], int comoNoJug[], int puntaje[], int &nroTiradas, bool &salida, char nombre1[], int tecla, int jugador){
    int contador=1;
    mostrarNombre(nombre1);
    ponerEnUno(comoNoJug, 10);
    ponerEnCero(puntaje, 2);
    mostrarPuntaje(puntaje, jugador);
do{
    volverAtirar(vDados, tam, vPJ, comoNoJug, puntaje, jugador, nroTiradas, salida, nombre1, tecla);
    cout<<"Ronda numero :"<<contador<<endl;
    getch();
    rlutil::cls();
    contador++;
    }while(contador <= cantRondas);
}

void volverAtirar(int vDados[],int tam, int vPJ[], int comoNoJug[], int puntaje[], int jugador, int &nroTiradas, bool &salida, char nombre[], int tecla){
int contador =1, n;
nroTiradas += contador;
bool eligio=false;
    tirarDados(vDados,tam);
while (contador<3){//el tema esta en que cuando cambia dados, los cambia, pero a su vez vuelve a tirar
    mostrarPuntaje(puntaje, jugador);
    mostrarNombre(nombre);
    ponerEnCero( vPJ, 10);
    posibleCombinacion( vDados, tam, vPJ);
    rlutil::locate(2, 15);
    cout<<"Volver a tirar o Cancelar Jugada"<<endl;
    cout<<"[Volver a tirar] ingrese 1"<<endl;
    cout<<"[Cancelar]  ingrese 2"     <<endl;
    cout<<"[Elegir jugada] ingrese 0: ";
    cin>>n;
    while (n!=1&&n!=2&&n!=0){
    rlutil::locate(2, 15);
    cout<<"Eligio una opcion inexistente      "<<endl;
    cout<<"Volver a tirar o Cancelar Jugada"<<endl;
    cout<<"[Volver a tirar] ingrese 1"<<endl;
    cout<<"[Cancelar]  ingrese 2      "<<endl;
    cout<<"[Elegir jugada] ingrese 0: ";
    cin>>n;

    }
    switch(n){
    case 1:
    cambiarDados(vDados);
    ponerEnCero(vPJ, 10);
    rlutil::cls();
    ordenarDeMenorAMayor(vDados, tam);
    mostrarArray(vDados, 50, 12);
    contador++;
    posibleCombinacion(vDados, tam, vPJ);
    break;
    case 2:
    eligio = true;
    CancelarJugada(comoNoJug);
    contador = 3;
    break;
    case 0:
    eligio = true;
    rlutil::cls();
    mostrarPuntaje(puntaje, jugador);
    mostrarNombre(nombre);
    ordenarDeMenorAMayor(vDados, tam);
    mostrarArray(vDados, 50, 12);
    ponerEnCero(vPJ, 10);
    posibleCombinacion(vDados, tam, vPJ);
    hayOnoJugada(vPJ, comoNoJug, vDados, puntaje, jugador , nroTiradas, salida);
    contador = 3;
    break;
    default:
    rlutil::cls();
    mostrarTexto("Ingrese una opcion correcta", 50, 14);
    break;
        }
    }
    if(!eligio) hayOnoJugada(vPJ, comoNoJug, vDados, puntaje, jugador, nroTiradas, salida);
    contador=1;
    eligio=false;
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
        cout<<vDados[i]<<endl;
        cout<<" "<<endl;
        posX+=3;
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

void generala( int puntaje[], int jugador, int &nroTiradas, bool &salida){
 int  puntos=50;
        if(nroTiradas ==  1) salida = true;
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
void hayOnoJugada(int vPJ[], int comoNoJug[], int vDados[], int puntaje[], int jugador, int &nroTiradas, bool &salida){
    bool hayJugada = false;
    int i;
for (i=0;i<=9;i++){
        if(vPJ[i]==1&&comoNoJug[i]==1) hayJugada=true;
                  }
hayJugada ? elegirJugada(vPJ,comoNoJug, vDados, puntaje, jugador,  nroTiradas, salida) : CancelarJugada(comoNoJug);
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
void elegirJugada(int vPJ[],int comoNoJug[], int vDados[], int puntaje[], int jugador, int &nroTiradas, bool &salida){
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
                      generala(puntaje, jugador, nroTiradas, salida),comoNoJug[jugada-1]=0;
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
    mostrarTexto("PUNTAJE: ", 2, 1);
    rlutil::locate(10, 1);
    cout<<puntaje[jugador]<<endl;
}

void mostrarNombre(char unNombre[]){
    rlutil::locate(2, 2);
    cout<<unNombre<<endl;
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
