// Lucca Traslosheros Abascal
// A01713944
// Avance 2
// 23 de octubre de 2025

#ifndef ANALIZADOR_H
#define ANALIZADOR_H

#include <vector>
#include <string>
#include <functional>
#include "Sismo.h"
#include "bst_sismos.h"

// Clase para cargar, ordenar y mostrar datos de sismos
class Analizador {
private:
    // Guardar sismos 
    std::vector<Sismo> sismos;
    // Guardar en árbol
    BSTSismos arbolSismos;
    
    void merge(int l, int m, int r, std::function<bool(const Sismo&, const Sismo&)> comparador);
    void mergeSort(int l, int r, std::function<bool(const Sismo&, const Sismo&)> comparador);

public:
    
    bool cargarDatos(const std::string& nombreArchivo);
    void ordenarPor(std::function<bool(const Sismo&, const Sismo&)> comparador);
    void mostrarDatos(const std::string& titulo) const;
    int cantidadRegistros() const;
    std::string mostrarInorder() const;
    std::string mostrarPreorder() const;
    std::string mostrarPostorder() const;
};

#endif // ANALIZADOR_H
