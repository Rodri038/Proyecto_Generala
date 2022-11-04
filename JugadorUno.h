///Definicion de funciones
#ifndef JUGADORUNO_H_INCLUDED
#define JUGADORUNO_H_INCLUDED
#include "funciones.h"

//int puntaje[2];
//void mostrar puntaje (int puntaje[],)



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

void accionesCursor(int posCursor, int tecla, bool &salida,char nombre[],int tam,int vDados[]){
    int cantRondas;
            if(tecla == 1){
                switch(posCursor){
                    case 0:
                    rlutil::cls();
                    cout<<"Me presionaste en jugador 1"<<endl;
                    cantRondas=cantidadDeRondas();
                 comienzo(nombre,vDados,tam,cantRondas,vPJ);
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

void ponerEnUno(int Array[], int tam ){
    int i;
   for(i=0; i<=tam-1; i++){
    Array[i] = 1;
   }
}



//Funcion poner en cero array
void ponerEnCero(int Array[], int tam ){
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
//da comienzo a la partida

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

void volverAtirar(int vDados[],int tam,int vPJ[]){
int contador =1,n;
while (contador<=3){
    tirarDados( vDados,tam);
    ponerEnCero( vPJ, 10);
    PosibleCombinacion( vDados, tam, vPJ);
    cout<<"quiere volver a tirar"<<endl;
cout<<"si si ,ingrese 1 si , no ingrese 0:   ";
cin>>n;
if(n==1){tirarDados( vDados,tam);
ponerEnCero( vPJ, 10);
PosibleCombinacion( vDados, tam, vPJ);
contador++;

        }
else{hayOnoJugada(vPJ,vDados);
contador=3;
    }

                   }

                                                  }
void tirarDados(int vDados[],int tam){
cargarDados(vDados, tam);
    mostrarArray(vDados, 50, 11);
    ordenarDeMenorAMayor(vDados, tam);

}

void comienzo(char nombre[], int vDados[], int tam, int cantRondas,int vPJ[]){
    int rondas, contador=1;
    int juegos, escaleraGame;
    ponerEnUno(ComNoJug,10);
    do{


    volverAtirar(vDados,tam, vPJ);





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
int jugadaAlNumero(int vDados[],int eleccion){
    int  i, cant=0, puntos;
cout<<"jugaste al numero:"<<eleccion<<endl;
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



//funcion para detectar si hay o no hay una posible jugada
void hayOnoJugada(int vPJ[],int vDados[]){
    bool hayJugada=false;
    int i;
for (i=0;i<=9;i++){
        if(vPJ[i]==1&&ComNoJug[i]==1)hayJugada=true;
                  }
hayJugada==true?elegirJugada(vPJ,ComNoJug,vDados):CancelarJugada(ComNoJug);
}



//f para elegir una jugada que sea posible
void elegirJugada(int vPJ[],int ComNoJug[],int vDados[]){
    int jugada=0;
    int i;
    cout<<"elija una jugada"<<endl;
    for (i=0;i<=9;i++){
        if(vPJ[i]==1&&ComNoJug[i]==1)cout<<"jugada N*"<<i+1<<endl;


    }

    cin>>jugada;
     if(ComNoJug[jugada-1]==0||vPJ[jugada-1]==0){
            rlutil::cls();
        while (vPJ[jugada-1]!=1||ComNoJug[jugada-1]!=1){
    cout<<"eligio una jugada que no era posible"<<endl;
    cout<<"elija una jugada"<<endl;
     mostrarArray(vDados, 50, 11);
    for (i=0;i<=9;i++){
        if(vPJ[i]==1&&ComNoJug[i]==1)cout<<"jugada N*"<<i+1<<endl;
    }
    cin>>jugada;
rlutil::cls();
}


     }
rlutil::cls();

switch(jugada-1){
                case 0:
                    jugadaAlNumero(vDados,jugada ),ComNoJug[jugada-1]=0;
                    break;
                case 1 :
                    jugadaAlNumero(vDados,jugada),ComNoJug[jugada-1]=0;
                    break;
                case 2:
                    jugadaAlNumero(vDados,jugada ),ComNoJug[jugada-1]=0;
                    break;
                case 3:
                    jugadaAlNumero(vDados,jugada),ComNoJug[jugada-1]=0;
                    break;
                case 4:
                    jugadaAlNumero(vDados,jugada ),ComNoJug[jugada-1]=0;
                    break;
                case 5:
                     jugadaAlNumero(vDados,jugada),ComNoJug[jugada-1]=0;
                    break;
                case 6:
                      escalera(vDados,5 ),ComNoJug[jugada-1]=0;
                    break;
                case 7:
                    armadoDeJuegos(vDados, 5),ComNoJug[jugada-1]=0;
                    break;
                case 8:
                    armadoDeJuegos(vDados, 5),ComNoJug[jugada-1]=0;
                    break;
                case 9:
                 armadoDeJuegos(vDados, 5),ComNoJug[jugada-1]=0;

                break;
                }

}


//f para tachar jugada , cuando no hay jugada posible
void CancelarJugada(int ComNoJug[]){
int i , jugada;
cout<<"no hay una jugada posible "<<endl;
cout<<"elija que jugada tachar"<<endl;
for (i=0;i<=9;i++){
        if(ComNoJug[i]==1)cout<<"jugada"<<i+1<<endl;
    }
cin>>jugada;
rlutil::cls();
while(ComNoJug[jugada-1]!=1){
    cout<<"eligio una jugada que ya se jugo o ya fue tachada"<<endl;
    cout<<"elija que jugada tachar"<<endl;
for (i=0;i<=9;i++){
        if(ComNoJug[i]==1)cout<<"jugada"<<i+1<<endl;
    }
cin>>jugada;
rlutil::cls();
}
ComNoJug[jugada-1]=0;
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





void PosibleCombinacion(int vDados[],int tam,int vPJ[]){
  int i;
  for (i=0;i<tam;i++){
    if(vDados[i]==1)vPJ[0]=1;
     if(vDados[i]==2)vPJ[1]=1;
      if(vDados[i]==3)vPJ[2]=1;
       if(vDados[i]==4)vPJ[3]=1;
        if(vDados[i]==5)vPJ[4]=1;
         if(vDados[i]==6)vPJ[5]=1;

    }
    if( escalera( vDados, tam)==25)vPJ[6]=1;
         if( armadoDeJuegos( vDados,  tam)==30)vPJ[7]=1;
         if( armadoDeJuegos( vDados,  tam)==40)vPJ[8]=1;
         if( armadoDeJuegos(vDados,  tam)==50)vPJ[9]=1;
}



#endif // JUGADORUNO_H_INCLUDED
