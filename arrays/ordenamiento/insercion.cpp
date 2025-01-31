// DEBER; HACER LAS COMAPARACIONES DE BUSRBUJAS DE LAS TRES MANERASEN PRUEBA DE ESCRITORIO
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void llenarVector(int v[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        //v[i] = rand() % 20 + 1;
        cin>>v[i];
    }
}

void mostrarVector(int v[], int n) {
    for (int i = 0; i < n; i++) {
    cout << v[i] << "\t";
    }
}

int ordenarInsersion(int v[], int n) {
    int contador = 0;
    for (int i = 1; i < n; i++) {
        int aux = v[i];
        int j = i - 1;
        while (j >= 0) {
            contador++;
            if (aux<v[j]) {
                v[j + 1] = v[j];
            v[j] = aux;
        
        }
        j--;
    }
}
return contador;
}
int main() {
    int ne, comparaciones;
    cout << "Ingrese el numero de elementos del vector: ";
    cin >> ne;
    int vector[ne];
    llenarVector(vector, ne);
    cout << "Vector original: \n";
    mostrarVector(vector, ne);
comparaciones = ordenarInsersion(vector, ne);
cout << "\nVector ordenado: \n";
mostrarVector(vector, ne);
cout << "\nEl numero de comparaciones es: " << comparaciones;
}