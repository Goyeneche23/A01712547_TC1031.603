# A01712547_TC1031.603
### Music sheet analyzer


#### Juan José Goyeneche Sánchez - A01712547

Descripcion proyecto
===============	

Este programa para la clase de Programación de estructuras de datos y algoritmos fundamentales tendra como objetivo crear un herramienta que analise piezas musicales. 


Se usara la aplicación de musescore para sacar las partituras para su posterior analisis, se extraera la partitura en forma de archivo de .XML y se importara al codigo, dentro del codigo para la lectura de estas
partituras se hara uso de la libreria TinyXML-2 (https://github.com/leethomason/tinyxml2), esta libreria esta hecha para leer archivos .XML.

#### Libreria "TinyXML2 
Usada para extraer los datos de un archivo .XML, haciendo uso de las funciones: 
FirstChildElement
NextSiblingElement
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
1. Escribe la lista de cambios realizados sobre el planteamiento original: Argumenta la razón por la que decidiste el cambio. Estos argumentos puedes retomarlos más adelante en tu argumentación de competencias.
2. Cambio 2: Razón del cambio
3. Cambio 3: Razón del cambio
4. etc...: etc...

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o primer_avance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./primer_avance` 

## Descripción de las entradas del avance de proyecto
Escribe aquí la descripción de las entradas del proyecto, por ejemplo, si de entrada se requieren varios archivos, hay que indicar el formato de cada uno de ellos, y proporcionar un ejemplo de los datos de cada archivo.

## Descripción de las salidas del avance de proyecto
Escribe aquí la descripción de los resultados de la ejecución de tu programa.

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
