//
// Created by Adrian on 26/11/2019.
//

#ifndef BORRADOR_PUNTEROS_CROBOT_H
#define BORRADOR_PUNTEROS_CROBOT_H

#include "CObjeto.h"




class CRobot: public CObjeto{
private:
    //Tipo_string Ncontroles;
    //Tipo_tablero Nvidas;
    Tipo_tablero Ntamano;
    Tipo_string Npoder;
    CRobot* m_robot;
    CRobot* p_robot;
public:
    CRobot();
    //CRobot(): m_Opcion{} {}
    CRobot(Tipo_string mNombre, Tipo_caracter mColor, Tipo_tablero mPosX, Tipo_tablero mPosY,
            Tipo_tablero pNvidas, Tipo_tablero pNtamano, Tipo_string pNpoder);
    CRobot(Tipo_tablero pNtamano, Tipo_string pNpoder);
    virtual ~CRobot();
    Tipo_tablero getNtamano();
    Tipo_string getNpoder();
    void duelo(CRobot* robot,CRobot* mrobot, Tipo_string pControles,Tipo_caracter letra);
    Tipo_tablero disVidas();
    Tipo_tablero getNvidas();




};


#endif //BORRADOR_PUNTEROS_CROBOT_H
