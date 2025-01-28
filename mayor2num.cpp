#include <iostream>
using namespace std;

int encontrarMax(int x, int y);

int main() {
    int n1, n2;

    cout << "Digite 2 numeros: ";
    cin >> n1 >> n2;

    cout << "El mayor de los 2 numeros es: " << encontrarMax(n1, n2) << endl;

    return 0;
}

//Definicion de la funcion
int encontrarMax(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}
