//
// Created by Adrian on 20/11/2019.
//

#include "CObjeto.h"
CObjeto::CObjeto() {}


CObjeto::CObjeto(Tipo_string pNombre, Tipo_caracter pColor,
                 Tipo_tablero pPosX, Tipo_tablero pPosY, Tipo_tablero pNvidas):m_Nombre{pNombre}, m_Color{pColor}, m_PosX{pPosX}, m_PosY{pPosY},
                 Nvidas{pNvidas} {}
CObjeto::CObjeto(Tipo_caracter pNombre, Tipo_caracter pColor,
                 Tipo_tablero pPosX, Tipo_tablero pPosY, Tipo_tablero pNvidas):m_NombrE{pNombre}, m_Color{pColor}, m_PosX{pPosX}, m_PosY{pPosY},
                                                                               Nvidas{pNvidas} {}
CObjeto::CObjeto(Tipo_string pNombre, Tipo_caracter pColor)
        :m_Nombre{pNombre}, m_Color{pColor} {
}

CObjeto::~CObjeto() {}
void CObjeto::setNombre(Tipo_string pNombre) { this->m_Nombre = pNombre; }

Tipo_string   CObjeto::getNombre() { return m_Nombre; }
Tipo_tablero   CObjeto::getPosX()   { return m_PosX; }
Tipo_tablero  CObjeto::getPosY()   { return m_PosY; }
Tipo_caracter CObjeto::getColor()  { return m_Color; }
Tipo_string CObjeto::getPosicion() {
    return "X = " + to_string(m_PosX) + " Y = " + to_string(m_PosY);
}
Tipo_tablero CObjeto::aumPosX(){
    m_PosX = m_PosX +1;
    return m_PosX;
}
Tipo_tablero CObjeto::aumPosY(){
    m_PosY = m_PosY -1;
    return m_PosY;
}
Tipo_tablero CObjeto::disPosX(){
    m_PosX = m_PosX -1;
    return m_PosX;
}
Tipo_tablero CObjeto::disPosY(){
    m_PosY = m_PosY +1;
    return m_PosY;
}

Tipo_tablero CObjeto::quitarVidas() {Nvidas = Nvidas - 1; return Nvidas;}
Tipo_tablero CObjeto::getVidas() {return Nvidas;}