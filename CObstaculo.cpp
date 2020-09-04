//
// Created by Adrian on 26/11/2019.
//

#include "CObstaculo.h"

CObstaculo::CObstaculo() {}

CObstaculo::CObstaculo (Tipo_string mNombre, Tipo_caracter mColor, Tipo_tablero mPosX, Tipo_tablero mPosY,Tipo_tablero mNvidas,
                       Tipo_tablero pDano, Tipo_string pTipo)
                       :CObjeto(mNombre,mColor, mPosX, mPosY,mNvidas) {m_Dano=pDano; m_Tipo=pTipo;}

CObstaculo::CObstaculo(Tipo_tablero pDano, Tipo_string pTipo): m_Dano{pDano}, m_Tipo{pTipo} {}

CObstaculo::~CObstaculo() {}




void CObstaculo::DanarRobot(CRobot *pRobot,CObstaculo  *pObstaculo ){
    p_robot = pRobot;
    p_obstaculo = pObstaculo;

        if(p_obstaculo->getPosY()  == p_robot->getPosY() && p_obstaculo->getPosX() == p_robot->getPosX()){
            p_robot->disVidas();
            cout<<"las vidas de "<<p_robot->getNombre()<<" ahora es: "<<p_robot->getNvidas()<<endl;
        }
        else{cout<<"no hay obstaculos cerca cerca"<<endl;}
}


Tipo_tablero CObstaculo ::dismVidas() {
    quitarVidas();
}
Tipo_tablero CObstaculo::getnVidas() {
    getVidas();
}

