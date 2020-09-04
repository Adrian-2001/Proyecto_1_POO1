//
// Created by Adrian on 22/11/2019.
//

#include "CMenu.h"

enum class Opciones { /*Leer=1,*/ AgregarR=1, AgregarO, /*Salida,*/ Remover, Mostrar, jugar};


/*void limpiar() {
    cout << "\033[2J\033[0;0H";
}

void esperar() {
    char w;
    do {
        w = input<Tipo_caracter>("Presione C y Enter para continuar...");
    }while (toupper(w) != 'C');
}*/

void CMenu::imprimirMenu() {
    /*limpiar()*/;
    cout << "MENU\n";
    cout << string(4, '-') << "\n\n";
    /*cout << "1. Leer Archivo\n";*/
    cout << "1. Ingresar Robot\n";
    cout << "2. Implementar los obstaculos\n";
    //cout << "3. Ingresar Salida\n";
    cout << "3. Remover objeto\n";
    cout << "4. Imprimir Arena\n";
    cout << "5. Jugar\n\n";
    cout << "0. Para Salir\n\n";
}

void CMenu::agregarRobot() {
    auto    nombre = input<Tipo_string>(" Ingrese Nombre(string) : ");
    auto color  = input<Tipo_caracter>("Ingrese color (Un caracter): ");

    auto x = input<Tipo_tablero>("Ingrese posicion X : ");

    while (x < 0 || x >= m_CArena.getAncho()) {
        cout << "Posicion X Incorrecta, los limites son: 0, "
             << m_CArena.getAncho() - 1 << "\n";
        x = input<Tipo_tablero>("Ingrese posicion X : ");
    }

    auto y = input<Tipo_tablero>("Ingrese posicion Y : ");

    while (y < 0 || y >= m_CArena.getAncho()) {
        cout  << "Posicion Y Incorrecta, los limites son: 0, "
              << m_CArena.getAlto() - 1 << "\n";
        y = input<Tipo_tablero>("Ingrese posicion Y : ");
    }
    auto vidas = input<Tipo_tablero>("Ingrese vidas(entero): ");
    auto tamano = input<Tipo_tablero>("Ingrese tamano(entero): ");
    auto poder = input<Tipo_string>("Ingrese poder o arma(string): ");
    cout<<endl<<endl;

    m_CArena.agregarObjetos(new CRobot(nombre, color, x, y, vidas, tamano, poder));
}
void CMenu::leer(){
    vector<Tipo_tablero> V1;
    ifstream fi;
    fi.open("E://UTEC//POO.1//Proyecto1//texto//laberinto.txt");
    if(fi.is_open()){//abre el archivo
        fi>>ALTO>>ANCHO>>CANTIDAD;//almacena solo los tres primeros
        while(!fi.eof()){//bucle que recorre los puntos de los obstaculos
            int a;
            fi>>a;//iterador que va por todos los puntos de los obstaculos
            V1.push_back(a);
        }
    }
    fi.close();
    agregarObstaculos(V1,CANTIDAD);
}
void CMenu::agregarObstaculos(vector<Tipo_tablero>V1,Tipo_tablero cantidad) {
    Tipo_tablero x, y, i = 0;
    Tipo_string OBSTACULOS,a= "a";
    cout<<" Ingrese "<<CANTIDAD <<"  letras para los obstaculos(string) : "<<endl;
    cin>> OBSTACULOS;
    cout<<endl<<endl;
    auto color = input<Tipo_caracter>("Ingrese color para los obstaculos (Un caracter): ");
    cout<<endl<<endl;
    auto tipo = input<Tipo_string>("Ingrese el arma que tendran los obstaculos(string): ");
    cout<<endl<<endl;
    auto dano = input<Tipo_tablero>("Ingrese dano de dichas armas(entero): ");
    cout<<endl<<endl;
    auto resistencia = input<Tipo_tablero>("Ingrese cuantos ataques del robot resisten (entero): ");
    cout<<endl<<endl;
    while (cantidad > 0) {
        //a = a + OBSTACULOS[i];
        x = V1[i];
        y = V1[i + 1];
        m_CArena.agregarObjetos(reinterpret_cast<CRobot *>(new CObstaculo(OBSTACULOS, color, x, y, resistencia, dano, tipo)));
        i++;
        cantidad = cantidad - 1;
    }
}

/*void CMenu::agregarSalida() {
    auto x = input<Tipo_tablero>("Ingrese posicion X : ");

    while (x < 0 || x >= m_CArena.getAncho()) {
        cout << "Posicion X Incorrecta, los limites son: 0, "
             << m_CArena.getAncho() - 1 << "\n";
        x = input<Tipo_tablero>("Ingrese posicion X : ");
    }

    auto y = input<Tipo_tablero>("Ingrese posicion Y : ");

    while (y < 0 || y >= m_CArena.getAncho()) {
        cout  << "Posicion Y Incorrecta, los limites son: 0, "
              << m_CArena.getAlto() - 1 << "\n";
        y = input<Tipo_tablero>("Ingrese posicion Y : ");
    }


    m_CArena.agregarObjetos(new CRobot(x, y));
}*/


void CMenu::removerObjeto() {
    auto nombre = input<Tipo_string>("Ingrese Nombre: ");

    CObjeto* obj = m_CArena.removerObjetos(nombre);
    if (obj == nullptr) {
        cout << "Objeto No existe\n";
    }
    else {
        delete obj;
        cout << "Objeto: " << nombre << " ha sido removido\n";
    }
    /*esperar();*/
}

void CMenu::dibujarMapa() {
    /*limpiar();*/
    m_CArena.actualizarArena();
    m_CArena.imprimirArena(cout);
    cout << '\n';
    /*m_CArena.mostrarRobots(cout);
    cout << '\n';*/
    /*esperar();*/
}

void CMenu::ejecutar() {
    do {
        imprimirMenu();
        cin >> m_Opcion;
        seleccionarOpcion();
    } while (m_Opcion != 0);
    cout << "Fin del programa...\n";
}

void CMenu::seleccionarOpcion() {
    /*limpiar()*/;
    switch(Opciones(m_Opcion)) {

        case Opciones::AgregarR:  // Agregar Objeto
            agregarRobot();
            break;
        case  Opciones::AgregarO: // Dibujando Tierra
            leer();
            break;
        /*case  Opciones::Salida: // Dibujando Tierra
            agregarSalida();
            break;*/
        case Opciones::Remover:  // Remover Objeto
            removerObjeto();
            break;
        case  Opciones::Mostrar: // Dibujando Tierra
            dibujarMapa();
            break;
        case  Opciones::jugar: // Dibujando Tierra
            jugar();
            break;
    }
}

void CMenu::jugar(){
    Tipo_caracter letra;
    Tipo_string a = "a";
    Tipo_tablero i = 0;
    auto nombre = input<Tipo_string>("Ingrese Nombre rel robot principal: ");
    cout << endl << endl;
    m_CArena.buscarRobot(nombre);
    auto nombre2 = input<Tipo_string>("Ingrese Nombre rel robot segundario: ");
    cout << endl << endl;
    m_CArena.buscarRobot(nombre2);
    auto pControles1 = input<Tipo_string>(
            "ingrese teclas para poder moverse arriba, abajo, izquierda, derecha, ataque para el principal: ");
    cout << endl << endl;
    auto pControles2 = input<Tipo_string>(
            "ingrese teclas para poder moverse arriba, abajo, izquierda, derecha, ataque para el segundario: ");
    cout << endl << endl;
        do {
            if (dynamic_cast<CRobot *>(m_CArena.buscarRobot(nombre))->getVidas() == 0) { m_CArena.removerObjetos(nombre); dibujarMapa();}
            if (dynamic_cast<CRobot *>(m_CArena.buscarRobot(nombre2))->getVidas() == 0) { m_CArena.removerObjetos(nombre2);dibujarMapa();}
            cout << "juega con " << nombre << " " << "moviendote" << endl <<
                 "presiona 2 para cambiar a " << nombre2 << endl <<
                 "presiona 0 para salir" << endl;
            cin >> letra;
            if (letra == '2') {leer(nombre2, nombre, pControles2, letra); }
            m_robot.duelo(dynamic_cast<CRobot *>(m_CArena.buscarRobot(nombre)),
                          dynamic_cast<CRobot *>(m_CArena.buscarRobot(nombre2)), pControles1, letra);
            /*do { a= a + m_obstaculo.getNombre()[i];
                m_obstaculo.DanarRobot(dynamic_cast<CRobot *>(m_CArena.buscarRobot(nombre)),
                                       dynamic_cast<CObstaculo *>(m_CArena.buscarRobot(a)));
                i ++;
            }while(i<= CANTIDAD);*/
            dibujarMapa();
        } while (letra != '0');
}


void CMenu::leer(Tipo_string nombre, Tipo_string nombre2,Tipo_string pControles, Tipo_caracter letra){
    Tipo_tablero i = 0;
    Tipo_string a= "a";
        do {
            if (dynamic_cast<CRobot *>(m_CArena.buscarRobot(nombre))->getNvidas() == 0) { m_CArena.removerObjetos(nombre); dibujarMapa(); }
            if (dynamic_cast<CRobot *>(m_CArena.buscarRobot(nombre2))->getNvidas() == 0) { m_CArena.removerObjetos(nombre2); dibujarMapa();}
        cout<<"juega con " << nombre<<" "<< "moviendote"<<endl<<
            "presiona 5 para cambiar a "<<nombre2<<endl;
        cin>>letra;
        m_robot.duelo(dynamic_cast<CRobot *>(m_CArena.buscarRobot(nombre)),
                      dynamic_cast<CRobot *>(m_CArena.buscarRobot(nombre2)), pControles, letra);
        /*do{a = a + m_obstaculo.getNombre()[i];
            m_obstaculo.DanarRobot(dynamic_cast<CRobot *>(m_CArena.buscarRobot(nombre)),
                                   dynamic_cast<CObstaculo *>(m_CArena.buscarRobot(a)));
            i++;
        }while(i<= CANTIDAD);*/
        dibujarMapa();
    }while(letra !='5');
}

CMenu::CMenu() : m_Opcion{} {}
