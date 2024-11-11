#include "Tonalidad.h"
#include "Escalas.h"
#include "leer.h"
#include "list.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    const char* filePath = "xmls/composition(Ddorico).xml";

    leer<string> Leer;
    Tonalidad tonalidad;
    Escalas escalas;

    List<string> lista = Leer.extraerNotas(filePath);

    tonalidad.NotasOrdenadas(lista);

    string tonoFinal = escalas.identificarEscala(tonalidad.notasOrdenadas);

    cout <<  tonoFinal << endl; 

    ofstream NotasExtraidas("codeMusic.txt");

    NotasExtraidas << "Notas totales extraidas:\n" << lista.toString() <<  endl;

    NotasExtraidas << "Notas ordenadas:\n" << tonalidad.ImprimirNotasOrdenadas() << endl;

    NotasExtraidas << "notas y cantidad\n" << tonalidad.ImprimirNotasCantidad() << endl;

    NotasExtraidas << "\n \n" << tonoFinal;

    NotasExtraidas.close();

    return 0;
}
