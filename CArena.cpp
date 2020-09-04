#include "CArena.h"
/*Tipo_tablero ALTO;
Tipo_tablero ANCHO;*/

Tipo_tablero ALTO, ANCHO, CANTIDAD;
/*void CArena::leerArchivo(){
    vector<Tipo_tablero> V1;
    ifstream fi;
    fi.open("C://Users//user//Documents//Ciclo2_UTEC//Poo.1//Proyecto//texto//laberinto.txt");
    if(fi.is_open()){//abre el archivo
        fi>>ALTO>>ANCHO>>CANTIDAD;//almacena solo los tres primeros
        while(!fi.eof()){//bucle que recorre los puntos de los obstaculos
            int a;
            fi>>a;//iterador que va por todos los puntos de los obstaculos
            V1.push_back(a);
        }
    }
    fi.close();
    CArena();
}*/
void CArena::resizeTablero(Tipo_tablero pAlto, Tipo_tablero pAncho){
    m_Tablero = new Tipo_caracter*[pAlto];
    for (size_t i = 0; i < pAlto; ++i)
        m_Tablero[i] = new Tipo_caracter[pAncho];
}

CArena::CArena(): m_CantObjetos{0}, m_Alto{ALTO}, m_Ancho{ANCHO}{
    resizeTablero(m_Alto, m_Ancho);
}

CArena::CArena(Tipo_tablero pAlto, Tipo_tablero pAncho): m_Alto {pAlto}, m_Ancho {pAncho}, m_CantObjetos{0} {
    resizeTablero(m_Alto,m_Ancho) ;
}

CArena::~CArena() {
   for (size_t i = 0; i < m_Alto; ++i) {
        delete[] m_Tablero[i];
    }
    delete[] m_Tablero;
    m_Tablero = nullptr;
}

void CArena::agregarObjetos(CRobot *pObjeto) {
    CObjeto** temp = new CObjeto*[m_CantObjetos + 1];
    for (size_t i  = 0; i < m_CantObjetos; ++i)
        temp[i] = m_Objetos[i];
    temp[m_CantObjetos] = pObjeto;

    delete [] m_Objetos;
    m_Objetos = temp;
    m_CantObjetos++;
}

CObjeto* CArena::removerObjetos(Tipo_string pNombre) {
    // Buscando objeto
    auto robot = buscarRobot(pNombre);
    if (robot == nullptr) return nullptr;
    // Eliminando objeto
    CObjeto** temp = new CObjeto*[m_CantObjetos - 1];
    int j = 0;
    for (size_t i  = 0; i < m_CantObjetos; ++i)
        if (m_Objetos[i] != robot) {
            temp[j] = m_Objetos[i];
            j++;
        }
    m_Objetos = temp;
    m_CantObjetos--;
    return robot;
}


CObjeto* CArena::buscarRobot(Tipo_string pNombre) {
    for (size_t i  = 0; i < m_CantObjetos; ++i) {
        if (pNombre == m_Objetos[i]->getNombre()) {
            return m_Objetos[i];
        }
    }
    return nullptr;
}



void CArena::mostrarRobots(ostream &os) {
    for(size_t i=0; i< m_CantObjetos; ++i){
        os<<"* * * * * * ["<<i<<"] ";
        os<< " Nombre "<< m_Objetos[i] -> getNombre()<<" "
          << m_Objetos[i] -> getPosicion()
          <<" color = "<<m_Objetos[i] -> getColor()<<"\n";
    }
}

void CArena::actualizarArena(){
    for (size_t i = 0; i < m_Alto ; ++i) {
        for (size_t j = 0; j < m_Ancho; ++j) {
            m_Tablero[i][j] = COLOR;
        }
    }
    for (size_t k = 0; k < m_CantObjetos; ++k) {
        m_Tablero[m_Objetos[k]->getPosY()][m_Objetos[k]->getPosX()]
                = m_Objetos[k]->getColor();
    }
}

void CArena::imprimirArena(ostream &os) {
    os << '\n';
    os << setw(3) << ' ';
    for (size_t j = 0; j < m_Ancho; ++j)
        os << setw(3) << j;
    os << '\n';
    for (size_t i = 0; i < m_Alto ; ++i) {
        os << setw(3) << i;
        for (size_t j = 0; j < m_Ancho; ++j) {
            os << setw(3) << m_Tablero[i][j];
        }
        os << '\n';
    }
}

Tipo_tablero CArena::getAlto() {
    return m_Alto;
}

Tipo_tablero CArena::getAncho() {
    return m_Ancho;
}










