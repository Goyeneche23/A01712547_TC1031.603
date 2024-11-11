#ifndef TONALIDAD_H
#define TONALIDAD_H
//Mejor caso: O(nlogn)  Caso Promedio: O(nlogn)  Peor Caso: O(nlogn)
#include <iostream>
#include <vector>
#include <algorithm> 
#include <sstream>
#include <cstdlib>
#include <utility>   
#include "sorts.h"
#include <string>
#include "list.h"

using namespace std;

class Tonalidad{
    private: 
    Sorts<pair<int, int>> sorts;

    public:
        Tonalidad() {
            Notas = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
            CantidadNotas = {0,0,0,0,0,0,0,0,0,0,0,0};
        }
        void UnirNotasCantidad(); //Mejor: O(n)     Promedio: O(n)      Peor: O(n)
        void NotasOrdenadas(List<string>& x); //Mejor: O(n log n)     Promedio: O(n log n)      Peor: O(n log n)
        void Ordenamiento(); //Mejor: O(n log n)     Promedio: O(n log n)       Peor: O(n log n)
        void ContarNotas(List<string>&); //Mejor: O(n)     Promedio: O(n)      Peor: O(n)
        void LimpiarVector(); //Mejor: O(n)     Promedio: O(n)     Peor: O(n)
        void VerificarNotas(); //Mejor: O(n)     Promedio: O(n)      Peor: O(n)

        string ImprimirNotasCantidad();  //Mejor: O(n)      Promedio: O(n)      Peor: O(n)
        string ImprimirNotasOrdenadas();  //Mejor: O(n)    Promedio: O(n)      Peor: O(n)

        vector<int> notasOrdenadas;
        vector<string> Notas;
        vector<pair<int, int>> NotasYCantidad;
        vector<int> CantidadNotas;
        
};

void Tonalidad::ContarNotas(List<string>& listaConNotas) {

    auto current = listaConNotas.head; // empezar desde cabeza de lista enlazada

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
        current = current->next; // Avanzar a siguiente nodo
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
    UnirNotasCantidad(); // Llena vector de pares
    Ordenamiento(); // Ordena pares

    for (int i = 0; i < NotasYCantidad.size(); i++) {
        notasOrdenadas.push_back(NotasYCantidad[i].second); //Se toma el valor de la nota para ordenarlas en el vector ya como nota musical de la menos usada a la mas usada
    }
    LimpiarVector();
    VerificarNotas();
}

void Tonalidad::VerificarNotas(){

    int notasVacias = 0;

    for (int i = 0; i < NotasYCantidad.size(); i++){
        if (NotasYCantidad[i].first == 0 ){
            notasVacias +=1;
        }
    }if (notasVacias > 5){
            cout << "Notas Insuficientes para analisis" << endl;
            exit(0);
        }
}

void Tonalidad::LimpiarVector(){

    auto first = notasOrdenadas.begin();

    auto last = notasOrdenadas.end() -7;

    notasOrdenadas.erase(first, last);
}


//para pruebas
string Tonalidad::ImprimirNotasCantidad() {
    stringstream aux;

    for (int i = 0; i < NotasYCantidad.size(); i++) {
        aux << Notas[NotasYCantidad[i].second] << ": " << NotasYCantidad[i].first << endl;
    }
    return aux.str();
}

// para imprimir notas ordenadas para pruebas
string Tonalidad::ImprimirNotasOrdenadas() {
    stringstream aux;
    
    for (int i = 0; i < notasOrdenadas.size(); i++) {
        aux << Notas[notasOrdenadas[i]] << " |     ";
        aux << notasOrdenadas[i] << endl;
    }
    aux << endl;
    return aux.str();
}

#endif
