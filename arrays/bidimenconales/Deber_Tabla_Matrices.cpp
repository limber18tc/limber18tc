#include <iostream>
#include <stdlib.h>
#include <time.h>
#define MAX 50 

using namespace std;

void llenaDatos(int tabla[][MAX], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tabla[i][j] = rand() % 11 + 10;
        }
    }
}

int sumaDiagonalPrincipal(int tabla[][MAX], int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += tabla[i][i];
    }
    return suma;
}

int sumaDiagonalSecundaria(int tabla[][MAX], int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += tabla[i][n - i - 1];
    }
    return suma;
}

void imprimeDiagonales(int tabla[][MAX], int n) {
    cout << "Diagonales de la matriz:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i + j == n - 1) {
                cout << tabla[i][j] << "\t";
            } else {
                cout << "\t";
            }
        }
        cout << endl;
    }
}

void diagonalMayor(int sumaPrincipal, int sumaSecundaria) {
    if (sumaPrincipal == sumaSecundaria) {
        cout << "Ambas diagonales tienen la misma suma.\n";
    } else if (sumaPrincipal > sumaSecundaria) {
        cout << "La diagonal principal tiene una suma mayor.\n";
    } else {
        cout << "La diagonal secundaria tiene una suma mayor.\n";
    }
}

// Función principal
int main() {
    int tabla[MAX][MAX];
    int n;

    cout << "Ingrese el tamaño de la matriz cuadrada (n x n): ";
    cin >> n;

    if (n <= 0 || n > MAX) {
        cout << "Tamaño inválido. Intente de nuevo.\n";
        return 1;
    }

    llenaDatos(tabla, n);

    cout << "\nMatriz generada:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << tabla[i][j] << "\t";
        }
        cout << endl;
    }

    int sumaPrincipal = sumaDiagonalPrincipal(tabla, n);
    int sumaSecundaria = sumaDiagonalSecundaria(tabla, n);

    cout << "\n";
    imprimeDiagonales(tabla, n);

    cout << "\nSuma de la diagonal principal: " << sumaPrincipal << endl;
    cout << "Suma de la diagonal secundaria: " << sumaSecundaria << endl;

    diagonalMayor(sumaPrincipal, sumaSecundaria);

    return 0;
}
