/*
 * Lucca Traslosheros Abascal
 * A01713944
 * bst_sismos.cpp
 * Implementación de las funciones del BST para objetos Sismo.
 * ordenados por magnitud.
 * Avance 2
 * 23 de octubre de 2025
*/
#include "bst_sismos.h"

// NodoSismo constructor
NodoSismo::NodoSismo(const Sismo &val)
    : valor(val), izquierdo(nullptr), derecho(nullptr) {}

// BSTSismos constructor/destructor
BSTSismos::BSTSismos() : raiz(nullptr) {}
BSTSismos::~BSTSismos() { eliminarArbol(raiz); }

// Agregar
void BSTSismos::agregar(const Sismo &nuevo) {
    agregarRecursivo(raiz, nuevo);
}

void BSTSismos::agregarRecursivo(NodoSismo *&nodo, const Sismo &nuevo) {
    if (nodo == nullptr) {
        nodo = new NodoSismo(nuevo);
        return;
    }
    if (nuevo.magnitud < nodo->valor.magnitud) {
        agregarRecursivo(nodo->izquierdo, nuevo);
    } else {
        agregarRecursivo(nodo->derecho, nuevo);
    }
}

// Recorridos
std::string BSTSismos::inorder() const {
    std::stringstream ss;
    ss << "[";
    inorderRecursivo(raiz, ss);
    ss << "]";
    return ss.str();
}

void BSTSismos::inorderRecursivo(NodoSismo *nodo, std::stringstream &ss) const {
    if (!nodo) return;
    inorderRecursivo(nodo->izquierdo, ss);
    ss << nodo->valor.magnitud << " ";
    inorderRecursivo(nodo->derecho, ss);
}

std::string BSTSismos::preorder() const {
    std::stringstream ss;
    ss << "[";
    preorderRecursivo(raiz, ss);
    ss << "]";
    return ss.str();
}

void BSTSismos::preorderRecursivo(NodoSismo *nodo, std::stringstream &ss) const {
    if (!nodo) return;
    ss << nodo->valor.magnitud << " ";
    preorderRecursivo(nodo->izquierdo, ss);
    preorderRecursivo(nodo->derecho, ss);
}

std::string BSTSismos::postorder() const {
    std::stringstream ss;
    ss << "[";
    postorderRecursivo(raiz, ss);
    ss << "]";
    return ss.str();
}

void BSTSismos::postorderRecursivo(NodoSismo *nodo, std::stringstream &ss) const {
    if (!nodo) return;
    postorderRecursivo(nodo->izquierdo, ss);
    postorderRecursivo(nodo->derecho, ss);
    ss << nodo->valor.magnitud << " ";
}

// Elimina todos los nodos
void BSTSismos::eliminarArbol(NodoSismo *nodo) {
    if (!nodo) return;
    eliminarArbol(nodo->izquierdo);
    eliminarArbol(nodo->derecho);
    delete nodo;
}
