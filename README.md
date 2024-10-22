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

####Leer.h
El proceso que se hara para extraer la partitura del archivo XML:
![image](https://github.com/user-attachments/assets/bffb8cc3-302e-4dc5-9226-5a9583930eee)

Tras validar que se puede leer el archivo validamos que este mismo tenga el elemento "score-partwise" que este contendra toda la partitura.

![image](https://github.com/user-attachments/assets/050e2145-4c02-4bb7-9bc1-2273f4af959e)

Tras esto se accedera a "measure" que se encuentra dentro de "part", esto para acceder y posteriormente ir iterando sobre los compases, tras esto se buscara "note" que contendra los valores de las notas, note es como el espacio en el que va una nota, pero como en este ejemplo si dentro de note se encuentra "rest" ignoraremos y pasaremos al siguiente porque rest significaria que es un silencio.



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
Este criterio lo emplee a mi parecer correctamente en este codigo, use el metodo de ordenamiento Merge porque tras lo aprendido en clase me parecio el que podria alcanzar una menor complejidad asi como tambien comparando con las necesidades de mi proyecto que es un simple ordenamiento de un vector me parecio el mas idoneo para realizar.
#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
Considero que durante el curso he desarrollado esta competencia, al poder entender de manera completa la logica detras de como funciona una lista y los distintos tipos existentes de estas, en mi codigo hice uso de una lista ligada simple, esto porque tras analizar el proyecto y las necesidades que tenia me di cuenta que solo necesitaria esta primera lista para extraer y almacenar datos del archivo externo por lo cual no ocuparia de momento una lista doblemente ligada, aunque para los proximos avances donde requiera de mas manipulacion de datos a la hora de comparar las escalas musicales usare otro tipo de listas.
### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Seleccione el algoritmo de ordenamiento sortMerge al ser un algoritmo que puede llegar a alcanzar una complejidad muy baja, el algoritmo esta en el archivo sort.h y tiene su uso y llamada en tonalidad.h
#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Seleccione el algoritmo de una lista ligada simple para esta primera lista en el programa, esto porque no requerrira de mucha manipulacion de datos por lo que los beneficios que te puede dar una lista ligada doble aun no son muy necesarios, esto cambiara cuando llegue al paso de hacer comparaciones de datos para descubrir la tonalidad de la cancion. El algoritmo se encuentra en list.h y se emplea en leer.h
### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
Escribe aquí tus argumentos sobre por qué consideras que has desarrrollado esta competencia y dónde se puede observar el desarrollo que mencionas.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
En el archivo de leer.h se puede apreciar como se realiza una extraccion de datos de un archivo template .XML ("PruebasMusic.xml") para su posterior almacenamiento en una lista ligada, esto se logra con el archivo TinyXML2 el cual es una herramienta que nos permitira hacer uso de funciones para encontrar ciertos elementos dentro del erchivo XML y luego al encontrar el "step" dentro de "pitch" se almacenara en una lista ligada para su posterior uso en el proyecto.
