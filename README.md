# A01712547_TC1031.603
### Music sheet analyzer


#### Juan José Goyeneche Sánchez - A01712547

Descripcion proyecto
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


## Descripción del avance 2
Este avance busca hacer uso de las listas, esto se puede ver como al extraer las notas de la partitura del arvhivo XML haciendo uso de la herramiento TinyXML2 estas notas se almacenan en una lista ligada haciendo uso de los codigos realizados en clase. 


### Cambios sobre el primer avance
1. main.cpp: El main.cpp ya tiene implementado un llamado a funciones para realizar pruebas y evaluar el avance.
2. leer.h: El mayor cambio fue la implementacion de leer.h este archivo hace uso de tinyXML2 para leer el archivo de texto y extraer los elementos que ocupamos para desglosar las partituras.
3. list.h: El codigo mayormente desarrollado en las clases, se usara dentro de leer.h para guardar todas las notas en una lista ligada.
4. contarNotas(): Dentro de Tonalidad.h se crea la funcion contarNotas que ayuda al ordenamiento de estas, haciendo uso de la lista ligada de una manera no muy practica pasa la informacion a un vector con el cual se trabajara para el analisis y ordenamiento.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o primer_avance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./primer_avance` 

## Descripción de las entradas del avance de proyecto
Este programa funcionara a partir del input = "PruebasMusic.xml", un archivo .xml extraido de musescore. 

## Descripción de las salidas del avance de proyecto
Este programa por el momento mostrara el progreso del codigo el cual sera mostrar todas las notas extraidas del archivo XML (archivo pequeño),asi como tambien en orden ascendente las notas que mas se repiten en la partitura y tambien la cantidad de veces que se repiten.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Si lograste este criterio en el primer avance, copia aquí tu argumentación. Si no, ésta es una nueva oportunidad para lograrlo. Escribe aquí tu aprendizaje y tus argumentos sobre por qué consideras que ahora ya has desarrrollado este criterio y dónde se puede observar el desarrollo que mencionas.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
Escribe aquí tus argumentos sobre por qué consideras que has desarrrollado esta competencia y dónde se puede observar el desarrollo que mencionas.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Si lograste este criterio en el primer avance, copia aquí tu argumentación. Si no, ésta es una nueva oportunidad para lograrlo. Escribe aquí tu aprendizaje y tus argumentos sobre por qué consideras que ahora ya has desarrrollado este criterio y dónde se puede observar el desarrollo que mencionas.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Escribe aquí tus argumentos sobre por qué consideras que has desarrrollado esta competencia y dónde se puede observar el desarrollo que mencionas.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
Escribe aquí tus argumentos sobre por qué consideras que has desarrrollado esta competencia y dónde se puede observar el desarrollo que mencionas.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Escribe aquí tus argumentos sobre por qué consideras que has desarrrollado esta competencia y dónde se puede observar el desarrollo que mencionas.
