#ifndef ESCALAS_H_
#define ESCALAS_H_
//Mejor caso: O(nlogn)  Caso Promedio: O(nlogn)  Peor Caso: O(nlogn)
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

struct Scale {
    vector<int> notes;
    string nombre;
};

class Escalas {

    private:
        vector<Scale> scale;

    public:
        Escalas(); //Mejor: O(1)  Promedio: O(1)  Peor: O(1)  

        string identificarEscala(vector<int>& notasOrdenadas); //Mejor: O(1)  Promedio: O(nlogn)  Peor: O(nlogn)
        int ajustarBucleNotas(int nota, int dominante); //Mejor: O(1)  Promedio: O(1)  Peor: O(1)
        //string imprimirEscala(vector<int>& tone);
        vector<int> ordenarSobreDominante(vector<int>& notasOrdenadasCantidad); //Mejor: O(nlogn)  Promedio: O(nlogn)  Peor: O(nlogn)
        void ajustarPatron(vector<int>& escala); //Mejor: O(n)  Promedio: O(n)  Peor: O(n)
        bool compararNotas(int a, int b, int dom); //Mejor: O(1)  Promedio: O(1)  Peor: O(1)
        string convToString(int x); //Mejor: O(1)  Promedio: O(1)  Peor: O(1)
};

// Constructor: inicializa los patrones de escalas en el mapa
Escalas::Escalas() {

    scale.push_back(Scale{{0, 2, 4, 5, 7, 9, 11}, "Escala Mayor"});
    scale.push_back(Scale{{0, 2, 3, 5, 7, 8, 10}, "Escala Menor"});
    scale.push_back(Scale{{0, 2, 3, 5, 7, 8, 11}, "Escala Menor Armonica"});
    scale.push_back(Scale{{0, 2, 3, 5, 7, 9, 11}, "Escala Menor Melodica"});
    scale.push_back(Scale{{0, 2, 3, 5, 7, 9, 10}, "Escala Dorica"});
    scale.push_back(Scale{{0, 1, 3, 5, 7, 8, 10}, "Escala Frigia"});
    scale.push_back(Scale{{0, 2, 4, 6, 7, 9, 11}, "Escala Lidia"});
    scale.push_back(Scale{{0, 2, 4, 5, 7, 9, 10}, "Escala Mixolidia"});
    scale.push_back(Scale{{0, 1, 3, 5, 6, 8, 10}, "Escala Locria"});
    scale.push_back(Scale{{0, 2, 3, 6, 7, 9, 11}, "Escala Doble Armonica"});
    scale.push_back(Scale{{0, 2, 4, 5, 7, 8, 11}, "Escala Menor Húngara"});
    scale.push_back(Scale{{0, 2, 4, 5, 7, 8, 10}, "Escala Hindu"});
    scale.push_back(Scale{{0, 1, 4, 5, 7, 8, 11}, "Escala Flamenca"});
}
// Funcion para identificar la escala a partir del vector de notas ordenadas
string Escalas::identificarEscala(vector<int>& notasOrdenadas) 
{
    stringstream aux;   

    int dominantNote = notasOrdenadas.back();
    string notaDominant = convToString(dominantNote);
    vector<int> tone = ordenarSobreDominante(notasOrdenadas);
    
    ajustarPatron(tone);

    aux << "Vector de notas normalizado: ";
    for (int i = 0;  i < tone.size(); i++) {

        aux << tone[i] << " ";
    }
    aux << endl;

    for (auto i = scale.begin(); i != scale.end(); i++) {

        vector<int> pattern = i->notes; 
        string scaleName = i->nombre;  

        if (pattern == tone) {
            aux << "La escala identificada es: " + scaleName + " de " + notaDominant;
            return aux.str();
        }
    }
    return "Escala desconocida";
}

vector<int> Escalas::ordenarSobreDominante(vector<int>& notasOrdenadasCantidad){

    int dominante = notasOrdenadasCantidad.back(); //devuelve el valor mas usado de la partitura (nota dominante)
    auto inicio = notasOrdenadasCantidad.begin();
    auto fin = notasOrdenadasCantidad.end(); //para hacer mas legible el sort

    //este es un sort personalizado para que ordene con la condicion que queremos
    sort(inicio, fin, [&dominante, this](int a, int b) { //comparara 2 notas del vector pero no el numero en si, el resultados tras usar funcion ajustarBucleNotas 
    
        return compararNotas(a, b, dominante);
    });

    return notasOrdenadasCantidad;
}

int Escalas::ajustarBucleNotas(int nota, int dominante){

    int distancia = nota - dominante; //distancia entre nota y nota dominante
    // Ajustar a una cantidad que sea valida para nota 0 - 11
    //en caso de ser negativo distancia deveulve el residuo lo cual sirve para hacer 0 - 11 un "bucle"
    return (distancia + 12) % 12;  // ej. 2 - 4 = -2; -2 + 12 = 10; ej2. 5 - 1 = 4; + 12 = 16 % 12 = 16 - 12 = 4;
}

bool Escalas::compararNotas(int a, int b, int dominante) {

    return ajustarBucleNotas(a, dominante) < ajustarBucleNotas(b, dominante);
}

void Escalas::ajustarPatron(vector<int>& escala){//ajusta para que la escala de el patron de saltos que hace sin importar las notas

    int dominante = escala[0];

    for (int i = 0; i < escala.size(); i++) {//bucle para restar los saltos de la nota dominante a cada nota

        escala[i] = (escala[i] - dominante + 12) % 12;
    }
}

string Escalas::convToString(int nota){ //Convertir nota para asegurar que vaya de 0-11

    string notaString[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

    return notaString[nota];  
}
/*
string Escalas::imprimirEscala(vector<int>& tone){
    stringstream aux;
    for (int i = 0;  i < tone.size(); i++) {
        aux << tone[i] << " ";
    }
    aux << endl;

    return aux.str();
}
*/
#endif
