#ifndef JUGADORDOS_H_INCLUDED
#define JUGADORDOS_H_INCLUDED


#include "Funciones.h"
#include "JugadorUno.h"
void jugadorDeADos(int puntaje[],char nombre1[],char nombre2[]){
    int cantRondas;
    int comNoJug2[10];
    int comNoJug[10];
    int vDadosAzar[5];
    int vPJ[10];
    char jugador1[20] = {};
    char jugador2[20] = {};
    cantRondas = cantidadDeRondas();
    comienzoJuegoDos(vDadosAzar , 5,cantRondas, vPJ, comNoJug , puntaje, nombre1 ,nombre2, comNoJug2);
}

void comienzoJuegoDos(int vDados[], int tam, int cantRondas,int vPJ[], int comoNoJug[],int puntaje[], char nombre1[], char nombre2[], int comoNoJug2[]){
    int contador=1;
    mostrarTexto("Nombre jugador UNO", 52, 9);
    pedirNombres(nombre1);
    rlutil::cls();
    mostrarTexto("Nombre jugador DOS", 52, 9);
    pedirNombres(nombre2);
    rlutil::cls();
    ponerEnUno(comoNoJug, 10);
    ponerEnUno(comoNoJug2, 10);
    ponerEnCero(puntaje, 2);

do{
    EntreRondas( contador,nombre1,nombre2, puntaje);
    volverAtirar(vDados, tam, vPJ, comoNoJug, puntaje, 0, nombre1);
    cout<<"Ronda numero : "<<contador<<endl;
    getch();
    rlutil::cls();
    contador++;
  EntreRondas( contador,nombre1,nombre2, puntaje);
    volverAtirar(vDados, tam, vPJ, comoNoJug2, puntaje, 1, nombre2);
    cout<<"Ronda numero : "<<contador<<endl;
    getch();
    rlutil::cls();
    contador++;
    }while(contador <= cantRondas);
}
void DibujarLinea(int EmpiezaX,int EmpiezaY,int TerminaX ,int TerminaY,int orientacion,int TopBotom,int tipo){
int Y,X,I;
//orientacion
//1=vertical
//2=horizontal
//Topbotom=arriba o abajo
//3=top
//4=botom
 if (orientacion==1){
        I=0;
for(Y=EmpiezaY;Y<TerminaY;I++){
        Y++;
           rlutil::locate(EmpiezaX,EmpiezaY+I);

       std::cout<<(char)tipo<<endl;

           }
        }


    if(orientacion==2){
I=0;
    for(X=EmpiezaX;X<TerminaX;I++){
            X++;
            if(tipo==186){
                rlutil::locate(EmpiezaX+I,EmpiezaY);
         std::cout<<(char)205<<endl;

            }
        if(tipo==179){
                rlutil::locate(EmpiezaX+I,EmpiezaY);
         std::cout<<(char)196<<endl;

    }
if(TopBotom==3){//top
        if(tipo==186){
             rlutil::locate(EmpiezaX,EmpiezaY);
            std::cout<<(char)201<<endl;

            rlutil::locate(TerminaX,EmpiezaY);
            std::cout<<(char)187<<endl;
        }
        if(tipo==179){
             rlutil::locate(EmpiezaX,EmpiezaY);
            std::cout<<(char)218<<endl;

            rlutil::locate(TerminaX,EmpiezaY);
            std::cout<<(char)191<<endl;


        }
}
if(TopBotom==4){//botom
        if(tipo==186){
         rlutil::locate(EmpiezaX,EmpiezaY);
            std::cout<<(char)200<<endl;

            rlutil::locate(TerminaX,EmpiezaY);
            std::cout<<(char)188<<endl;
        }
         if(tipo==179){
             rlutil::locate(EmpiezaX,EmpiezaY);
            std::cout<<(char)192<<endl;

             rlutil::locate(TerminaX,EmpiezaY);
            std::cout<<(char)217<<endl;

         }
}


}


}}
void DibujarCuadrado(int xE,int yE,int ancho,int largo,int tipo){
    int xT,yT;
    xT=xE+ancho;
    yT=yE+largo;

DibujarLinea(xT,yE,xT,yT,1,0,tipo);
DibujarLinea(xE,yE,xE,yT,1,0,tipo);
DibujarLinea(xE,yE,xT,yE,2,3,tipo);
DibujarLinea(xE,yT,xT,yT,2,4,tipo);

}





void EntreRondas(int contador,char nombre1[], char nombre2[],int puntaje[]){
DibujarCuadrado( 30, 5,50,20,186);
mostrarRonda( contador, 50,6);
mostrarProxTurno(contador,45,10,nombre1,nombre2);
mostrarNombresyPuntos(nombre1,nombre2,puntaje);

 Cargando(3);
 rlutil::cls();

}
void Cargando(int vueltas){
    int i;
for(i=0;i<=vueltas;i++){
     mostrarTexto("Cargando    ", 50, 24);
    rlutil::msleep( 	400);
    mostrarTexto("Cargando.   ", 50, 24);
    rlutil::msleep( 	400);
    mostrarTexto("Cargando..   ", 50, 24);
    rlutil::msleep( 	400);
    mostrarTexto("Cargando...   ", 50, 24);
    rlutil::msleep( 	400);


}}
void mostrarNombresyPuntos(char unNombre[],char unNombre2[],int puntaje[]){

      rlutil::locate(44, 15);
    cout<<unNombre<<":"<<puntaje[0]<<" Puntos"<<endl;


    rlutil::locate(44, 16);
    cout<<unNombre2<<":"<<puntaje[1]<<" Puntos"<<endl;


}
void mostrarRonda(int ronda,int posX,int posY){

rlutil::locate(posX, posY);
cout<<"Ronda N"<<(char)167<<ronda<<endl;

}
void mostrarProxTurno(int ronda,int posX,int posY,char unNombre[],char unNombre2[]){
if(ronda%2==0){
rlutil::locate(posX, posY);
cout<<"Proximo turno:"<<unNombre2<<endl;
}else{
rlutil::locate(posX, posY);
cout<<"Proximo turno:"<<unNombre<<endl;
}}
void MuestraPuntajes(char nombre1[], char nombre2[],int puntaje[]){
     rlutil::cls();
    DibujarCuadrado( 30, 5,50,20,186);
    mostrarNombresyPuntos(nombre1,nombre2,puntaje);
    Cargando(3);
 rlutil::cls();


}
//
 //DibujarDado( 3, 3, 0);
void DibujarDado(int PosX,int PosY,int Numero){
int ancho=8;
int largo=4;



 switch(Numero){
                case 1:
                   DibujarCuadrado( PosX, PosY,ancho,largo,179);
                   DibujarPuntos(Numero,PosX,PosY);

                    break;
                case 2:
                    DibujarCuadrado( PosX, PosY,ancho,largo,179);
 DibujarPuntos(Numero,PosX,PosY);
                    break;
                case 3:
                   DibujarCuadrado( PosX, PosY,ancho,largo,179);
 DibujarPuntos(Numero,PosX,PosY);
                    break;
                case 4:
                   DibujarCuadrado( PosX, PosY,ancho,largo,179);
 DibujarPuntos(Numero,PosX,PosY);
                    break;
                case 5:
                   DibujarCuadrado( PosX, PosY,ancho,largo,179);
 DibujarPuntos(Numero,PosX,PosY);
                    break;
                case 6:
                   DibujarCuadrado( PosX, PosY,ancho,largo,179);
 DibujarPuntos(Numero,PosX,PosY);
                    break;



           }    }
void DibujarPuntos(int Numero,int PosX,int PosY){
if (Numero==1){
rlutil::locate(PosX+4, PosY+2);
cout<<(char)254<<endl;
}else{if(Numero==2){
    rlutil::locate(PosX+1, PosY+1);
cout<<(char)254<<endl;
rlutil::locate(PosX+7, PosY+3);
cout<<(char)254<<endl;
}else{if(Numero==3){
rlutil::locate(PosX+4, PosY+2);
cout<<(char)254<<endl;
rlutil::locate(PosX+1, PosY+1);
cout<<(char)254<<endl;
rlutil::locate(PosX+7, PosY+3);
cout<<(char)254<<endl;
}else{if(Numero==4){
rlutil::locate(PosX+2, PosY+1);
cout<<(char)254<<endl;
rlutil::locate(PosX+6, PosY+1);
cout<<(char)254<<endl;
rlutil::locate(PosX+2, PosY+3);
cout<<(char)254<<endl;
rlutil::locate(PosX+6, PosY+3);
cout<<(char)254<<endl;
}else{if(Numero==5){
rlutil::locate(PosX+2, PosY+1);
cout<<(char)254<<endl;
rlutil::locate(PosX+6, PosY+1);
cout<<(char)254<<endl;
rlutil::locate(PosX+2, PosY+3);
cout<<(char)254<<endl;
rlutil::locate(PosX+6, PosY+3);
cout<<(char)254<<endl;
rlutil::locate(PosX+4, PosY+2);
cout<<(char)254<<endl;
}else{if(Numero==6){
rlutil::locate(PosX+2, PosY+1);
cout<<(char)254<<endl;
rlutil::locate(PosX+6, PosY+1);
cout<<(char)254<<endl;
rlutil::locate(PosX+2, PosY+3);
cout<<(char)254<<endl;
rlutil::locate(PosX+6, PosY+3);
cout<<(char)254<<endl;
rlutil::locate(PosX+2, PosY+2);
cout<<(char)254<<endl;
rlutil::locate(PosX+6, PosY+2);
cout<<(char)254<<endl;
}
}
}


}
}}}
void MostrarDados(int vDados[],int posX,int posY){

int i;
for (i=0;i<6;i++){
if(i==0)DibujarDado( posX, posY, vDados[i]);
   if (i!=0) DibujarDado( posX+=9, posY, vDados[i]);

}



}



#endif // JUGADORDOS_H_INCLUDED
