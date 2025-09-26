# Analizador de Datos Sísmicos

Este proyecto es una herramienta de consola para analizar datos sísmicos. El programa carga un conjunto de datos de terremotos desde un archivo `.csv` y permite al usuario ordenar y visualizar la información según diferentes criterios, como la magnitud, la profundidad y la fecha del evento.

## Uso del Programa

La interacción con el programa es sencilla y se realiza a través de un menú en la consola:

1.  **Inicio:** Al ejecutar el programa, te pedirá el nombre del archivo de datos que deseas analizar (por ejemplo, `sismos.csv`).
2.  **Carga de Datos:** El programa leerá el archivo, creará un objeto en memoria para cada sismo y los almacenará en una estructura de datos interna. Si el archivo no se encuentra o tiene un formato incorrecto, mostrará un error.
3.  **Menú Interactivo:** Una vez cargados los datos, se mostrará un menú con las siguientes opciones:
    * `1. Mostrar los sismos más FUERTES (ordenar por magnitud)`
    * `2. Mostrar los sismos más SUPERFICIALES (ordenar por profundidad)`
    * `3. Mostrar los sismos más RECIENTES (ordenar por fecha)`  
    * `4. Mostrar todos los datos sin ordenar`
    * `5. Salir`
4.  **Análisis:** Elige una opción numérica y presiona `Enter`. El programa ordenará los datos según el criterio seleccionado y los mostrará en pantalla.
5.  **Ciclo:** Después de mostrar los resultados, el menú volverá a aparecer, permitiéndote realizar otro análisis sin necesidad de recargar el archivo.
6.  **Salida:** Selecciona la opción `5` para finalizar el programa.

---

## SICT0302: Toma decisiones

### Selecciona y usa una estructura lineal adecuada al problema

Para almacenar los objetos `Sismo`, se utilizó un **arreglo dinámico (vector)**. Se eligió esta estructura por las siguientes razones:

* **Acceso Eficiente:** El programa se centra en ordenar y mostrar datos. Un vector ofrece acceso a sus elementos en tiempo constante $O(1)$, lo cual es ideal para iterar sobre los datos y para algoritmos de ordenamiento que requieren acceso por índice.
* **Caso de Uso:** Las operaciones de inserción o eliminación de elementos individuales no son un requisito del programa; los datos se cargan una sola vez al inicio. Por lo tanto, la desventaja del vector en inserciones ($O(n)$) no es relevante aquí, y su ventaja en acceso lo hace más adecuado que una lista enlazada.

El código que implementa esto se encuentra en la función de carga de datos, donde cada sismo leído del archivo `.csv` se agrega al final del vector.

### Selecciona un algoritmo de ordenamiento adecuado al problema

Para todas las opciones de ordenamiento (magnitud, profundidad y fecha), se seleccionó el algoritmo **Merge Sort**.

La elección se justifica por su rendimiento y fiabilidad. Aunque otros algoritmos como Quick Sort son rápidos en el caso promedio, su rendimiento puede degradarse a $O(n^2)$ en el peor de los casos (por ejemplo, con datos ya ordenados). **Merge Sort garantiza una complejidad de tiempo de $O(n \log n)$ en todos los casos** (peor, promedio y mejor), lo que lo convierte en una opción más robusta y predecible para un conjunto de datos de tamaño desconocido.

La implementación es modular: se utiliza una única función `mergeSort` que acepta un **comparador** como parámetro. Esto permite reutilizar el mismo algoritmo para ordenar por magnitud (comparando números flotantes), profundidad (comparando enteros) y fecha (comparando objetos de fecha/hora) simplemente cambiando la regla de comparación.

---

## SICT0301: Evalúa los componentes

### Hace un análisis de complejidad correcto y completo para el programa y sus componentes

A continuación, se detalla el análisis de complejidad para las operaciones clave del programa, donde *n* es el número total de sismos en el conjunto de datos.

#### Carga de Datos (Lectura de archivo CSV)

* **Complejidad de Tiempo:** $O(n)$
* **Justificación:** El programa debe recorrer cada una de las *n* líneas del archivo una vez para procesarla y crear un objeto `Sismo`. La inserción al final de un vector (amortizada) es $O(1)$, por lo que la complejidad total está dominada por la lectura del archivo.

#### Ordenamiento de Sismos (Merge Sort)

* **Complejidad de Tiempo:** $O(n \log n)$
* **Justificación:** Esta es la complejidad de tiempo garantizada para Merge Sort en su peor, promedio y mejor caso, ya que divide el conjunto de datos de manera consistente hasta llegar a elementos individuales y luego los fusiona.
* **Complejidad de Espacio:** $O(n)$
* **Justificación:** Merge Sort es un algoritmo que no ordena "in-place". Requiere la creación de arreglos auxiliares para almacenar temporalmente las mitades del conjunto de datos durante el proceso de fusión. En el peor de los casos, este espacio adicional es proporcional al tamaño del conjunto de datos original.

#### Muestra de Datos (Cualquier opción)

* **Complejidad de Tiempo:** $O(n)$
* **Justificación:** Ya sea que los datos estén ordenados o no, para mostrarlos en la consola es necesario iterar a través de toda la lista de *n* sismos e imprimir la información de cada uno.

---

## SICT0303: Implementa acciones científicas

### Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa

El programa implementa un mecanismo de carga de datos desde un archivo con formato de valores separados por comas (`.csv`), un estándar común para conjuntos de datos. Al iniciar, solicita al usuario el nombre del archivo, lo que lo hace flexible para analizar diferentes fuentes de datos sísmicos sin necesidad de modificar el código.

### Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa

El programa ofrece una interfaz de usuario clara y funcional a través de un menú interactivo. Este menú actúa como un sistema de consulta que permite al usuario aplicar filtros de ordenamiento de manera repetida y eficiente. Las opciones (`1. Por Magnitud`, `2. Por Profundidad`, `3. Por Fecha`) son consultas directas que transforman los datos brutos en información ordenada y útil para el análisis.