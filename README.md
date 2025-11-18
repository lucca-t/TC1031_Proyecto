# Proyecto: Analizador de Datos Sísmicos

Este proyecto es una herramienta de consola para analizar datos sísmicos. Permite cargar información de terremotos desde un archivo `.csv` y visualizar los datos ordenados por diferentes criterios como magnitud, profundidad o fecha.

## Descripción del avance 1

El programa carga un conjunto de datos de sismos desde un archivo `.csv`, crea un objeto `Sismo` por cada registro, y los almacena en una estructura de datos interna (un vector).
A través de un menú interactivo en consola, el usuario puede ordenar y mostrar los sismos más fuertes, más superficiales, más recientes, o ver todos los registros.

## Descripción del avance 2
Para este avance, se integró una segunda estructura de datos: un **Árbol Binario de Búsqueda (BST)**.
Ahora, al cargar los datos desde el `.csv`, cada sismo se almacena simultáneamente en dos estructuras:
1.  Un `std::vector` (como en el avance 1) para permitir ordenamientos flexibles (por fecha, profundidad, etc.).
2.  Un `BSTSismos` (el nuevo BST), que **ordena automáticamente los sismos por magnitud** conforme se insertan.

Se agregó una nueva opción al menú para mostrar los recorridos del BST (inorder, preorder, postorder), demostrando un método alternativo de almacenamiento y consulta de datos.

### Cambios sobre el primer avance
1.  **Nueva Estructura de Datos (BST):** Se implementaron `bst_sismos.h` y `bst_sismos.cpp` para crear un Árbol Binario de Búsqueda que almacena objetos `Sismo`.
    * **Razón:** Para demostrar el uso de una estructura de datos no lineal (árbol) y sus ventajas para mantener los datos ordenados automáticamente por un criterio (magnitud).
2.  **Doble Carga de Datos:** `Analizador::cargarDatos` fue modificado para insertar cada sismo tanto en el `std::vector` como en el `BSTSismos`.
    * **Razón:** Para mantener la flexibilidad del vector (necesaria para ordenar por fecha o profundidad) y, al mismo tiempo, tener una vista permanentemente ordenada por magnitud gracias al BST.
3.  **Nuevas Funciones en `Analizador`:** Se añadieron los métodos `mostrarInorder()`, `mostrarPreorder()` y `mostrarPostorder()`.
    * **Razón:** Para exponer las funciones de consulta del nuevo BST al `main.cpp`.
4.  **Actualización del Menú Principal:** Se añadió la opción 5 y se movió "Salir" a la opción 6.
    * **Razón:** Para permitir al usuario interactuar con la nueva estructura de datos BST.


## Descripción del avance 3
Para este avance final, se expandió la funcionalidad del programa para cumplir con las competencias. El enfoque fué en corregir los errores previos, y agregar funcionalidad para aprovechar del BST. 

1.  **Búsqueda Rápida en BST:** Se implementó una función de búsqueda (`buscarSismoPorMagnitud`) que utiliza la naturaleza ordenada del `BSTSismos` para encontrar sismos por magnitud en tiempo promedio $O(\log n)$.
2.  **Escritura de Archivos:** Se implementó una función (`guardarDatos`) que permite al usuario guardar el estado actual del `std::vector` (con el último ordenamiento aplicado) en un nuevo archivo `.csv`.


### Cambios sobre el segundo avance
1.  **Nueva Función de Búsqueda en `BSTSismos`:** Se añadieron `buscarPorMagnitud` (pública) y `buscarRecursivo` (privada) a `bst_sismos.h` y `bst_sismos.cpp`.
    * **Razón:** Para demostrar el beneficio principal de un BST (búsqueda $O(\log n)$) y justificar su uso más allá de ser solo un método de ordenamiento (abordando SICT0302).
2.  **Nueva Función de Guardado en `Analizador`:** Se añadió `guardarDatos` a `Analizador.h` y `Analizador.cpp`.
    * **Razón:** Para cumplir con la competencia "Implementa mecanismos de escritura de archivos" (SICT0303), demostrando cómo iterar sobre el vector ($O(n)$) para persistir los datos.
3.  **Actualización del Menú Principal:** Se añadieron las opciones 6 ("Guardar") y 7 ("Buscar por Magnitud") al `main.cpp`, moviendo "Salir" a la opción 8.
    * **Razón:** Para exponer las nuevas funcionalidades al usuario final.
4.  **Revisión Completa del Análisis de Competencias:** Se reescribió la sección `Desarrollo de competencias` para incluir un análisis de complejidad detallado (Mejor, Promedio, Peor Caso) para cada estructura y operación, justificando las decisiones de diseño (SICT0302) con base en este análisis (SICT0301).


## Instrucciones para compilar el avance de proyecto

Ejecuta el siguiente comando en la terminal:

`g++ Analizador.h Sismo.h bst_sismos.h Analizador.cpp bst_sismos.cpp main.cpp -std=c++11 -o tercer_avance`

## Instrucciones para ejecutar el avance de proyecto

(Opcional) Encontré que correr este comando en la terminal ayuda a que muestre los acentos un mi máquina de Windows 10 por si no se visualiza:
(Encodings para texto es muy complicado)

`chcp 65001`

Ejecuta el siguiente comando en la terminal:

`./tercer_avance`

## Descripción de las entradas del avance de proyecto

El programa solicita el nombre de un archivo `.csv` con los datos sísmicos.
Cada línea del archivo debe contener la información de un sismo en el siguiente formato:

`ID,FechaUTC,Latitud,Longitud,ProfundidadKM,Magnitud`

**Ejemplo de entrada:**

```
ID,FechaUTC,Latitud,Longitud,ProfundidadKM,Magnitud 
8,2025-07-30T18:25:00Z,52.08,159.65,25.0,8.8 
9,2025-06-12T03:14:45Z,38.74,142.35,30.2,7.4 
10,2025-11-02T13:47:22Z,4.12,96.02,15.0,6.8
```
 
Si el archivo no existe, el programa mostrará un mensaje de error y solicitará un nuevo nombre.

## Descripción de las salidas del avance de proyecto

El programa muestra en consola los resultados del análisis solicitado.
Las opciones disponibles en el menú son:

1.  Mostrar los sismos más **fuertes** (ordenar por magnitud)
2.  Mostrar los sismos más **superficiales** (ordenar por profundidad)
3.  Mostrar los sismos más **recientes** (ordenar por fecha)
4.  Mostrar **todos los datos**
5.  Mostrar los sismos usando **BST (inorder, preorder, postorder)**
6.  **Guardar** datos ordenados a un archivo
7.  **Buscar** sismo por Magnitud (BST)
8.  **Salir** del programa

---

## Desarrollo de competencias

### SICT0301: Evalúa los componentes

#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

A continuación, se detalla el análisis de complejidad para las estructuras de datos y las operaciones clave del programa, donde **n** es el número total de sismos en el conjunto de datos.

**Estructura 1: `std::vector<Sismo> sismos`**
* **Operación: Carga de Datos (`cargarDatos` -> `sismos.push_back`)**
    * **Mejor Caso:** $O(1)$ (amortizado).
    * **Caso Promedio:** $O(1)$ (amortizado).
    * **Peor Caso:** $O(n)$. Ocurre cuando el vector se llena y necesita reasignar memoria, copiando todos los *n* elementos existentes a una nueva ubicación.
* **Operación: Ordenamiento (`ordenarPor` -> `mergeSort`)**
    * **Mejor Caso:** $O(n \log n)$.
    * **Caso Promedio:** $O(n \log n)$.
    * **Peor Caso:** $O(n \log n)$.
    * **Justificación:** Se analiza en la sección de algoritmos.
* **Operación: Muestra y Escritura (`mostrarDatos`, `guardarDatos`)**
    * **Mejor Caso:** $O(n)$.
    * **Caso Promedio:** $O(n)$.
    * **Peor Caso:** $O(n)$.
    * **Justificación:** Se debe iterar sobre los *n* elementos del vector para imprimirlos o guardarlos en el archivo.

**Estructura 2: `BSTSismos arbolSismos` (BST ordenado por Magnitud)**
* **Operación: Carga de Datos (`cargarDatos` -> `arbolSismos.agregar`)**
    * **Mejor Caso:** $O(\log n)$. Ocurre si el árbol está balanceado.
    * **Caso Promedio:** $O(\log n)$. Ocurre si los datos de magnitud (la clave) se insertan en un orden aleatorio, manteniendo el árbol razonablemente balanceado.
    * **Peor Caso:** $O(n)$. Ocurre si el árbol degenera en una lista ligada (ej. si los sismos se insertan ya ordenados por magnitud, de menor a mayor o viceversa).
* **Operación: Recorridos (`mostrarInorder`, `mostrarPreorder`, `mostrarPostorder`)**
    * **Mejor Caso:** $O(n)$.
    * **Caso Promedio:** $O(n)$.
    * **Peor Caso:** $O(n)$.
    * **Justificación:** Independientemente de la forma del árbol (balanceado o degenerado), un recorrido completo debe visitar cada uno de los *n* nodos exactamente una vez.
* **Operación: Búsqueda (`buscarSismoPorMagnitud`)**
    * **Mejor Caso:** $O(1)$. Ocurre si la magnitud buscada se encuentra en el nodo raíz.
    * **Caso Promedio:** $O(\log n)$. Ocurre en un árbol balanceado, donde cada comparación descarta la mitad de los nodos restantes.
    * **Peor Caso:** $O(n)$. Ocurre si el árbol está degenerado en una lista y la magnitud buscada es el último elemento (o no existe).

#### Análisis de complejidad de Algoritmos de Ordenamiento

* **Algoritmo 1: Merge Sort (`mergeSort` en `Analizador.cpp`)**
    * **Mejor Caso:** $O(n \log n)$.
    * **Caso Promedio:** $O(n \log n)$.
    * **Peor Caso:** $O(n \log n)$.
    * **Justificación:** Merge Sort es un algoritmo consistente. Siempre divide el arreglo en dos mitades y luego las fusiona. La división toma $O(\log n)$ niveles, y la fusión en cada nivel toma $O(n)$ tiempo.
* **Algoritmo 2: Ordenamiento Implícito (Inserción en `BSTSismos`)**
    * **Justificación:** El BST actúa como un algoritmo de ordenamiento *implícito*. Al insertar *n* elementos, el costo total es:
    * **Mejor/Promedio Caso (Total):** $O(n \log n)$. (Son *n* inserciones, cada una con costo $O(\log n)$).
    * **Peor Caso (Total):** $O(n^2)$. (Son *n* inserciones, cada una con costo $O(n)$ en un árbol degenerado).

---

### SICT0302: Toma decisiones

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.

Este proyecto utiliza **dos estructuras de datos** principales para almacenar los objetos `Sismo`, ya que ninguna estructura por sí sola resolvía todos los requisitos de manera óptima. La selección se basa en el análisis de complejidad (SICT0301):

1.  **`std::vector<Sismo>`:**
    * **Decisión:** Se usa como almacén principal y para ordenamientos flexibles (fecha, profundidad).
    * **Justificación (basada en análisis):** Su operación `push_back` tiene una complejidad amortizada de $O(1)$, permitiendo una carga de datos inicial muy rápida. Es la estructura de datos ideal para ser ordenada por un algoritmo como **Merge Sort** ($O(n \log n)$), que ofrece el mejor rendimiento garantizado para ordenamientos flexibles.
    * **Debilidad (Trade-off):** Su búsqueda lineal en datos desordenados es $O(n)$ (lenta), y por eso se complementa con el BST.

2.  **`BSTSismos` (Árbol Binario de Búsqueda):**
    * **Decisión:** Se usa para mantener una vista de los datos **permanentemente ordenada por magnitud** y para permitir búsquedas rápidas por esta clave.
    * **Justificación:**
        * **Ordenamiento implícito:** Aunque la carga total tiene un costo promedio de $O(n \log n)$ (igual que Merge Sort), mantiene los datos ordenados en todo momento.
        * **Funcionalidad nueva:** Permite la búsqueda por magnitud (`buscarSismoPorMagnitud`) con una complejidad promedio de **$O(\log n)$**. Esto es mucho más rápido que el $O(n)$ que requeriría buscar en el vector.
    * **Debilidad (Trade-off):** El peor caso de ($O(n)$) y búsqueda ($O(n)$) es malo, pero los datos leidos normalmente son aleatorios así que asumimos que el promedio ($O(\log n)$) será el promedio de complejidad.

#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

* **Algoritmo 1: Merge Sort**
    * **Decisión:** Se utiliza para ordenar el `std::vector` por criterios de fecha y profundidad.
    * **Justificación (basada en análisis):** Se eligió sobre otros algoritmos (como Quick Sort) por su **garantía de complejidad**. Merge Sort tiene un rendimiento de $O(n \log n)$ en *todos los casos* (mejor, promedio y peor). Esto lo hace más predecible y seguro que Quick Sort, cuyo peor caso es $O(n^2)$.
* **Algoritmo 2: BST (Inserción)**
    * **Decisión:** Se utiliza para el ordenamiento por magnitud.
    * **Justificación (basada en análisis):** La inserción en el BST (`agregarRecursivo`) es un algoritmo de ordenamiento en sí mismo. Su caso promedio de $O(\log n)$ por inserción lo hace una alternativa eficiente al Merge Sort para *un* criterio de ordenamiento fijo.

---

### SICT0303: Implementa acciones científicas

#### Implementa mecanismos para consultar información de las estructuras correctos.

Se implementan tres tipos de mecanismos de consulta:

1.  **Vector (Iteración $O(n)$):** El método `mostrarDatos(const std::string& titulo)` itera sobre el vector con un *range-based for loop* (`for (const auto& sismo : sismos)`) e invoca `sismo.imprimir()` para cada elemento.
2.  **Árbol (Recorridos $O(n)$):** Se implementaron los métodos `mostrarInorder()`, `mostrarPreorder()` y `mostrarPostorder()`. Estos métodos llaman a las funciones recursivas privadas correspondientes en la clase `BSTSismos` (`inorderRecursivo`, etc.) para visitar todos los nodos.
3.  **Árbol (Búsqueda $O(\log n)$ promedio):** Se implementó `buscarSismoPorMagnitud` que llama a `buscarRecursivo`. Esta función utiliza la propiedad del BST (menores a la izquierda, mayores a la derecha) para descartar recursivamente la mitad del árbol en cada paso, logrando una búsqueda eficiente.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.

El método `cargarDatos(const std::string& nombreArchivo)` implementa la carga de datos.
Utiliza `std::ifstream` para abrir el archivo y `std::getline` para leerlo línea por línea, omitiendo el encabezado.
Cada línea se procesa con `std::stringstream` para extraer los campos.
Por cada registro leído, el método instancia un `Sismo` y lo inserta en **ambas** estructuras de datos:
1.  En el vector, usando `sismos.push_back(Sismo(...))`
2.  En el árbol, usando `arbolSismos.agregar(nuevoSismo)`

#### Implementa mechanisms de escritura de archivos para guardar los datos de las estructuras de manera correcta.

* Se implementó el método `guardarDatos` en la clase `Analizador`.
* Este método utiliza `std::ofstream` para abrir y escribir en un nuevo archivo `.csv`.
* Itera sobre el `std::vector sismos` (que retiene el último ordenamiento aplicado por el usuario) y escribe cada objeto `Sismo` en una nueva línea con formato CSV.
* La complejidad de esta operación es $O(n)$, ya que debe visitar cada sismo en el vector una vez.