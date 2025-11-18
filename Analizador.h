/*
    Lucca Traslosheros Abascal
    A01713944
    Analizador.h
    Avance 3
    17 de noviembre de 2025
*/


#ifndef ANALIZADOR_H
#define ANALIZADOR_H

#include <vector>
#include <string>
#include <functional>
#include <fstream>
#include <fstream>       
#include "Sismo.h"
#include "bst_sismos.h"

// Clase para cargar, ordenar y mostrar datos de sismos usando un 
class Analizador {
private: 
    std::vector<Sismo> sismos;
    BSTSismos arbolSismos;

    void merge(int l, int m, int r, std::function<bool(const Sismo&, const Sismo&)> comparador);
    void mergeSort(int l, int r, std::function<bool(const Sismo&, const Sismo&)> comparador);

public:
    
    bool cargarDatos(const std::string& nombreArchivo);
    void ordenarPor(std::function<bool(const Sismo&, const Sismo&)> comparador);
    void mostrarDatos(const std::string& titulo) const;
    bool guardarDatos(const std::string& nombreArchivo, const std::string& titulo) const;
    int cantidadRegistros() const;
    
    //BST
    Sismo* buscarSismoPorMagnitud(double mag) const;
    std::string mostrarInorder() const;
    std::string mostrarPreorder() const;
    std::string mostrarPostorder() const;
};

#endif // ANALIZADOR_H
