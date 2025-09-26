// Lucca Traslosheros Abascal
// A01713944
// Avance 1
// 26 de septiembre de 2025


#ifndef SISMO_H
#define SISMO_H

#include <iostream>
#include <string>

// Guardar la info de los sismos. 
// Usar un struct porque solo es info que no cambia.
struct Sismo {
    // Atributos
    int id;
    std::string fecha_hora_utc;
    double latitud;
    double longitud;
    double profundidad_km;
    double magnitud;

    // Constructor para crear un objeto vacío.
    Sismo() = default;

    // Constructor para inicializar un sismo con todos sus datos.
    Sismo(int id, std::string fecha, double lat, 
        double lon, double prof, double mag)
        : id(id), fecha_hora_utc(fecha), latitud(lat), 
        longitud(lon), profundidad_km(prof), magnitud(mag) {}

    // Función para imprimir los datos del sismo.
    void imprimir() const {
        std::cout << "ID: " << id
                  << " | Fecha: " << fecha_hora_utc
                  << " | Magnitud: " << magnitud
                  << " | Profundidad: " << profundidad_km << " km" << std::endl;
    }

};

#endif // SISMO_H