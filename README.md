# A01712547_TC1031.603
### Music sheet analyzer


#### Juan José Goyeneche Sánchez - A01712547


OPCION 1 (prioridad)
===============	

Este programa para la clase de Programación de estructuras de datos y algoritmos fundamentales tendra como objetivo crear un herramienta que analise piezas musicales. 


Se usara la aplicación de musescore para sacar las partituras para su posterior analisis, se extraera la partitura en forma de archivo de .XML y se importara al codigo, dentro del codigo para la lectura de estas
partituras se hara uso de la libreria TinyXML-2 (https://github.com/leethomason/tinyxml2), esta libreria esta hecha para leer archivos .XML.



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


![image](https://github.com/user-attachments/assets/c98b15e8-e782-4fde-bc69-118f083a40ac)


Se hara el uso de la libreria <Utility> que cuenta con la funcion pair(https://www.geeksforgeeks.org/pair-in-cpp-stl/), que nos ayudara para evitar una problematica tras realizar el Sort, con la funcion pair antes de ordenar asignaremos a todo valor de cantidad su nota correspondiente y tras esto podremos realizar el ordenamiento.

OPCION 2 (alternativa)
===============	

Este programa para la clase de Programación de estructuras de datos y algoritmos fundamentales tendra como objetivo la creación, desglose o identificación de acordes en base a ciertos inputs dados por el usuario.
Esto en caso de que el manejo de archivos de .xml sea muy compleja.

Tambien podria ser una opcion agregada a la opcion 1.
