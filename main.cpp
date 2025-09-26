// Lucca Traslosheros Abascal
// A01713944
// Avance 1
// 26 de septiembre de 2025

#include <iostream>
#include <limits>
#include "Analizador.h"

void mostrarMenu() {
    std::cout << "\n¿Qué te gustaría hacer?\n"
              << "1. Mostrar los sismos más FUERTES (ordenar por magnitud)\n"
              << "2. Mostrar los sismos más SUPERFICIALES (ordenar por profundidad)\n"
              << "3. Mostrar los sismos más RECIENTES (ordenar por fecha)\n"
              << "4. Mostrar todos los datos\n"
              << "5. Salir\n"
              << "Elige una opción: ";
}

int main() {
    Analizador analizador;
    std::string nombreArchivo;

    std::cout << "Bienvenido al Analizador de Datos Sísmicos.\n";
    std::cout << "Por favor, escribe el nombre del archivo CSV: ";
    std::cin >> nombreArchivo;

    if (!analizador.cargarDatos(nombreArchivo)) {
        return 1; // Por si falla
    }
    
    std::cout << "Datos cargados. Se encontraron " << analizador.cantidadRegistros() << " registros.\n";
    
    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;

        // Limpia el buffer si falla
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcion = 0; // Muestra error
        }

        switch (opcion) {
            case 1: { // Ordena por magnitud de mayor a menor.
                auto porMagnitud = [](const Sismo& a, const Sismo& b) {
                    return a.magnitud > b.magnitud;
                };
                analizador.ordenarPor(porMagnitud);
                analizador.mostrarDatos("Sismos ordenados por Mayor Magnitud");
                break;
            }
            case 2: { // Ordena por profundidad de menor a mayor.
                auto porProfundidad = [](const Sismo& a, const Sismo& b) {
                    return a.profundidad_km < b.profundidad_km;
                };
                analizador.ordenarPor(porProfundidad);
                analizador.mostrarDatos("Sismos ordenados por Menor Profundidad");
                break;
            }
            case 3: { // Ordena por fecha de más reciente a más antigua.
                auto porFecha = [](const Sismo& a, const Sismo& b) {
                    return a.fecha_hora_utc > b.fecha_hora_utc;
                };
                analizador.ordenarPor(porFecha);
                analizador.mostrarDatos("Sismos ordenados por Fecha (recientes primero)");
                break;
            }
            case 4: {
                analizador.mostrarDatos("Todos los datos");
                break;
            }
            case 5:
                std::cout << "Análisis terminado. ¡Adiós!\n";
                break;
            default:
                std::cout << "Opción no válida. Intenta de nuevo.\n";
                break;
        }
    } while (opcion != 5);

    return 0;
}