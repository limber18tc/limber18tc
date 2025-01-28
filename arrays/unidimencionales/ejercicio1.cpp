#include <iostream>
using namespace std;
void llenaVector(int v[], int tamano) {
    for(int i = 0; i < tamano; i++) {
        cout << "Ingrese el valor del elemento " << i + 1 << ": ";
        cin >> v[i];
    }
}
void verVector(int v[], int tamano) {
    for(int i = 0; i < tamano; i++) {
        cout << "El elemento " << i + 1 << " del vectores: " << v[i] << endl;
    }
}

int main() {
    int ne;
    cout << "Cuantos elementos tiene el vector?: ";
    cin >> ne;
    int vector[ne];
    llenaVector(vector, ne);
    verVector(vector, ne);
}