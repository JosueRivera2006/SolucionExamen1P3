#include "Inventario.h"
#include <stdlib.h>
#include <time.h>
Inventario::Inventario() {
}
Inventario::~Inventario() { //este metodo realiza la liberacion necesaria para eliminar todos los punteros de los vectores de la clase
    for (int posicionBloque = 0; posicionBloque < bloques.size(); posicionBloque++) {
        delete bloques.at(posicionBloque);
    }
    for (int posicionPico = 0; posicionPico < picos.size(); posicionPico++) {
        delete picos.at(posicionPico);
    }
    
}
void Inventario::añadirPalos() {
    if(palos < 9) {
        cout << "Se añadio el palo con éxito." << endl;
        palos++;
    } else {
        cout << "No se puede agregar más palos porque la cantidad máxima es de 9." << endl;
    }
    cout << "Total de palos: " << palos << endl;
}

void Inventario::añadirPiedra() {
    srand(time(NULL));
    int verificarPosibilidad = rand() % 100 + 1;
    if(verificarPosibilidad <= 75) {
        piedras++;
        cout << "Se añadio la piedra con éxito." << endl;
    } else {
        cout << "No se añadio la piedra. La probabilidad no le favoreció" << endl;
    }
    cout << "Total de piedras: " << piedras << endl;
}

void Inventario::añadirLingotes() {
    srand(time(NULL));
    int verificarPosibilidad = rand() % 100 + 1;
    if(verificarPosibilidad <= 50) {
        lingotesDeHierro++;
        cout << "Se añadio el lingote de hierro con éxito." << endl;
    } else {
        cout << "No se añadio el lingote de hierro. La probabilidad no le favoreció" << endl;
    }
    cout << "Total de lingotes de hierro: " << lingotesDeHierro << endl;
}

void Inventario::añadirDiamantes() {
    srand(time(NULL));
    int verificarPosibilidad = rand() % 100 + 1;
    if(verificarPosibilidad <= 25) {
        diamantes++;
        cout << "Se añadio el diamante con éxito." << endl;
    } else {
        cout << "No se añadio el diamante. La probabilidad no le favoreció" << endl;
    }
    cout << "Total de diamantes: " << diamantes << endl;
}

void Inventario::crearPicoPiedra() {
    if(palos >= 2 && piedras >= 3) {
        Pico* nuevoPico = new Pico();
        nuevoPico->darMaterial("Piedra");
        nuevoPico->modificarVidaDelPico(100);
        picos.push_back(nuevoPico);
        cout << "Se ha creado el pico de piedra exitosamente." << endl;
        piedras = piedras - 3;
        palos = palos - 2;
    } else {
        cout << "Le falta material para crear el pico." << endl;
    }
}

void Inventario::crearPicoHierro() {
    if(palos >= 2 && lingotesDeHierro >= 3) {
        Pico *nuevoPico = new Pico;
        nuevoPico->darMaterial("Hierro");
        nuevoPico->modificarVidaDelPico(250);
        picos.push_back(nuevoPico);
        cout << "Se ha creado el pico de hierro exitosamente." << endl;
        lingotesDeHierro = lingotesDeHierro - 3;
        palos = palos - 2;
    } else {
        cout << "Le falta material para crear el pico." << endl;
    }
}

void Inventario::crearPicoDiamante() {
    if(palos >= 2 && diamantes >= 3) {
        Pico *nuevoPico = new Pico;
        nuevoPico->darMaterial("Diamante");
        nuevoPico->modificarVidaDelPico(500);
        picos.push_back(nuevoPico);
        cout << "Se ha creado el pico de diamante exitosamente." << endl;
        diamantes = diamantes - 3;
        palos = palos - 2;
    } else {
        cout << "Le falta material para crear el pico." << endl;
    }
}

void Inventario::añadirBloque() {
    bool continuar = true;
    int option;
    do { //ESTE SWITCH LLAMA EL METODO QUE SE QUIERA USAR PARA PODER AGREGAR UN BLOQUE
        cout << "---Tipo de Bloques---" << endl << "0. Agregar Obsidiana" << endl << "1. Agregar Oro" << endl << "2. Agregar carbón" << endl << "Eliga un bloque: " << endl;
        cin >> option;
        switch(option) {
            case 0:
                agregarObsidiana();
                continuar = false;
                break;
            case 1:
                agregarOro();
                continuar = false;
                break;
            case 2:
                agregarCarbon();
                continuar = false;
                break;
            default:
                cout << "Esa no es una opción válida, devuelta a la lista de bloques..." << endl;
        }
    } while(continuar);
}
void Inventario::ListarPicos() {
    if(picos.size() > 0) {
        for (int posicionPico = 0; posicionPico < picos.size(); posicionPico++) {
            cout << posicionPico << ") ";
            picos.at(posicionPico)->mostrarInformacion();
        }
    } else {
        cout << "No hay picos en el inventario." << endl;
    }
}
void Inventario::ListarBloques() {
    if(bloques.size()) {
        for (int posicionBloque = 0; posicionBloque < bloques.size(); posicionBloque++) {
            cout << posicionBloque << ") ";
            bloques.at(posicionBloque)->mostrarInformacion();
        }
    } else {
        cout << "No hay bloques en el inventario." << endl;
    }
}
void Inventario::agregarObsidiana() {
    srand(time(NULL));
    int verificarPosibilidad = rand() % 100 + 1;
    if(verificarPosibilidad <= 33) {
        Bloque* nuevoBloque = new Bloque();
        nuevoBloque->indicarMaterial("Obsidiana");
        nuevoBloque->indicarDurabilidad(275);
        nuevoBloque->indicarTiempo(15.0);
        cout << "Se añadio la obsidiana correctamente." << endl;
        bloques.push_back(nuevoBloque);
    } else {
        cout << "Que mala suerte, la probabilidad no le favoreció, no se ha agregado la obsidiana." << endl;
    }
}

void Inventario::agregarOro() {
    srand(time(NULL));
    int verificarPosibilidad = rand() % 100 + 1;
    if(verificarPosibilidad <= 66) {
        Bloque* nuevoBloque = new Bloque();
        nuevoBloque->indicarMaterial("Oro");
        nuevoBloque->indicarDurabilidad(118);
        nuevoBloque->indicarTiempo(12.1);
        cout << "Se añadio el oro correctamente." << endl;
        bloques.push_back(nuevoBloque);
    } else {
        cout << "Que mala suerte, la probabilidad no le favoreció, no se ha agregado el oro." << endl;
    }
}

void Inventario::agregarCarbon() {
    srand(time(NULL));
    int verificarPosibilidad = rand() % 100 + 1;
    if(verificarPosibilidad <= 75) {
        Bloque* nuevoBloque = new Bloque();
        nuevoBloque->indicarMaterial("Carbon");
        nuevoBloque->indicarDurabilidad(50);
        nuevoBloque->indicarTiempo(6.3);
        cout << "Se añadio el carbon correctamente." << endl;
        bloques.push_back(nuevoBloque);
    } else {
        cout << "Que mala suerte, la probabilidad no le favoreció, no se ha agregado el carbon." << endl;
    }
}
void Inventario::mejorarPico() {
    int opcionPico = -1;
    bool picosDisponibles = false;
    for (int posicionPico = 0; posicionPico < picos.size(); posicionPico++) {
        if(picos.at(posicionPico)->retornarMaterial().at(0) == 'H' || picos.at(posicionPico)->retornarMaterial().at(0) == 'P') {
            picosDisponibles = true;
        }
    }
    if(picosDisponibles && picos.size() > 0) {
        do {
            cout << "Ingrese la posición del pico que desea modificar: " << endl;
            cin >> opcionPico;
            if(opcionPico < 0 || opcionPico >= picos.size()) {
                cout << "Esa posicion no es válida..." << endl;
            }
        } while(opcionPico < 0 || opcionPico >= picos.size()); //LAS COMPARACIONES EN LAS LINEAS 192, 199 Y 206 SIRVEN PARA SABER QUE MATERIAL ESTA HECHO EL PICO, OBTENIENDO LA INICIAL DE ESE MATERIAL Y COMPARANDOLO CON H, P Y D, ADEMAS DE ESO VERIFICA SI EN EL INVENTARIO SE ENCUENTRAN LOS MATERIALE SUFICIENTES, SEGUN EL TIPO DE PICO QUE SE QUIERA MEJORAR
        if(picos.at(opcionPico)->retornarMaterial().at(0) == 'P' && lingotesDeHierro >= 3) { //Estas comparaciones sirven para detectar la inicial del material, y ya con eso declarar sus respectivas propiedades
            picos.at(opcionPico)->darMaterial("Hierro");
            picos.at(opcionPico)->modificarVidaDelPico(250);
            cout << "Se mejoró el pico de piedra a pico de hierro." << endl;
            lingotesDeHierro = lingotesDeHierro - 3;
            cout << "Estadisticas del nuevo Pico: " << opcionPico;
            picos.at(opcionPico)->mostrarInformacion();
        } else if(picos.at(opcionPico)->retornarMaterial().at(0) == 'H' && diamantes >= 3) {
            picos.at(opcionPico)->darMaterial("Diamante");
            picos.at(opcionPico)->modificarVidaDelPico(500);
            cout << "Se mejoró el pico de hierro a pico de diamante," << endl;
            diamantes = diamantes - 3;
            cout << "Estadisticas del nuevo Pico: " << opcionPico;
            picos.at(opcionPico)->mostrarInformacion();
        } else if (picos.at(opcionPico)->retornarMaterial().at(0) == 'D') {
            cout << "El pico de diamante no puede ser mejorado." << endl;
        } else {
            cout << "No se pudo mejorar el pico, hay materiales insuficientes..." << endl;
        }
    } else if(!picosDisponibles && picos.size() > 0) {
        cout << "No hay picos que se puedan mejorar." << endl;
    }
}
void Inventario::romerBloque() {
    int posicionBloque = -1;
    int posicionPico = -1;
    if(bloques.size() > 0 && picos.size() > 0) {
        do {
            cout << "Ingrese la posición del bloque que desea romper: " << endl;
            cin >> posicionBloque;
        } while(posicionBloque < 0 || posicionBloque >= bloques.size());
        ListarPicos();
        do {
            cout << "Ingrese la posición del pico que desea usar: " << endl;
            cin >> posicionPico;
        } while(posicionPico < 0 || posicionPico >= bloques.size());
        int durabilidadB = bloques.at(posicionBloque)->retornarDurabilidad();
        int vidaP = picos.at(posicionPico)->retornarVidaDelPico();
        int diferencia = vidaP - durabilidadB;
        float tiempoParaRomper = bloques.at(posicionBloque)->retornarTiempo();
        char inicialDelPico = picos.at(posicionPico)->retornarMaterial().at(0);
        if(inicialDelPico == 'D') { //AQUI SE ESTA COMPARANDO EL CHAR INICIAL DEL STRING MATERIAL DEL PICO PARA PODER DETERMINAR EL TIEMPO PARA ROMPER EL BLOQUE
            tiempoParaRomper = tiempoParaRomper/2;
        } else if(inicialDelPico == 'H'){
            tiempoParaRomper = tiempoParaRomper - (tiempoParaRomper/4);
        } else {
            tiempoParaRomper = tiempoParaRomper - (tiempoParaRomper * 0.15);
        }
        if(diferencia > 0) { //SI LA DIFERENCIA ES POSITIVA ENTONCES SOLO ES NECESARIO ELIMINAR EL BLOQUE Y REDUCIR LA DURABILIDAD DEL PICO
            picos.at(posicionPico)->modificarVidaDelPico(diferencia);
            cout << "Se rompió el bloque de " << bloques.at(posicionBloque)->retornarMaterial() << " con el pico de ";
            cout << picos.at(posicionPico)->retornarMaterial() << " y vida restante ";
            cout << picos.at(posicionPico)->retornarVidaDelPico() << ", en un tiempo de ";
            cout << tiempoParaRomper << endl;
        }
        if(diferencia < 0) { //SI LA DIFERENCIA ES MENOR A 0 ENTONCES SE TIENE QUE ELIMINAR EL PICO, PERO AL BLOQUE SOLO SE LE TIENE QUE MODIFICAR LA DURABILIDAD Y POR direncia*-1. La RAZON ES QUE COMO LA DIFERENCIA ES NEGATIVA SE TIENE QUE PASAR UN VALOR POSITIVO PARA LA DURABILIDAD.
            picos.erase(picos.begin() + posicionPico);
            bloques.at(posicionBloque)->indicarDurabilidad(diferencia*-1);
            cout << "El pico se rompió. Pero el bloque " << bloques.at(posicionBloque)->retornarMaterial();
            cout << " no se rompió, y su nueva durabilidad es de: " << bloques.at(posicionBloque)->retornarDurabilidad() << endl;
        } else if (diferencia == 0) { //SI LA DIFERENCIA ES IGUAL QUIERE DECIR QUE TANTO EL BLOQUE COMO EL PICO TENIAN LA MISMA DURABILIDAD Y SE TIENEN QUE ELIMINAR LOS DOS
            cout << "Se rompió el bloque de " << bloques.at(posicionBloque)->retornarMaterial() << " con el pico de ";
            cout << picos.at(posicionPico)->retornarMaterial() << " y vida restante ";
            cout << picos.at(posicionPico)->retornarVidaDelPico() << ", en un tiempo de ";
            cout << tiempoParaRomper << endl;
            cout << "ANUNCIO: SE ELIMINO EL BLOQUE Y EL PICO DE SU INVENTARIO." << endl;
            picos.erase(picos.begin() + posicionPico);
            bloques.erase(bloques.begin() + posicionBloque);
        } else {
            bloques.erase(bloques.begin() + posicionBloque);
        }
    } else if(picos.size() > 0) {
        cout << "No hay bloques para poder minar." << endl;
    } else if(bloques.size() > 0) {
        cout << "No hay picos para poder minar." << endl;
    } else {
        cout << "No hay ni picos ni bloques en el inventario." << endl;
    }
}
