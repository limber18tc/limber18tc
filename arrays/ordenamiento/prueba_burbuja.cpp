#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void llenaVector(int v[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        v[i]  = rand()%20 + 1;
        //cin >> v[i];
    }
}
void copiaVector(int original[], int copia[], int n) {
    for (int i = 0; i < n; i++) {
        copia[i] = original[i];
    }
}
int ordenaBurbujav1(int v[], int n) {
    int aux, contador = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            contador++;
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
    return contador;
}
int ordenaBurbujav2(int v[], int n) {
    int mejora = 1;
    int aux, contador = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - mejora; j++) {
            contador++;
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
        mejora++;
    }
    return contador;
}
int ordenaBurbujav3(int v[], int n) {
    int mejora = 1;
    bool cambio = true;
    int aux, contador = 0;
    for (int i = 0; i < n && cambio; i++) {
        cambio = false;
        for (int j = 0; j < n - mejora; j++) {
            contador++;
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                cambio = true;
            }
        }
        mejora++;
    }
    return contador;
}
void muestraVector(int v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
void comparaResultados(int comparaciones1, int comparaciones2, int comparaciones3) {
    cout << "Comparaciones de cada versión:" << endl;
    cout << "El numero de coparaciones burbuja v1 = " << comparaciones1 << endl;
    cout << "El numero de coparaciones burbuja v2 = "  << comparaciones2 << endl;
    cout << "El numero de coparaciones burbuja v3 = "  << comparaciones3 << endl;

    int minimo = min(comparaciones1, min(comparaciones2, comparaciones3));
    cout << "\nLa versión más óptima es: ";
    if (minimo == comparaciones1) {
        cout << "Versión 1" << endl;
    } else if (minimo == comparaciones2) {
        cout << "Versión 2" << endl;
    } else {
        cout << "Versión 3" << endl;
    }
}
int main() {
    int ne;
    cout << "Número de elementos: ";
    cin >> ne;
    int vec[ne], copia[ne];
    
    llenaVector(vec, ne);
    cout << "Vector original: ";
    muestraVector(vec, ne);

    copiaVector(vec, copia, ne);
    int comparaciones1 = ordenaBurbujav1(copia, ne);

    copiaVector(vec, copia, ne);
    int comparaciones2 = ordenaBurbujav2(copia, ne);

    copiaVector(vec, copia, ne);
    int comparaciones3 = ordenaBurbujav3(copia, ne);

    comparaResultados(comparaciones1, comparaciones2, comparaciones3);

    cout << "\nVector ordenado (por Versión 1): ";
    muestraVector(copia, ne);

    return 0;
}
