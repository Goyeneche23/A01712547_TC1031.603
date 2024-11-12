# A01712547_TC1031.603
### Music sheet analyzer


#### Juan José Goyeneche Sánchez - A01712547

Descripcion proyecto | Complexity = O(nlogn)
===============	

Este programa para la clase de Programación de estructuras de datos y algoritmos fundamentales tendra como objetivo crear un herramienta que analise piezas musicales. 


Se usara la aplicación de musescore para sacar las partituras para su posterior analisis, se extraera la partitura en forma de archivo de .XML y se importara al codigo, dentro del codigo para la lectura de estas
partituras se hara uso de la libreria TinyXML-2 (https://github.com/leethomason/tinyxml2), esta libreria esta hecha para leer archivos .XML.

#### Libreria "TinyXML2 by Lee Thomason
Usada para extraer los datos de un archivo .XML, haciendo uso de las funciones: 

FirstChildElement
![image](https://github.com/user-attachments/assets/35f01c71-a3a2-499c-bb06-851a3822f339)

NextSiblingElement
![image](https://github.com/user-attachments/assets/b5287d98-a255-442e-bfed-c847a966736c)

(https://github.com/leethomason/tinyxml2)

##### Vector Cantidades
Se hara uso de una funcion que cuente las cantidad de veces que se repite una nota en la pieza musical. Esto se podria hacer con un ciclo y condicionante que sume cada vez que se encuentre la nota, se puede hacer uso de las funciones de busqueda vistas en clase como la busqueda secuencial.



##### Tonalidades/Escalas
Una de las principales utilidades que dara el codigo seria el encontrar Tonalidades. Para esto primero habra una función que cree un vector que almacene la cantidad de veces que se repite cada nota en base al vector principal de la partitura dada. Esto despues pasara por una funcion Sort (Merge) para enontrar las notas que mas se repiten en las partituras, y en base a las que mas se repiten podremos hayar la escala y tonalidad en la que se encuentre la pieza musical haciendo la comparación con las tablas de escalas que estaran declaradas en vectores.
(Las notas se usaran numeros del 0 al 11 para representarlas, hasta el final se hara la conversion a strings para mayor practicidad)


###### EJemplo
Ejemplo (64, 0, 57,  4,  30, 15,  2,  29,  1,  18,  0,  8)   --> Vector Creado para contar Notas


Notas   ( C, C#, D,  D#,  E,  F,  F#,  G,  G#,  A,  A#, B)


<br>


Sort    (0,  0,  1,  2,  4,  8, 15,  18,  29, 30,  57, 64)


Notas   (A#, C#, G#, F#, D#, B,  F,   A,   G,  F,   D,  C)   --> Ordenamiento de notas que mas se repiten(MERGE)


<br>


VectorC (1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1)                --> Comparando las notas que mas se repiten con los vectores de escalas declarados se encuentra la similitud.


C Mayor (C, D, E, F, G, A, B)  

<br>

![image](https://github.com/user-attachments/assets/c98b15e8-e782-4fde-bc69-118f083a40ac)

<br>

Se hara el uso de la libreria <Utility> que cuenta con la funcion pair(https://www.geeksforgeeks.org/pair-in-cpp-stl/), que nos ayudara para evitar una problematica tras realizar el Sort, con la funcion pair antes de ordenar asignaremos a todo valor de cantidad su nota correspondiente y tras esto podremos realizar el ordenamiento.

####Leer.h
El proceso que se hara para extraer la partitura del archivo XML:
![image](https://github.com/user-attachments/assets/bffb8cc3-302e-4dc5-9226-5a9583930eee)

Tras validar que se puede leer el archivo validamos que este mismo tenga el elemento "score-partwise" que este contendra toda la partitura.

![image](https://github.com/user-attachments/assets/050e2145-4c02-4bb7-9bc1-2273f4af959e)

Tras esto se accedera a "measure" que se encuentra dentro de "part", esto para acceder y posteriormente ir iterando sobre los compases, tras esto se buscara "note" que contendra los valores de las notas, note es como el espacio en el que va una nota, pero como en este ejemplo si dentro de note se encuentra "rest" ignoraremos y pasaremos al siguiente porque rest significaria que es un silencio.

![image](https://github.com/user-attachments/assets/31b99301-bf32-4bfe-b017-391ab66218ac)

En caso de que no sea un silencio significaria que existira un "pitch" y dentro de este habra la informacion de "step" que nos dara la nota existente (en caso de ser sostenida o bemol se representara en otra variable "alter"). Step se ligara a la lista.

Solo funcionara con clave de Sol*



## Descripción del avance 2
Este avance busca hacer uso de las listas, esto se puede ver como al extraer las notas de la partitura del arvhivo XML haciendo uso de la herramiento TinyXML2 estas notas se almacenan en una lista ligada haciendo uso de los codigos realizados en clase. 


### Cambios sobre el primer avance
1. main.cpp: El main.cpp ya tiene implementado un llamado a funciones para realizar pruebas y evaluar el avance.
2. leer.h: El mayor cambio fue la implementacion de leer.h este archivo hace uso de tinyXML2 para leer el archivo de texto y extraer los elementos que ocupamos para desglosar las partituras.
3. list.h: El codigo mayormente desarrollado en las clases, se usara dentro de leer.h para guardar todas las notas en una lista ligada.
4. contarNotas(): Dentro de Tonalidad.h se crea la funcion contarNotas que ayuda al ordenamiento de estas, haciendo uso de la lista ligada de una manera no muy practica pasa la informacion a un vector con el cual se trabajara para el analisis y ordenamiento.



## Descripción del avance 3
El Avance 3 termina el codigo almenos los objetivos planteados al principio para este, se logra con el archivo Escalas.h hacer uso del vector con las notas ordenadas que ya teniamos para ordenarlas sobre la nota dominante: 

Ejemplo: 
    Notas Ordenadas= [D, E, C ,F, G#, B, A] ? [2, 4, 0, 5, 8, 11, 9]
    NotaDominante = ultima nota de Notas Ordenadas = A = 9
    OrdenadasSobreDominante = [A, B, C, D, E, F,G#] = [9, 11, 0, 2, 4, 5, 8]

Tras esto lo que se decidio hacer para iterar sobre los vectores de listasa ordenadas que tendriamos fue iterar sobre patrones y no sobre notas. La opcion mas simple hubiera sido almacenar todas las escalas posibles e iterar sobre estas con el vector de las notas OrdenadaSobreDominante hasta encontrar coencidencia pero la complejidad hubiera sido exponencial, luego surgio la idea de hacer uso de un arbol Hash o Merkle con las 11 notas como inicios de arboles para que la complejidad baje a O(n) y se vaya siguiendo un camino hasta llegar al nombre de la nota pero seguiriamos con el mismo problema de almacenar muchas "listas" de escalas musicales (esta idea hubiera ignorado las escalas con saltos de tonos y medioS) por lo cual se opto por analizar los patrones (saltos) de la escala y no la escala como tal esto se tendra siempre que ordenar sobre 0.

Ejemplo:
    OrdenadasSobreDominante = [A, B, C, D, E, F,G#] = [9, 11, 0, 2, 4, 5, 8]
    ajustadaSobreZero = [0, 2, 3, 5, 7, 8, 11] = Escala Menor Armonica.
    Esto se itera sobre la lista de escalas que tenemos y se regresa el nombre de la escala.
    Resultado = Scale + notaDominante = Escala Menor Armonica de A.

Para todo este proceso se hace uso de varias funciones especiales:

1.- Sort:

    sort(inicio, fin, [&dominante, this](int a, int b) { //comparara 2 notas del vector pero no el numero en si, el resultados tras usar funcion ajustarBucleNotas 
            return compararNotas(a, b, dominante); //This, clausula de captura para acceder a funcion no estatica
        });

Una cláusula de captura vacía, [ ], indica que el cuerpo de la expresión lambda no tiene acceso a ninguna variable en el ámbito de inclusión.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
    bool Escalas::compararNotas(int a, int b, int dominante) {
        return ajustarBucleNotas(a, dominante) < ajustarBucleNotas(b, dominante);
    }

Ej. 
    Si el vector que se le da es {5, 6, 4, 3, 2, 0, 1} el cual seria empezaria desde 5 = inicio a 1 = fin y la dominante seria 1, tras estor iterara por todo el sort asignando valores de a y b a cada numeros seleccionados en la iteracion: 
    
It1:    Comparación entre 5 y 6:
        distanciaCiclica(5, 1) = 4
        distanciaCiclica(6, 1) = 5
        Como 4 < 5, 5 va antes que 6.
It2:    Comparación entre 5 y 4:
        distanciaCiclica(5, 1) = 4
        distanciaCiclica(4, 1) = 3
        Como 4 > 3, 4 va antes que 5.
It3:    Comparación entre 5 y 3:
        distanciaCiclica(5, 1) = 4
        distanciaCiclica(3, 1) = 2
        Como 4 > 2, 3 va antes que 5.

Y se repite este proceso hasta ordenar todas las notas, la diferencia aqui es que se hace la comparacion no con el valor de los numeros si no con el valor de la distancia que tienen con la dominante y si es true se eraliza el cambio en caso de que se falso no.
----------------------------------------------------------------------------------------------------------------------------------------------

2.- Ajuste

    int Escalas::ajustarBucleNotas(int nota, int dominante){
        int distancia = nota - dominante; //distancia entre nota y nota dominante
     
        return (distancia + 12) % 12;  
    }

(distancia + 12) % 12;  Esta funcion se hace para que la nota 12 que en todo caso seria un C2 se tome como un C y siempre se trabaje sobre un bucle de 0 - 11, aunque esto tmb se pudo haber resuelto con un vector, me parecio que seria mas facil hacer operaciones matematicas y manipular las notas de esta manera.

Ej.
         5 - 1 = 4; + 12 = 16 % 12 = 16 - 12 = 4;


### Cambios sobre el segundo avance
1. Modificar archivo Tonalidad.h
2. Crear archivo Escalas.h y devolver la escala de la cancion.
3. Analisis de complejidad para cada funcion del codigo.
4. Extraccion del archivo de Txt con la informacion de la partitura
5. Link a una pagina creada en la cual puede crear archivos xml para luego ser analizada por el code
6. Solucionar errores previos.
7. Espaciados para una mejor legibilidad del codigo.



## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp tinyxml2.cpp -o programa` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./programa` 

## Descripción de las entradas del avance de proyecto
Este programa funcionara a partir del input = "PruebasMusic.xml", un archivo .xml extraido de musescore. 

## Descripción de las salidas del avance de proyecto
Este programa por el momento mostrara el progreso del codigo el cual sera mostrar todas las notas extraidas del archivo XML (archivo pequeño),asi como tambien en orden ascendente las notas que mas se repiten en la partitura y tambien la cantidad de veces que se repiten.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Este criterio lo emplee a mi parecer correctamente en este codigo, use el metodo de ordenamiento Merge porque tras lo aprendido en clase me parecio el que podria alcanzar una menor complejidad asi como tambien comparando con las necesidades de mi proyecto que es un simple ordenamiento de un vector me parecio el mas idoneo para realizar.
#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
Considero que durante el curso he desarrollado esta competencia, al poder entender de manera completa la logica detras de como funciona una lista y los distintos tipos existentes de estas, en mi codigo hice uso de una lista ligada simple, esto porque tras analizar el proyecto y las necesidades que tenia me di cuenta que solo necesitaria esta primera lista para extraer y almacenar datos del archivo externo por lo cual no ocuparia de momento una lista doblemente ligada, aunque para los proximos avances donde requiera de mas manipulacion de datos a la hora de comparar las escalas musicales usare otro tipo de listas.
#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
En cada funcion del programa al declarar las funciones y constructores de las clases se escribe como comentario un analisis de complejidad que incluye tanto el mejor caso, caso promedio y peor caso de cada funcion y luego al final un analisis general de cada clase (archivo). Y uno finalel cual de todo el codigo general seria de O(nlogn), lo cual en mi opinion es una complejidad aceptable tomando encuenta que en este problema se requiere mucho de la manipulación, ordenamiento y comparación de datos.
![image](https://github.com/user-attachments/assets/5bfe89d7-b1ec-42dc-9b2f-387fab698c4b)


### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Seleccione el algoritmo de ordenamiento sortMerge al ser un algoritmo que puede llegar a alcanzar una complejidad muy baja, el algoritmo esta en el archivo sort.h y tiene su uso y llamada en tonalidad.h
#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Seleccione el algoritmo de una lista ligada simple para esta primera lista en el programa, esto porque no requerrira de mucha manipulacion de datos por lo que los beneficios que te puede dar una lista ligada doble aun no son muy necesarios, esto cambiara cuando llegue al paso de hacer comparaciones de datos para descubrir la tonalidad de la cancion. El algoritmo se encuentra en list.h y se emplea en leer.h.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
En este codigo se hacen uso de varios metodos para consultar informacion dentro de una estructura de dato: .back(); funcion search(); y se hizo uso de ir iterando el root de la lista ligada por toda la lista de notas. 

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


#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
En el archivo de leer.h se puede apreciar como se realiza una extraccion de datos de un archivo template .XML ("PruebasMusic.xml") para su posterior almacenamiento en una lista ligada, esto se logra con el archivo TinyXML2 el cual es una herramienta que nos permitira hacer uso de funciones para encontrar ciertos elementos dentro del erchivo XML y luego al encontrar el "step" dentro de "pitch" se almacenara en una lista ligada para su posterior uso en el proyecto.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
Se hace uso de stringstream para que ciertas funciones devuelvan en formato de string deseado y tras esto en el main se hace uso de ofstream para crear un archivo de texto llamada "codeMusic.txt" donde todas las funciones string que dan el resultado se llaman y se almacenan ahí.

________________________________________________

## Referencias

"(https://www.w3schools.com/cpp/cpp_structs.asp)"

"(https://www.freecodecamp.org/espanol/news/c-map-explicado-con-ejemplos/)"

"(https://github.com/leethomason/tinyxml2)"

"(ChatGPT, 2024)"

"(https://godbolt.org/)"

"(https://www.geeksforgeeks.org/lambda-expression-in-c/)"
