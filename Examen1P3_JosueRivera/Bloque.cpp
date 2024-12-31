#include "Bloque.h"

Bloque::Bloque() {
}
Bloque::~Bloque() {
}
void Bloque::indicarMaterial(string material) {
    materialBloque = material;
}
void Bloque::indicarTiempo(float tiempo) {
    tiempoEnRomper = tiempo;
}
void Bloque::indicarDurabilidad(int duracion) {
    durabilidad = duracion;
}
int Bloque::retornarDurabilidad() {
    return durabilidad;
}
float Bloque::retornarTiempo() {
    return tiempoEnRomper;
}
void Bloque::mostrarInformacion() {
    cout << "Material: " << materialBloque << ", Durabilidad: " << durabilidad << ", Tiempo en romperse: " << tiempoEnRomper << endl;
}
string Bloque::retornarMaterial() {
    return materialBloque;
}
