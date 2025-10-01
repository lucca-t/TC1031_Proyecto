# Analizador de Datos Sísmicos

Este proyecto es una herramienta de consola para analizar datos sísmicos. El programa carga un conjunto de datos de terremotos desde un archivo `.csv` y permite al usuario ordenar y visualizar la información según diferentes criterios, como la magnitud, la profundidad y la fecha del evento.

## Uso del Programa

Primero para compilar se necesita:
g++ main.cpp Analizador.cpp -o analizador_sismico

Y para correr se necesita correr:
.\analizador_sismico.exe

La interacción con el programa se realiza a través de un menú en la consola:

1.  **Inicio:** El programa pedirá el nombre del archivo de datos que deseas analizar
2.  **Carga de Datos:** El programa leerá el archivo, creará un objeto en memoria para cada sismo y los almacenará en una estructura de datos interna. Si el archivo no existe se mostrará un error.
3.  **Menú Interactivo:** Una vez cargados los datos, se mostrará un menú con las siguientes opciones:
    * `1. Mostrar los sismos más FUERTES (ordenar por magnitud)`
    * `2. Mostrar los sismos más SUPERFICIALES (ordenar por profundidad)`
    * `3. Mostrar los sismos más RECIENTES (ordenar por fecha)`  
    * `4. Mostrar todos los datos sin ordenar`
    * `5. Agregar datos de nuevo sismo `
    * `6. Salir`
4.  **Análisis:** Elige una opción numérica y el programa ordenará los datos según el criterio seleccionado y los mostrará en pantalla. Si se selecciono agregar datos se agregan en el formato adecuado.
5.  **Ciclo:** Después de mostrar los resultados, el menú volverá a aparecer, permitiéndote realizar otro análisis sin tener que recargar el archivo.
6.  **Salida:** Selecciona la opción `6` para finalizar el programa.

---

## SICT0302: Toma decisiones

### Selecciona y usa una estructura lineal adecuada al problema

Para almacenar los objetos `Sismo`, se utilizó un **arreglo dinámico (vector)**. Se eligió esta estructura por las siguientes razones:

* **Acceso Eficiente:** El programa se centra en ordenar y mostrar datos. Un vector ofrece acceso a sus elementos en tiempo constante $O(1)$, lo cual es ideal para iterar sobre los datos y para algoritmos de ordenamiento que requieren acceso por índice.
* **Caso de Uso:** Si se pueden insertar elementos, pero se hace muy poco en comparación con los ordenamientos y accesos al arreglo. Por lo tanto, la desventaja del vector en inserciones ($O(n)$) no es tan importante aquí.

El código que implementa esto se encuentra en la función de carga de datos, donde cada sismo leído del archivo `.csv` se agrega al final del vector.

### Selecciona un algoritmo de ordenamiento adecuado al problema

Para todas las opciones de ordenamiento (magnitud, profundidad y fecha), se seleccionó el algoritmo **Merge Sort**.

Es un algoritmo mas rápido que el Quick Sort en el peor caso porque tiene un peor caso de $O(n^2)$. **Merge Sort garantiza una complejidad de tiempo de $O(n \log n)$ en todos los casos**, lo que lo convierte en una opción más predecible para un conjunto de datos de tamaño desconocido.

La implementación es modular: se utiliza una única función `mergeSort` que acepta un **comparador** como parámetro. Esto permite reutilizar el mismo algoritmo para ordenar por magnitud, profundidad y fecha con solo cambier la regla de comparación.

---

## SICT0301: Evalúa los componentes

### Hace un análisis de complejidad correcto y completo para el programa y sus componentes

A continuación, se detalla el análisis de complejidad para las operaciones clave del programa, donde *n* es el número total de sismos en el conjunto de datos.

#### Carga de Datos (Lectura de archivo CSV)

* **Complejidad de Tiempo:** $O(n)$
* **Justificación:** El programa debe recorrer cada una de las *n* líneas del archivo una vez para procesarla y crear un objeto `Sismo`. La inserción al final de un vector es $O(1)$, por lo que la complejidad total está dominada por la longitud del archivo.

#### Ordenamiento de Sismos (Merge Sort)

* **Complejidad de Tiempo:** $O(n \log n)$
* **Justificación:** Esta es la complejidad de tiempo garantizada para Merge Sort en su peor, promedio y mejor caso, ya que divide el conjunto de datos de manera consistente hasta llegar a elementos individuales y luego los fusiona.
* **Complejidad de Espacio:** $O(n)$
* **Justificación:** Merge Sort es un algoritmo que no ordena "in-place". Requiere la creación de arreglos auxiliares para almacenar temporalmente las mitades del conjunto de datos durante el proceso de merging.

#### Muestra de Datos (Cualquier opción)

* **Complejidad de Tiempo:** $O(n)$
* **Justificación:** Con los datos ordenados o no ordenados, para mostrarlos en la consola es necesario iterar a través de toda la lista de *n* sismos e imprimir la información de cada uno.
