///Definicion de funciones
#ifndef JUGADORUNO_H_INCLUDED
#define JUGADORUNO_H_INCLUDED
#include "funciones.h"

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

void ponerEnUno(int Array[], int tam ){
    int i;
   for(i=0; i<=tam-1; i++){
    Array[i] = 1;
   }
}

void accionesCursor(int posCursor, int tecla, bool &salida, int tam, int vDados[], int vPJ[], int comoNoJug[], int puntaje[], int &jugador, int &nroTiradas, char nombre1[]){//vPJ =  vector de posible jugada
    int cantRondas;
            if(tecla == 1){
                switch(posCursor){
                    case 0:
                    rlutil::cls();
                    jugador = 0;
                    puntaje[jugador] = 0;
                    cantRondas = cantidadDeRondas();
                    pedirNombres(nombre1);
                    rlutil::cls();
                    comienzo(vDados,tam,cantRondas,vPJ, comoNoJug, puntaje, jugador, nroTiradas, salida, nombre1);
                        break;
                    case 1:
                    cout<<"Me presionaste en jugador 2"<<endl;
                        break;
                    case 2:
                    cout<<"Me presionaste en puntaje"<<endl;
                    mostrarPuntaje(puntaje, jugador);
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

void comienzo(int vDados[], int tam, int cantRondas, int vPJ[], int comoNoJug[], int puntaje[], int &jugador, int &nroTiradas, bool &salida, char nombre1[]){
    int contador=1;
    mostrarNombre(nombre1);
    ponerEnUno(comoNoJug, 10);
    ponerEnCero(puntaje, 2);
    mostrarPuntaje(puntaje, jugador);
do{
    volverAtirar(vDados, tam, vPJ, comoNoJug, puntaje, jugador, nroTiradas, salida, nombre1);
    cout<<"Ronda numero :"<<contador<<endl;
    system("pause");
    rlutil::cls();
    contador++;
    }while(contador <= cantRondas);
}

void volverAtirar(int vDados[],int tam, int vPJ[], int comoNoJug[], int puntaje[], int &jugador, int &nroTiradas, bool &salida, char nombre1[]){
int contador =1,n;
bool eligio=false;
    tirarDados(vDados,tam);
    mostrarPuntaje(puntaje, jugador);
    mostrarNombre(nombre1);
while (contador<3){//el tema esta en que cuando cambia dados, los cambia, pero a su vez vuelve a tirar
    ponerEnCero( vPJ, 10);
    posibleCombinacion( vDados, tam, vPJ, puntaje, jugador);

    rlutil::locate(2, 15);
    cout<<"Quiere volver a tirar "<<endl;
    cout<<"[SI] ingrese 1 , [NO] ingrese 0: ";
    cin>>n;
    switch(n){
    case 1:
        cambiarDados(vDados);
        ponerEnCero(vPJ, 10);
        rlutil::cls();
        ordenarDeMenorAMayor(vDados, tam);
        mostrarArray(vDados, 50, 12);
        contador++;
        posibleCombinacion(vDados, tam, vPJ, puntaje, jugador);
    break;
    case 0:
        eligio = true;
        ponerEnCero(vPJ, 10);
        posibleCombinacion(vDados, tam, vPJ, puntaje, jugador);
        hayOnoJugada(vPJ, comoNoJug, vDados, puntaje, jugador, nroTiradas, salida);
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

void posibleCombinacion(int vDados[], int tam, int vPJ[], int puntaje[], int &jugador){
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
int escalera2( int puntaje[], int &jugador){
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


void full( int puntaje[], int &jugador){
 int  puntos=30;
    puntaje[jugador] += puntos;
}

void poker( int puntaje[], int &jugador){
 int  puntos=40;
    puntaje[jugador] += puntos;
}

void generala( int puntaje[], int &jugador, int &nroTiradas, bool &salida){
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
    mostrarTexto("En que posiciones desea cambiar los dados?", 40, 2);
    for(i = 0; i <cantidad; i++){
        srand(time(NULL));
        cin>>posicion;
        vDados[posicion-1] = rand() % 6 + 1;
    }
}

//funcion para detectar si hay o no hay una posible jugada
void hayOnoJugada(int vPJ[], int comoNoJug[], int vDados[], int puntaje[], int &jugador, int &nroTiradas, bool &salida){
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
            switch(i){
            case 0:
                cout<<"jugada al numero: "<< i + 1<<endl;
            break;
            case 1:
                cout<<"jugada al numero: "<< i + 1<<endl;
            break;
            case 2:
                cout<<"jugada al numero: "<< i + 1<<endl;
            break;
            case 3:
                cout<<"jugada al numero: "<< i + 1<<endl;
            break;
            case 4:
                cout<<"jugada al numero: "<< i + 1<<endl;
            break;
            case 5:
                cout<<"jugada al numero: "<< i + 1<<endl;
            break;
            case 6:
                cout<<"jugada a Escalera: "<<i +1<<endl;
            break;
            case 7:
                cout<<"jugada a Full: "<<i +1<<endl;
            break;
            case 8:
                cout<<"jugada a Poker: "<<i +1<<endl;
            break;
            case 9:
                cout<<"jugada a Generala: "<<i +1<<endl;
            break;
            }
        }
    }
}

//f para elegir una jugada que sea posible
void elegirJugada(int vPJ[],int comoNoJug[], int vDados[], int puntaje[], int &jugador, int &nroTiradas, bool &salida){
    int jugada=0;
    cout<<"elija una jugada"<<endl;
    menuElegirJugada(vPJ,comoNoJug);
    //mostrarJugadasPosibles(vPJ);
    cin>>jugada;
    while (vPJ[jugada-1]!=1||comoNoJug[jugada-1]!=1){
        cout<<"eligio una jugada que no era posible"<<endl;
        cout<<"elija una jugada"<<endl;
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
int jugadaAlNumero2(int vDados[], int eleccion, int puntaje[], int &jugador){
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
void pedirNombres(char nombre1[]){
    rlutil::cls();
    mostrarTexto("Ingrese su nombre para comenzar a jugar: ", 40, 10);
    rlutil::setColor(rlutil::COLOR::GREY);
    rlutil::locate(55, 11);
    cin>>nombre1;
}


//f para tachar jugada , cuando no hay jugada posible
void CancelarJugada(int comoNoJug[]){
int i , jugada;
cout<<"no hay una jugada posible "<<endl;
cout<<"elija que jugada tachar"<<endl;
for (i = 0; i<= 9 ; i++){
        if(comoNoJug[i]==1)cout<<"jugada "<< i + 1 <<endl;
    }
cin>>jugada;
while(comoNoJug[jugada-1]!=1){
    cout<<"eligio una jugada que ya se jugo o ya fue tachada"<<endl;
    cout<<"elija que jugada tachar"<<endl;
for (i=0;i<=9;i++){
        if(comoNoJug[i]==1)cout<<"jugada "<<i+1<<endl;
    }
cin>>jugada;
}
comoNoJug[jugada-1]=0;
}

void mostrarPuntaje(int puntaje[], int &jugador){
    mostrarTexto("PUNTAJE: ", 2, 1);
    rlutil::locate(10, 1);
    cout<<puntaje[jugador]<<endl;
}

void mostrarNombre(char unNombre[]){
    rlutil::locate(2, 2);
    cout<<unNombre<<endl;
    }



#endif // JUGADORUNO_H_INCLUDED


