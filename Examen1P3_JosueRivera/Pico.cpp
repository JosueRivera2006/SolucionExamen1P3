#include "Pico.h"
Pico::Pico() {
}
Pico::Pico(string tipoMaterial, int durabilidad) {
    material = tipoMaterial;
    vidaPico = durabilidad;
}
Pico::~Pico() {
}
void Pico::mostrarInformacion() {
    cout << "Pico de " << material << " con una durabilidad de: " << vidaPico << endl;
}
void Pico::modificarVidaDelPico(int nuevaVida) {
    vidaPico = nuevaVida;
}
void Pico::darMaterial(string tipoMaterial) {
    material = tipoMaterial;
}
int Pico::retornarVidaDelPico() {
    return vidaPico;
}
string Pico::retornarMaterial() {
    return material;
}
