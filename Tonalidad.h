#ifndef TONALIDAD_H
#define TONALIDAD_H
#include "sorts.h"
#include "ListasTonos.h"
#include <utility> //pair
#include <vector>
#include <string>
#include <list>

using namespace std;


vector<string> Notas = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"}; //Para convertir a strings las notas
//                       0    1     2    3     4    5    6     7     8    9    10    11

vector<int> CantidadNotas = {8, 4, 3, 1, 2, 4, 0, 6, 0, 1, 0, 9}; //Ejemplo Provisional de como quedaria el vector tras contar notas de partitura

Sorts<pair<int, int>> sorts; //Se usara la funcion "pair" y se toma solo el primer valor para los sorts (a menos que hayan dos valoresw iguales)

class NotasMasUsadas{
    private: 
        vector<pair<int, int>> NotasYCantidad; //Unir el conteo con su nota correspondiente, para evitar que tras el sort se pierda a que nota pertenece cada valor

    public:
        void UnirNotasCantidad(vector<int>& CantidadNotas); //ciclo para la union notas representadas con numeros)

        vector<int>NotasOrdenadas(vector<int>& CantidadNotas); //Vector ya con el orden de las notas que mas aparecen

        void Ordenamiento(); //se usa el sort merge para el primer valor de NotasYCantidad
};


void NotasMasUsadas::UnirNotasCantidad(vector<int>& CantidadNotas){
    NotasYCantidad.clear();
    for (int i = 0; i < CantidadNotas.size(); i++) {
        NotasYCantidad.push_back(make_pair(CantidadNotas[i], i));
    }
}// Luego se convertiran a string las notas 0    1     2    3     4    5    6     7     8    9    10    11

void NotasMasUsadas::Ordenamiento(){
    sorts.ordenaMerge(NotasYCantidad);
}

vector<int>NotasMasUsadas::NotasOrdenadas(vector<int>& CantidadNotas){ //"main"
    UnirNotasCantidad(CantidadNotas); 
    Ordenamiento();
}
/*class EncontrarTonalid{
    
}*/
#endif
