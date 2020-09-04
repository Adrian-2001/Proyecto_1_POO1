//
// Created by Adrian on 22/11/2019.
//

#ifndef BORRADOR_CMENU_H
#define BORRADOR_CMENU_H
#include "Tipos.h"
#include "CArena.h"
#include "CRobot.h"
#include "CObstaculo.h"

template <typename T>
T input(string label){
    T value;
    cout<< label;
    cin>> value;
    cin.clear();
    return value;
}


class CMenu {
    Tipo_tablero m_Opcion;
    CArena m_CArena;
    CRobot m_robot;
    CObstaculo m_obstaculo;
    void imprimirMenu();
    void seleccionarOpcion();
    void agregarRobot();
    void agregarObstaculos(vector<Tipo_tablero>V1, Tipo_tablero cantidad);
    void removerObjeto();
    void leer();
    void dibujarMapa();
    //void agregarSalida();
public:
    CMenu();
    void ejecutar();
    void jugar();
    void leer(Tipo_string nombre, Tipo_string nombre2,Tipo_string pControles, Tipo_caracter letra);
};


#endif //BORRADOR_PUNTEROS_CMENU_H
