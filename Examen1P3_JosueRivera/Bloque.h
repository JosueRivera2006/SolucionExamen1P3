#include <iostream>
#include <cstring>
#pragma once
using namespace std;
class Bloque {
    private:
        string materialBloque;
        int durabilidad;
        float tiempoEnRomper;
    public:
        Bloque();
        ~Bloque();
        void mostrarInformacion();
        void indicarMaterial(string material);
        void indicarDurabilidad(int duracion);
        string retornarMaterial();
        void indicarTiempo(float tiempo);
        int retornarDurabilidad();
        float retornarTiempo();
};
