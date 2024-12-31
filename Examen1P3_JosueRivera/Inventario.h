#include "Pico.h"
#include "Bloque.h"
#include <vector>
using namespace std;
class Inventario {
    private:
        int piedras = 0;
        int lingotesDeHierro = 0;
        int diamantes = 0;
        int palos = 0;
        vector<Pico*> picos;
        vector<Bloque*> bloques;
    public:
        Inventario();
        ~Inventario();
        void añadirPiedra();
        void añadirLingotes();
        void añadirDiamantes();
        void añadirPalos();
        void crearPicoPiedra();
        void crearPicoHierro();
        void crearPicoDiamante();
        void añadirBloque(); //ESTE METODO ES MAS COMO UN SUBMENU DEL BLOQUE QUE EL USUARIO QUIERA AÑADIR, GRACIAS A UN SWITCH SE LLAMAN OTROS METODOS COMO agregarObsidiana(), agregarOro(), agregarCarbon()
        void ListarPicos();
        void ListarBloques();
        void agregarObsidiana();
        void agregarOro();
        void agregarCarbon();
        void mejorarPico();
        void romerBloque();
};
