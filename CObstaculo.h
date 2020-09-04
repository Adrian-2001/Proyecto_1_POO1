//
// Created by Adrian on 26/11/2019.
//

#ifndef BORRADOR_PUNTEROS_COBSTACULO_H
#define BORRADOR_PUNTEROS_COBSTACULO_H
//herencia, asociasion
#include "CObjeto.h"
#include "CRobot.h"

class CObstaculo: public CObjeto{

private:
    //Tipo_tablero Nvidas;
    Tipo_tablero m_Dano;
    Tipo_string m_Tipo;
    CObstaculo* p_obstaculo;
    CRobot* p_robot;
public:
    CObstaculo();
    virtual ~CObstaculo();
    CObstaculo(Tipo_string mNombre, Tipo_caracter mColor, Tipo_tablero mPosX, Tipo_tablero mPosY, Tipo_tablero mNvidas,
            Tipo_tablero pDano, Tipo_string pTipo);
    CObstaculo(Tipo_tablero pDano, Tipo_string pTipo);
    void DanarRobot(CRobot* pRobot,CObstaculo* pObstaculo);
    Tipo_tablero getnVidas();
    Tipo_tablero dismVidas();
};


#endif //BORRADOR_PUNTEROS_COBSTACULO_H
