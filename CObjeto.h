//
// Created by Adrian on 20/11/2019.
//

#ifndef BORRADOR_PUNTEROS_COBJETO_H
#define BORRADOR_PUNTEROS_COBJETO_H

#include "Tipos.h"

class CObjeto {
private:
    Tipo_tablero Nvidas;
    Tipo_string m_Nombre;
    Tipo_caracter m_NombrE;
    Tipo_caracter m_Color;
    Tipo_tablero m_PosX;
    Tipo_tablero m_PosY;
public:
    CObjeto(Tipo_string pNombre, Tipo_caracter pColor, Tipo_tablero pPosX, Tipo_tablero pPosY, Tipo_tablero pNvidas);
    CObjeto(Tipo_caracter pNombre, Tipo_caracter pColor, Tipo_tablero pPosX, Tipo_tablero pPosY,Tipo_tablero pNvidas);
    CObjeto(Tipo_string pNombre, Tipo_caracter pColor);
    CObjeto();
    virtual ~CObjeto();
    void setNombre(Tipo_string pNombre);
    Tipo_string getNombre();
    Tipo_tablero getPosX();
    Tipo_tablero getPosY();
    Tipo_caracter getColor();
    Tipo_string getPosicion();
    Tipo_tablero aumPosX();
    Tipo_tablero aumPosY();
    Tipo_tablero disPosX();
    Tipo_tablero disPosY();
    Tipo_tablero getVidas();
    Tipo_tablero quitarVidas();
};


#endif //BORRADOR_PUNTEROS_COBJETO_H
