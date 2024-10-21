#ifndef LEER_H
#define LEER_H

#include "list.h"
#include "tinyxml2.h"
#include <iostream>
#include <map>
#include <string>
using namespace tinyxml2;
using namespace std;

template <class T> class leer;

template<class T>
class leer{
  private:
    map<string, string> bemolToSostenido;
  
  public:
    List<T> extraerNotas(const char*);

};

map<string, string> bemolToSostenido = {
    {"A", "G#"}, // A♭ -> G#
    {"B", "A#"}, // B♭ -> A#
    {"D", "C#"}, // D♭ -> C#
    {"E", "D#"}, // E♭ -> D#
    {"G", "F#"}  // G♭ -> F#
};

//measure = compas
//pitch = info de nota (alter y step)
//step = nota
//Alter = 1 = # y -1 =bemol
//rest = silencio
//octave = agudeza o altura de nota (no se tomara en cuenta)

template<class T>
List<T> leer<T>::extraerNotas(const char *x){
  XMLDocument doc;
  List<string> listaNotas;

    // Cargar el archivo XML
    if (doc.LoadFile(x) != 0) {
      cerr << "Error al cargar XML" << endl;
      return listaNotas;
    }

    // Verificar si es una partitura
    XMLElement *root = doc.FirstChildElement("score-partwise");
    if (!root) {
      cerr << "Error formato" << endl;
      return listaNotas;
    }

    // Iterar sobre las medidas
    XMLElement *measure = root->FirstChildElement("part")->FirstChildElement("measure");
  
    while (measure) {
      XMLElement *nota = measure->FirstChildElement("note");

      // Iterar sobre las notas
      while (nota) {
        // Asegurarse de que no sea un silencio (rest)
        XMLElement *rest = nota->FirstChildElement("rest");
        if (nota != rest) {
          // Extraer la información de la nota
          XMLElement *pitch = nota->FirstChildElement("pitch");//busca pitch dentro d nota
          if (pitch) {
            XMLElement *step =pitch->FirstChildElement("step");//busca step dentro de pitch
            XMLElement *alter = pitch->FirstChildElement("alter");//busca alter dentro de pitch

            if (step) {
              string stepS = step->GetText();

              // Verificar si la nota tiene una alteración
              if (alter) {
                string alterS = (alter->GetText());
                if (alterS == "1") {
                  stepS += "#"; // Sostenido
                } else if (alterS == "-1") {
                  // Convertir bemol a su equivalente sostenido
                    stepS = bemolToSostenido[stepS];
                }
              }// almcacenar nota
              listaNotas.insertion(stepS);
            }
          }
        }//pasar a siguiente nota
        nota = nota->NextSiblingElement("note"); 
      }//pasar a siguiente compas
      measure = measure->NextSiblingElement("measure");
    }
  return listaNotas;
}

#endif