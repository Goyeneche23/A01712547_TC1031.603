#ifndef LIST_H
#define LIST_H
//Mejor caso: O(1)  Caso Promedio: O(n)  Peor Caso: O(n)
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template <class T> class List;
//plantilla para que List funcione con cualquier tipo de dato
template <class T>
class Link {

    public:
        Link(T); //inicializa nodo  
        Link(T, Link<T>*); 
        Link( Link<T>&);//constructor copia

        T value;
        Link<T> *next;

        friend class List<T>; //le permite a la class link acceder a los atributos pribados de Link
};

template <class T>
Link<T>::Link(T val) { //inicializa nodo 
    value = val;
    next = NULL;
}

template <class T>
Link<T>::Link(T val, Link* nxt) { //inicializa nodo y puntero al siguiente nodo
    value = val;
    next = nxt;
}

template <class T>
Link<T>::Link( Link<T> &source) {//crea nuevo nodo a partir de copia
    value = source.value;
    next = source.next;
}

template <class T>
class List {
public:
    List(); //inicializa MEjor: O(1)     Promedio: O(1)      Peor: O(1) 
    ~List(); //destrctor MEjor: O(1)      Promedio: O(n)      Peor: O(n) 

    void addFirst(T); //MEjor: O(1)     Promedio: O(1)      Peor: O(1) 
    void insertion(T); //MEjor: O(1)      Promedio: O(n)      Peor: O(n) 
    int search(T) ; //MEjor: O(1)      Promedio: O(n)       Peor: O(n)  
    bool update(int, T); //MEjor: O(1)     Promedio: O(n)      Peor: O(n) 
    bool deleteAt(int);  //MEjor: O(1)     Promedio: O(n)      Peor: O(n) 
    std::string toString() ; //MEjor: O(1)     Promedio: O(n)      Peor: O(n) 
    bool empty () ; //MEjor: O(1)     Promedio: O(1)      Peor: O(1)
    int size;
    Link<T> *head;
};

template <class T>
bool List<T>::empty() { //revisa si la lista tiene algun numero
    if (size == 0) {
        return true;
    }else{
        return false;
        }
}

template <class T>
List<T>::List() {//inicializa la lista vacia
    head = NULL;
    size = 0;
}

template <class T>
List<T>::~List() {//para destruir las listas

    while (head != NULL) {
        Link<T> *victim = head;
        head = victim->next;
        delete victim;
        size = size -1;
    }
}

template <class T>
void List<T>::insertion(T val) {
    if (empty()) {//en caso de ser una lista vacia se hara con la funcion addFirst
        addFirst(val);
    } else {
        Link<T> * nuevo_nodo = new Link<T>(val);

        if (nuevo_nodo == NULL) {
            cout << "OutOfMemory" << endl;//en caso de que falte memoria
        }

        Link<T> * nodo_actual = head;
        while (nodo_actual->next != NULL) { //Recorrer hasta que el siguiente puntero de valor sea nulo
            nodo_actual = nodo_actual->next;//recorre hasta el final de la lista
        }

        nodo_actual->next = nuevo_nodo; //la lista ahora apunta alk nuevo nodo en lugar de a un null
        size++; //el tamaño aumenta 1
    }
}


template <class T>
void List<T>::addFirst(T val) {
    Link<T> * nuevo_nodo = new Link<T>(val);

    if(nuevo_nodo == NULL) {
        cout << "OutOfMemory"<< endl;//en caso de que falte memoria
    }
    if (empty()) {
        head = nuevo_nodo;

    } else {

        nuevo_nodo->next = head;

        head = nuevo_nodo;
    }
    size++;
}


template <class T>
int List<T>::search(T val)  {//itera por la lista para revisar si existe el valor val
    Link<T> *current = head;
    int index = 0;
    while (current != NULL) {
        if (current->value == val) {
            return index;
        }
                index++;
        current = current->next;
    }
    return -1;  //no se encontro el valor buscado
}

template <class T>
bool List<T>::update(int index, T val) {
    if (index < 0 || index >= size) {
        return false;  
    }
    Link<T> *current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;//se buscara la posicion dada
    }
    current->value = val;//el nuevo vlor se indexara en la posicion del bucle
    return true;
}

template <class T>
bool List<T>::deleteAt(int index) {
    if (index < 0 || index >= size) {
        return false; 
    }
    if (index == 0) {//para el primer valor
        Link<T> *victim = head;
        head = head->next;
        delete victim;
    } else {
        Link<T> *current = head;
        for (int i = 0; i < index - 1; ++i) {//se busca la posicion del index
            current = current->next;
        }
        Link<T> *victim = current->next;//proceso de eliminacion de lo que este en ese valor
        current->next = victim->next;
        delete victim;
    }
    size--;//ajustar tamaño
    return true;
}

template <class T>
std::string List<T>::toString()  {
    std::stringstream aux;
    Link<T> *current = head;
    aux << "[";
    while (current != NULL) {
        aux << current->value;
        if (current->next != NULL) {
            aux << ", ";
        }
        current = current->next;
    }
    aux << "]";
    return aux.str();
}

#endif 
