#include "CMenu.h"


void leerArchivo(){
    ifstream fi
    ;
    fi.open("E://UTEC//POO.1//Proyecto1//texto//laberinto.txt");
    if(fi.is_open()){//abre el archivo
        fi>>ALTO>>ANCHO>>CANTIDAD;//almacena solo los tres primeros
    }
    fi.close();
}
int main() {
    leerArchivo();
    CMenu menu;
    menu.ejecutar();
    return 0;
}