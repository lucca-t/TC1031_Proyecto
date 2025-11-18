/*
    Lucca Traslosheros Abascal
    A01713944
    bst_sismos.h
    Avance 3
    17 de noviembre de 2025
*/

#ifndef BST_SISMOS_H_
#define BST_SISMOS_H_

#include <iostream>
#include <sstream>
#include <cmath>
#include "Sismo.h"

// Nodo del BST
class NodoSismo {
public:
    Sismo valor;
    NodoSismo *izquierdo;
    NodoSismo *derecho;

    NodoSismo(const Sismo &val);
};

// BST para almacenar Sismos
class BSTSismos {
private:
    NodoSismo *raiz;

    // Métodos recursivos privados
    void agregarRecursivo(NodoSismo *&nodo, const Sismo &nuevo);
    Sismo* buscarRecursivo(NodoSismo *nodo, double mag) const;

    void inorderRecursivo(NodoSismo *nodo, std::stringstream &ss) const;
    void preorderRecursivo(NodoSismo *nodo, std::stringstream &ss) const;
    void postorderRecursivo(NodoSismo *nodo, std::stringstream &ss) const;
    void eliminarArbol(NodoSismo *nodo);
    
public:
    BSTSismos();
    ~BSTSismos();


    void agregar(const Sismo &nuevo);
    Sismo* buscarPorMagnitud(double mag) const;

    std::string inorder() const;
    std::string preorder() const;
    std::string postorder() const;

};

#endif /* BST_SISMOS_H_ */
