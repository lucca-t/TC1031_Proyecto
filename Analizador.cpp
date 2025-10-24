// Lucca Traslosheros Abascal
// A01713944
// Avance 2
// 23 de octubre de 2025

#include "Analizador.h"  
#include <fstream>       
#include <sstream>       

// Implementación de la función cargarDatos
bool Analizador::cargarDatos(const std::string& nombreArchivo) {
    
    // Abre el archivo.
    std::ifstream archivo(nombreArchivo);

    // verifica si el archivo se abrió correctamente. Si no, regresa error.
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo encontrar el archivo '" << nombreArchivo << "'" << std::endl;
        return false;
    }

    std::string linea;
    // ignora la primera línea 
    std::getline(archivo, linea);

    // lee el resto del archivo línea por línea.
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string campo;

        // guardar detalles de la linea
        int id;
        std::string fecha;
        double lat, lon, prof, mag;

        
        std::getline(ss, campo, ','); id = std::stoi(campo);
        std::getline(ss, campo, ','); fecha = campo;
        std::getline(ss, campo, ','); lat = std::stod(campo);
        std::getline(ss, campo, ','); lon = std::stod(campo);
        std::getline(ss, campo, ','); prof = std::stod(campo);
        std::getline(ss, campo, ','); mag = std::stod(campo);
        
        
        sismos.push_back(Sismo(id, fecha, lat, lon, prof, mag));

        // Agregar en arbol
        Sismo nuevoSismo(id, fecha, lat, lon, prof, mag);
        arbolSismos.agregar(nuevoSismo);

    }

      
    archivo.close();
    return true;
}


//  Merge Sort

void Analizador::merge(int l, int m, int r, std::function<bool(const Sismo&, const Sismo&)> comparador) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<Sismo> L(n1), R(n2);

    for (int i = 0; i < n1; i++){
        L[i] = sismos[l + i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = sismos[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (comparador(L[i], R[j])) {
            sismos[k] = L[i];
            i++;
        } else {
            sismos[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) { 
        sismos[k] = L[i]; 
        i++; 
        k++; 
    }

    while (j < n2) { 
        sismos[k] = R[j]; 
        j++; 
        k++; 
    }
}

void Analizador::mergeSort(int l, int r, std::function<bool(const Sismo&, const Sismo&)> comparador) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(l, m, comparador);
    mergeSort(m + 1, r, comparador);
    merge(l, m, r, comparador);
}

// Escoger para que ordenarlos
void Analizador::ordenarPor(std::function<bool(const Sismo&, const Sismo&)> comparador) {
    if (!sismos.empty()) {
        mergeSort(0, sismos.size() - 1, comparador);
    }
}

// Muestra todos los sismos en la consola.
void Analizador::mostrarDatos(const std::string& titulo) const {
    std::cout << "\n--- " << titulo << " ---\n";

    if (sismos.empty()) {
        std::cout << "No hay datos para mostrar." << std::endl;
        return;
    }

    for (const auto& sismo : sismos) {
        sismo.imprimir();
    }

    std::cout << "--------------------------------------\n";
}

// Regresa el número total de sismos cargados.
int Analizador::cantidadRegistros() const {
    return sismos.size();
}


std::string Analizador::mostrarInorder() const {
    return arbolSismos.inorder();
}

std::string Analizador::mostrarPreorder() const {
    return arbolSismos.preorder();
}

std::string Analizador::mostrarPostorder() const {
    return arbolSismos.postorder();
}



