//
// Created by Adrian on 26/11/2019.
//

#include "CRobot.h"

CRobot::CRobot(Tipo_string mNombre, Tipo_caracter mColor, Tipo_tablero mPosX, Tipo_tablero mPosY,
               Tipo_tablero pNvidas, Tipo_tablero pNtamano, Tipo_string pNpoder)
               :CObjeto(mNombre, mColor, mPosX, mPosY,pNvidas){ Ntamano = pNtamano, Npoder = pNpoder;}


CRobot::CRobot(Tipo_tablero pNtamano, Tipo_string pNpoder):
                Ntamano{pNtamano}, Npoder{pNpoder}{}

CRobot::CRobot(){}

CRobot::~CRobot(){}


//--  por implementar
void CRobot::duelo(CRobot* robot,CRobot* mrobot,Tipo_string pControles, Tipo_caracter letra) {
    m_robot = robot;
    p_robot = mrobot;
        if (letra == pControles[0]) {m_robot->aumPosY();}
        if (letra == pControles[1]) {m_robot->disPosY();}
        if (letra == pControles[2]) {m_robot->disPosX();}
        if (letra == pControles[3]) {m_robot->aumPosX();}
        if (letra == pControles[4]) {
            if(m_robot->getPosY() + 1 == p_robot->getPosY()){
                p_robot->disVidas();
                cout<<"las vidas de "<<p_robot->getNombre()<<" ahora es: "<<p_robot->getNvidas()<<endl;
            }
            else if(m_robot->getPosY() - 1 == p_robot->getPosY()){
                p_robot->disVidas();
                cout<<"las vidas de "<<p_robot->getNombre()<<" ahora es: "<<p_robot->getNvidas()<<endl;
            }
            else if(m_robot->getPosX() + 1 == p_robot->getPosX()){
                p_robot->disVidas();
                cout<<"las vidas de "<<p_robot->getNombre()<<" ahora es: "<<p_robot->getNvidas()<<endl;
            }
            else if(m_robot->getPosX() - 1 == p_robot->getPosX()){
                p_robot->disVidas();
                cout<<"las vidas de "<<p_robot->getNombre()<<" ahora es: "<<p_robot->getNvidas()<<endl;
            }
            /*else{cout<<"no hay objetos cerca"<<endl;}*/

        }
}


Tipo_tablero  CRobot::getNtamano()   { return Ntamano; }
Tipo_string CRobot::getNpoder()   {return Npoder; }
Tipo_tablero CRobot::disVidas() {
    quitarVidas();
}
Tipo_tablero CRobot::getNvidas() {
    getVidas();
}