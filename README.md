# Proyecto: Analizador de Datos Sísmicos

Este proyecto es una herramienta de consola para analizar datos sísmicos. Permite cargar información de terremotos desde un archivo `.csv` y visualizar los datos ordenados por diferentes criterios como magnitud, profundidad o fecha.

## Descripción del avance 1

El programa carga un conjunto de datos de sismos desde un archivo `.csv`, crea un objeto `Sismo` por cada registro, y los almacena en una estructura de datos interna.
A través de un menú interactivo en consola, el usuario puede ordenar y mostrar los sismos más fuertes, más superficiales, más recientes, o ver todos los registros.
También es posible agregar nuevos sismos durante la ejecución.

## Descripción del avance 2
Escribe aquí la descripción de lo que contiene este avance. 



    
### Cambios sobre el primer avance
1. Escribe la lista de cambios realizados sobre el planteamiento original: Argumenta la razón por la que decidiste el cambio. Estos argumentos puedes retomarlos más adelante en tu argumentación de competencias.
2. Cambio 2: Razón del cambio
3. Cambio 3: Razón del cambio
4. etc...: etc...


## Instrucciones para compilar el avance de proyecto

Ejecuta el siguiente comando en la terminal:

`g++ Analizador.h Sismo.h Analizador.cpp main.cpp -std=c++11 -o analizador_sismico`

## Instrucciones para ejecutar el avance de proyecto

Ejecuta el siguiente comando en la terminal:

`./analizador_sismico`

## Descripción de las entradas del avance de proyecto

El programa solicita el nombre de un archivo `.csv` con los datos sísmicos.
Cada línea del archivo debe contener la información de un sismo en el siguiente formato:

`ID,FechaUTC,Latitud,Longitud,ProfundidadKM,Magnitud`

**Ejemplo de entrada:**


```
8,2025-07-30T18:25:00Z,52.08,159.65,25.0,8.8
9,2025-06-12T03:14:45Z,38.74,142.35,30.2,7.4
10,2025-11-02T13:47:22Z,4.12,96.02,15.0,6.8
```

Si el archivo no existe, el programa mostrará un mensaje de error y solicitará un nuevo nombre.

## Descripción de las salidas del avance de proyecto

El programa muestra en consola los resultados del análisis solicitado.
Las opciones disponibles en el menú son:

1. Mostrar los sismos más **fuertes** (ordenar por magnitud)
2. Mostrar los sismos más **superficiales** (ordenar por profundidad)
3. Mostrar los sismos más **recientes** (ordenar por fecha)
4. Mostrar **todos los datos** (sin ordenar, en el orden del archivo)
5. **Salir** del programa
Cada opción despliega los resultados en formato tabular directamente en la consola.

---

## Desarrollo de competencias

### SICT0301: Evalúa los componentes

#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

El algoritmo principal de ordenamiento es **Merge Sort**, seleccionado por su complejidad garantizada de $O(n \log n)$ en todos los casos.
El análisis de complejidad de las operaciones principales es el siguiente:

* **Carga de Datos:** $O(n)$ — Se recorre cada línea del archivo y se inserta al final del vector.
* **Ordenamiento (Merge Sort):** $O(n \log n)$ — División y fusión recursiva de los datos.
* **Muestra de Datos:** $O(n)$ — Se recorre la lista de sismos para imprimir los resultados.

Esto demuestra un análisis completo de las operaciones clave del programa y su desempeño.

### SICT0302: Toma decisiones

#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

Para almacenar los objetos `Sismo` se utilizó un **vector dinámico**, ya que permite acceso rápido a los elementos ($O(1)$) y facilita los algoritmos de ordenamiento por índice.
Para ordenar, se eligió **Merge Sort**, ya que garantiza un tiempo de ejecución estable de $O(n \log n)$ y una estructura modular que acepta un **comparador** como parámetro.
Esto permite reutilizar el mismo algoritmo para ordenar por magnitud, profundidad o fecha sin duplicar código.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.





### SICT0303: Implementa acciones científicas

#### Implementa mecanismos para consultar información de las estructuras correctos.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.