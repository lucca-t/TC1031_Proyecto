/*
 * Lucca Traslosheros Abascal
 * A01713944
 * bst_sismos.h
 * Árbol binario de búsqueda (BST) para almacenar objetos Sismo 
 * ordenados por magnitud.
 * Avance 2
 * 23 de octubre de 2025
*/

#ifndef BST_SISMOS_H_
#define BST_SISMOS_H_

#include <iostream>
#include <sstream>
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
    void inorderRecursivo(NodoSismo *nodo, std::stringstream &ss) const;
    void preorderRecursivo(NodoSismo *nodo, std::stringstream &ss) const;
    void postorderRecursivo(NodoSismo *nodo, std::stringstream &ss) const;
    void eliminarArbol(NodoSismo *nodo);

public:
    BSTSismos();
    ~BSTSismos();

    void agregar(const Sismo &nuevo);
    std::string inorder() const;
    std::string preorder() const;
    std::string postorder() const;
};

#endif /* BST_SISMOS_H_ */
