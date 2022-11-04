#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void menu(){
        int letra=0, rondas;
        int puntaje=0, vDadosAzar[5];
        int comoNoJug[10];
        int vPJ[10];
        char jugador1[20]; //jugador2[20];
        int cursor=0;
        const int inicial=49, comienzoDeTexto=50;
        bool exit=true;

        //hide cursor ocultar el cursor
        rlutil::hidecursor();
            do{
                switch(cursor){
                case 0:
                    letra=74;
                    break;
                case 1:
                    letra=74;
                    break;
                case 2:
                    letra=80;
                    break;
                case 3:
                    letra=83;
                    break;
                }
        mostrarTexto("Elija una opcion para comenzar a jugar", 40,10);
        mostrarTexto("j", inicial,11);
        mostrarTexto("ugar de a UNO", comienzoDeTexto,11);//case 0
        mostrarTexto("j", inicial,12);
        mostrarTexto("ugar de a DOS", comienzoDeTexto,12);//case 1
        mostrarTexto("p", inicial,13);
        mostrarTexto("untaje   ", comienzoDeTexto,13);//case 2
        mostrarTexto("s", inicial,14);
        mostrarTexto("alir del juego", comienzoDeTexto,14);//case 3
                //cursor
                rlutil::locate(49, 11 + cursor);
                cout<< (char)letra <<endl;

//get key escucha la tecla que tocamos y devuelve un entero
        int key = rlutil::getkey();
        posicionDeCursor(inicial, 11, cursor, key);
        accionesCursor(cursor, key, exit, 5, vDadosAzar, vPJ, comoNoJug);
    }while(exit);
}


#endif // MENU_H_INCLUDED
