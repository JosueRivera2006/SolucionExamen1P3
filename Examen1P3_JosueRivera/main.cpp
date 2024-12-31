#include <iostream>
#include "Inventario.h"
#include <cstdlib>
#include <vector>
void menu() {
    Inventario *inventory = new Inventario;
    bool continuar = true;
    int opcion;
    do {
        cout << "---Examen 1---" << endl;
        cout << "0. Salir" << endl;
        cout << "1. Agregar piedra" << endl;
        cout << "2. Agregar lingote de hierro" << endl;
        cout << "3. Agregar diamante" << endl;
        cout << "4. Agregar un palo" << endl;
        cout << "5. Crear pico de piedra" << endl;
        cout << "6. Crear pico de hierro." << endl;
        cout << "7. Crear pico de diamante" << endl;
        cout << "8. Listar picos" << endl;
        cout << "9. Mejorar pico" << endl;
        cout << "10. Listar bloques" << endl;
        cout << "11. Agregar bloque" << endl;
        cout << "12. Romper bloque" << endl;
        cout << "Ingrese una opción: " << endl;
        cin >> opcion;
        switch (opcion) {
            case 0:
                continuar = false;
                break;
            case 1:
                inventory->añadirPiedra();
                break;
            case 2:
                inventory->añadirLingotes();
                break;
            case 3:
                inventory->añadirDiamantes();
                break;
            case 4:
                inventory->añadirPalos();
                break;
            case 5:
                inventory->crearPicoPiedra();
                break;
            case 6:
                inventory->crearPicoHierro();
                break;
            case 7:
                inventory->crearPicoDiamante();
                break;
            case 8:
                inventory->ListarPicos();
                break;
            case 9:
                inventory->ListarPicos();
                inventory->mejorarPico();
                break;
            case 10:
                inventory->ListarBloques();
                break;
            case 11:
                inventory->añadirBloque();
                break;
            case 12:
                inventory->ListarBloques();
                inventory->romerBloque();
                break;
            default:
                cout << "Esa no es una opción válida..." << endl;
        }
    } while(continuar);
    delete inventory;
}

int main() {
    menu();
}
