#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void llenaVector(int v[], int n){
    srand(time(NULL));
    for(int i = 0; i<n; i++){
        //v[i] = rand()%20+1;
        cin >> v[i];
    }
}
void verVector (int v[], int n){
    for (int i = 0; i < n; i++){
        cout << v[i] << "\t";
    }
}

int ordenaSeleccion(int v[], int n) {
    int contar = 0, aux;
    bool cambios = true;
    for (int i = 0; i < n - 1 && cambios; i++) {
        cambios = false;
        for (int j = i+1; j < n; j++) {
            contar++;
            if(v[i] > v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                cambios = true;
            }
        }
    }
    return contar;
}
int main ()
{
    int ne, comparaciones;
    cout << "Ingresa Nro de elementos del vector: ";
    cin >> ne;
    int vector [ne];
    llenaVector (vector, ne);
    cout << "Vector Original: \n";
    verVector (vector, ne);
    comparaciones = ordenaSeleccion(vector, ne);
    cout << "\nVector Ordenado:\n";
    verVector (vector, ne);
    cout << "\nEl Nro de comparaciones = " << comparaciones;
}