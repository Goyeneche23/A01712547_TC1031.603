#ifndef TONALIDAD_H
#define TONALIDAD_H
#include <iostream>
#include <vector>
#include <algorithm> 
#include <utility>   // Para pair
#include "sorts.h"
#include <string>
#include "list.h"

using namespace std;

Sorts<pair<int, int>> sorts;

class Tonalidad{
    private: 

    public:
        Tonalidad() {
            Notas = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
            CantidadNotas = {0,0,0,0,0,0,0,0,0,0,0,0};
        }
        void UnirNotasCantidad();
        void NotasOrdenadas(List<string>& x);
        void Ordenamiento();
        void ContarNotas(List<string>&);
        void ImprimirNotasYCantidad();  
        void ImprimirNotasOrdenadas(); 
        vector<int> notasOrdenadas;
        vector<string> Notas;
        vector<pair<int, int>> NotasYCantidad;
        vector<int> CantidadNotas;
        
};

void Tonalidad::ContarNotas(List<string>& listaConNotas) {
    auto current = listaConNotas.head; // Empezar desde la cabeza de la lista enlazada
    while (current != nullptr) {
        if (current->value == "C") {
            CantidadNotas[0] += 1;
        } else if (current->value == "C#") {
            CantidadNotas[1] += 1;
        } else if (current->value == "D") {
            CantidadNotas[2] += 1;
        } else if (current->value == "D#") {
            CantidadNotas[3] += 1;
        } else if (current->value == "E") {
            CantidadNotas[4] += 1;
        } else if (current->value == "F") {
            CantidadNotas[5] += 1;
        } else if (current->value == "F#") {
            CantidadNotas[6] += 1;
        } else if (current->value == "G") {
            CantidadNotas[7] += 1;
        } else if (current->value == "G#") {
            CantidadNotas[8] += 1;
        } else if (current->value == "A") {
            CantidadNotas[9] += 1;
        } else if (current->value == "A#") {
            CantidadNotas[10] += 1;
        } else if (current->value == "B") {
            CantidadNotas[11] += 1;
        }
        current = current->next; // Avanzar al siguiente nodo
    }
}

void Tonalidad::UnirNotasCantidad(){
    NotasYCantidad.clear(); 
    for (int i = 0; i < CantidadNotas.size(); i++) {
        NotasYCantidad.push_back(make_pair(CantidadNotas[i], i));
    }
}

void Tonalidad::Ordenamiento(){
    sorts.ordenaMerge(NotasYCantidad);
}

void Tonalidad::NotasOrdenadas(List<string>& x) {
    ContarNotas(x);
    notasOrdenadas.clear();
    UnirNotasCantidad(); // Llena el vector de pares
    Ordenamiento(); // Ordena los pares
    for (int i = 0; i < NotasYCantidad.size(); ++i) {
        notasOrdenadas.push_back(NotasYCantidad[i].second); //Se toma el valor de la nota para ordenarlas en el vector ya como nota musical de la menos usada a la mas usada
    }
}
//para pruebas
void Tonalidad::ImprimirNotasYCantidad() {
    for (int i = 0; i < NotasYCantidad.size(); ++i) {
        cout << Notas[NotasYCantidad[i].second] << ": " << NotasYCantidad[i].first<<endl;
    }
}

// Función para imprimir notasOrdenadas para pruebas
void Tonalidad::ImprimirNotasOrdenadas() {
    for (int i = 0; i < notasOrdenadas.size(); ++i) {
        cout << Notas[notasOrdenadas[i]] << " ";
    }
    cout << endl;
}

#endif


