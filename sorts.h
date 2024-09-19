#ifndef SORTS_H
#define SORTS_H

#include <algorithm>
#include <iostream>
using namespace std;

template <class T>
class Sorts{
    private:
        void mergeArray(vector<T>&, vector<T>&, int, int, int);
        void copyArray(vector<T>&, vector<T>&, int, int);
    public:
        void swap(std::vector<T> &, int, int);
        void ordenaMerge(vector<T>&);
        void mergeSplit(vector<T> &, vector<T>&, int, int);
};

template <class T> //templates usan como plantilla para algoritmos
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
  T num = v[i];
  v[i] = v[j];
  v[j] = num;    //clase para cambiar un valor del arreglo con otra
};

template<class T>
void Sorts<T>::mergeArray(vector<T> &arreglo, vector<T> &arreglo2, int low, int mid, int high){
    int i = low; //valores para dividir arreglo
    int j = mid +1;
    int k = low;
    while (i <= mid &&j <= high) {
        if (arreglo[i] < arreglo[j]) {
            arreglo2[k++] = arreglo[i++];
        }else{
            arreglo2[k++] = arreglo[j++];
            }
        }
    while (i <= mid) { //copia elementos mitad
        arreglo2[k++] = arreglo[i++];
    }
    while (j <= high) { //copia elementos mitad
        arreglo2[k++] = arreglo[j++];
    }
}

template<class T>
void Sorts<T>::copyArray(vector<T>&arreglo, vector<T>&arreglo2, int low, int high){
    for (int i = low; i <= high; i++) {
        arreglo[i] = arreglo2[i];
    }
}

template <class T>
void Sorts<T>:: mergeSplit(vector<T> &arreglo, vector<T> &arreglo2, int low, int high){ //usa recursion
    if (low < high){ //caso base 
        int mitad = (high + low) / 2;

        mergeSplit(arreglo, arreglo2, low, mitad); //primera mitad
        
        mergeSplit(arreglo, arreglo2, mitad + 1, high); // segunda mitad
        
        mergeArray(arreglo, arreglo2, low, mitad, high);  //Fuciona arreglo
        
        copyArray(arreglo, arreglo2, low, high); //copiar a nuevo arreglo
    }
}

template <class T>
void Sorts<T>:: ordenaMerge( vector<T> &arreglo){
    vector<T> arreglo2(arreglo.size()); //crea un vectot para la copia
    int tamano = arreglo.size();
    mergeSplit(arreglo, arreglo2, 0, tamano - 1);
}

#endif
