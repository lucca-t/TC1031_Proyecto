#ifndef ANALIZADOR_H
#define ANALIZADOR_H

#include <vector>
#include <string>
#include <functional>
#include "Sismo.h"

// Clase para cargar, ordenar y mostrar datos de sismos
class Analizador {
private:
    // Guardar sismos 
    std::vector<Sismo> sismos;

    void merge(int l, int m, int r, std::function<bool(const Sismo&, const Sismo&)> comparador);
    void mergeSort(int l, int r, std::function<bool(const Sismo&, const Sismo&)> comparador);

public:
    
    bool cargarDatos(const std::string& nombreArchivo);
    void ordenarPor(std::function<bool(const Sismo&, const Sismo&)> comparador);
    void mostrarDatos(const std::string& titulo) const;
    int cantidadRegistros() const;
};

#endif // ANALIZADOR_H