#include <iostream>
#include <cstring>
#pragma once
using namespace std;
class Pico {
    private:
        string material;
        int vidaPico;
    public:
        Pico();
        Pico(string tipoMaterial, int vidaPico);
        ~Pico();
        void darMaterial(string tipoMaterial);
        void modificarVidaDelPico(int nuevaVida);
        int retornarVidaDelPico();
        string retornarMaterial();
        void mostrarInformacion();
};
