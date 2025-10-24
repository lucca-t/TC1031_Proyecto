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


## Instrucciones para compilar el avance de proyecto

Ejecuta el siguiente comando en la terminal (nota: se agregó `bst_sismos.cpp`):

`g++ Analizador.h Sismo.h bst_sismos.h Analizador.cpp bst_sismos.cpp main.cpp -std=c++11 -o segundo_avance`

## Instrucciones para ejecutar el avance de proyecto

(Opcional) Encontré que correr este comando en la terminal ayuda a que muestre los acentos un mi máquina de Windows 10 por si no se visualiza:
(Encodings para texto es muy complicado)

`chcp 65001`

Ejecuta el siguiente comando en la terminal:

`./segundo_avance`

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
4.  Mostrar **todos los datos** (del vector original)
5.  Mostrar los sismos usando **BST (inorder, preorder, postorder)**
6.  **Salir** del programa

---

## Desarrollo de competencias

### SICT0301: Evalúa los componentes

#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

El análisis de complejidad de las operaciones principales es el siguiente:

* **Carga de Datos:** $O(n \log n)$ — Se recorre cada línea del archivo ($O(n)$). Por cada línea, se realiza una inserción en el `std::vector` (amortizado $O(1)$, total $O(n)$) y una inserción en el `BSTSismos`. La inserción en el BST tiene una complejidad promedio de $O(\log n)$, resultando en un tiempo total de carga de $O(n \log n)$ en el caso promedio. es poco probable que se degenere el árbol porque las magnitudes son desordenadas cuando los datos son agregados en el csv.
* **Ordenamiento (Merge Sort):** $O(n \log n)$ — Se utiliza para ordenar el vector por criterios distintos a la magnitud (fecha, profundidad).
* **Muestra de Datos (Vector):** $O(n)$ — El método `mostrarDatos` recorre el `std::vector` para imprimir los resultados.
* **Muestra de Datos (BST):** $O(n)$ — Los recorridos `inorder`, `preorder`, y `postorder` deben visitar cada uno de los $n$ nodos en el árbol.

### SICT0302: Toma decisiones

#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

Se utiliza **Merge Sort** (`mergeSort`) para ordenar la estructura `std::vector`. Se eligió este algoritmo por su complejidad garantizada de $O(n \log n)$ y su capacidad para recibir un **comparador** (`std::function`).
Esto permite reutilizar el mismo algoritmo para ordenar por magnitud, profundidad o fecha sin duplicar código.
Adicionalmente, el **BST** actúa como un algoritmo de ordenamiento *implícito*: mantiene los sismos ordenados por magnitud desde el momento de la inserción.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.

Este proyecto utiliza **dos estructuras de datos** principales para almacenar los objetos `Sismo`, cada una con un propósito específico:

1.  **`std::vector<Sismo>`:**
    * **Propósito:** Almacenar la lista original de sismos en el orden en que se leyeron y servir como estructura base para ordenamientos flexibles (por fecha, profundidad, etc.) usando Merge Sort.
    * **Uso:** Se llena con `push_back()`. Se consulta iterando sobre él (`mostrarDatos`). Se modifica con `ordenarPor()`.

2.  **`BSTSismos` (Árbol Binario de Búsqueda):**
    * **Propósito:** Almacenar los sismos en una estructura que los mantiene **permanentemente ordenados por magnitud**.
    * **Uso:** Se llena con `agregar()`. Se consulta usando recorridos (`inorder`, `preorder`, `postorder`).

### SICT0303: Implementa acciones científicas

#### Implementa mecanismos para consultar información de las estructuras correctos.

Se implementan dos tipos de mecanismos de consulta:

1.  **Para el Vector (`std::vector`):** El método `mostrarDatos(const std::string& titulo)` itera sobre el vector con un *range-based for loop* (`for (const auto& sismo : sismos)`) e invoca `sismo.imprimir()` para cada elemento.
2.  **Para el Árbol (`BSTSismos`):** Se implementaron los métodos `mostrarInorder()`, `mostrarPreorder()` y `mostrarPostorder()`. Estos métodos llaman a las funciones recursivas privadas correspondientes en la clase `BSTSismos` (`inorderRecursivo`, etc.). Estas funciones de recorrido construyen un `std::stringstream` con las magnitudes de los sismos en el orden solicitado.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.

El método `cargarDatos(const std::string& nombreArchivo)` implementa la carga de datos.
Utiliza `std::ifstream` para abrir el archivo y `std::getline` para leerlo línea por línea, omitiendo el encabezado.
Cada línea se procesa con `std::stringstream` para extraer los campos.
Por cada registro leído, el método instancia un `Sismo` y lo inserta en **ambas** estructuras de datos:
1.  En el vector, usando `sismos.push_back(Sismo(...))`
2.  En el árbol, usando `arbolSismos.agregar(nuevoSismo)`