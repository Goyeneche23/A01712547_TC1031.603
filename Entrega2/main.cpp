#include "leer.h"
#include "Tonalidad.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    const char *filePath = "PruebasMusic.xml"; 

    leer<string> Leer; //iniciar clase
    
    Tonalidad tonalidad;     //iniciar clase tonalidad

    List<string> lista = Leer.extraerNotas(filePath);  // Extraer las notas del XML

    vector<int> CantidadNotas = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // Para contar las notas

    cout << "Notas extraídas: " <<endl;
    
    cout << lista.toString();   // Mostrar la lista de notas extraídas

    cout<<"Notas ordenadas de mayor a menor de uso:" <<endl;

    vector<int> notasOrdenadas;

    tonalidad.NotasOrdenadas(lista);   // Ordenar las notas

    tonalidad.ImprimirNotasOrdenadas(); //para pruebas
    tonalidad.ImprimirNotasYCantidad();//para pruebas

    return 0;
}