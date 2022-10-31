///Definicion de funciones
#ifndef JUGADORUNO_H_INCLUDED
#define JUGADORUNO_H_INCLUDED
#include "funciones.h"

//Funcion poner en cero vector posible jugada
void ponerEnCero( int vPJ[]){
    int i;
   for(i=0; i<10; i++){
    vPJ[i] = 0;
   }
}


//Funcion poner en cero array
void ponerEnCero(int Array[], int tam ,int vPJ[]){
    int i;
   for(i=0; i<=tam-1; i++){
    Array[i] = 0;
   }
}

void pedirNombres(char nombre[]){
    cout<<"Ingrese su nombre para comenzar a jugar: "<<endl;
    //cin.getline(jugador1, 20, '\n');
    cin>>nombre;
}

//da comienzo a la partida
void comienzo(char nombre[], int vDados[], int tam,int vPJ[]){
    int tiradas=1;
    bool juegoEscalera;
    pedirNombres(nombre);
    ponerEnCero(vDados, 5);
     ponerEnCero(vPJ[]);
    cout<<"             Bienvenido  "<<nombre<<" a mi juego de generala, jugamos?               "<<endl;
    while(tiradas<=3){
        cargarDados(vDados, 5);
        mostrarDados(vDados, 5);
        //detectar que tipo de juegos se armaron
        ordenarDeMenorAMayor(vDados, 5);
        juegoEscalera = escalera(vDados, 5);
        juegoEscalera ? cout<<"Armaste Escalera" : cout<<"No armaste escalera";
        tiradas++;
        }
    tiradas=1;
}

//carga los numeros del array y genera un numero aleatorio por cada posicion
void cargarDados(int vDados[], int tam){
    int i;
        for(i = 0; i<=tam-1; i++){
            vDados[i]= rand() % 6+1;
        }
}

//muestra los numeros del array
void mostrarDados(int vDados[], int tam){
    int i;
        for(i = 0; i<=tam-1; i++){
            cout<<" "<<vDados[i]<<" ";
            }
        cout<<" "<<endl;
        cin.get();
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

//funcion ordenar numeros
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
bool escalera(int vDados[], int tam){
    int i, valor;
    bool juego=true;
        valor=vDados[0];
        for(i = 1; i <=tam-1;i++){
            vDados[i]>valor ? valor=vDados[i] : juego=false;
        }
        return juego;
}

//funcion para detectar posibles jugadas

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
hayJugada==true?elegirJugada(int vPJ[],int ComNoJug[]):cancelarJugada(int ComNoJug[]);
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


//f para tachar jugada , cuando no hay jugada posible
void CancelarJugada(int ComNoJug[]){
int i , jugada;
cout<<"no hay una jugada posible "<<endl;
cout<<"elija que jugada tachar"<<endl;
for (i=0;i<=9;i++){
        if(ComNoJug[i]==1)cout<<"jugada"<<i+1<<endl;
    }
cin>>jugada;
while(ComNoJug[jugada-1]!=1){
    cout<<"eligio una jugada que ya se jugo o ya fue tachada"<<endl;
    cout<<"elija que jugada tachar"<<endl;
for (i=0;i<=9;i++){
        if(ComNoJug[i]==1)cout<<"jugada"<<i+1<<endl;
    }
cin>>jugada;

}
ComNoJug[jugada-1]=0;
}






#endif // JUGADORUNO_H_INCLUDED
