



#ifndef BORRADOR_PUNTEROS_CARENA_H
#define BORRADOR_PUNTEROS_CARENA_H
#include "CObjeto.h"
#include "CRobot.h"
#include "CObstaculo.h"

/*const Tipo_tablero ALTO = 10;
const Tipo_tablero ANCHO= 10;*/
const Tipo_caracter COLOR = '.';

class CArena {
private:
    Tipo_tablero m_Alto;
    Tipo_tablero m_Ancho;
    Tipo_tablero m_CantObjetos;
    Tipo_caracter **m_Tablero;
    CObjeto **m_Objetos= nullptr;
    void resizeTablero(Tipo_tablero pAlto, Tipo_tablero pAncho);
public:
    CArena();
    CArena(Tipo_tablero pAlto, Tipo_tablero pAncho);
    virtual ~CArena();
    void agregarObjetos(CRobot *pObjeto);
    CObjeto* removerObjetos(Tipo_string pNombre);
    CObjeto* buscarRobot(Tipo_string pNombre);
    void mostrarRobots(ostream &os);
    //void leerArchivo();
    Tipo_tablero getAlto();
    Tipo_tablero getAncho();
    void imprimirArena(ostream &os);
    void actualizarArena();
};

#endif //BORRADOR_PUNTEROS_CARENA_H
