#include <iostream>
#define max 50
#include <stdlib.h>
#include <time.h>
using namespace std;
void llenaTabla (int tabla [][max], int f, int c){
for (int i = 0; i < f; i++){
    for (int j=0 ;j<c;j++){
cout << "Introduce el valor de la posicion [" << i << "][" << j << "] de la tabla: ";
cin >> tabla [i][j];
        }
    }
}
void llenaDatos(int tabla[][max], int f, int c) {
    srand(time(NULL));
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            tabla[i][j] = (rand() % 20 + 1);
        }
    }
}
int sumaDiagonalPrincipal(int tabla [][max], int f, int c){
int suma=0;
for (int i = 0; i < f; i++){
    for (int j=0 ;j<c;j++){
        if (i==j){
            suma += tabla [i][j];
        }
}
}
return suma;
}
int sumaDiagonalSecundaria(int tabla [][max], int f, int c){
int suma=0;
for (int i = 0; i < f; i++){
    for (int j=0 ;j<c;j++){
        if (i+j==c-1){
            suma += tabla [i][j];
        }
}
}
return suma;
}
void imprimeDiagonales(int tabla [][max], int f, int c){
    for (int i = 0; i < f; i++){
        for (int j=0 ;j<c;j++){
            if (i==j || i+j==c-1){
                cout << tabla [i][j] << "\t";
            } else {
                cout << "\t";
            }
        }
        cout <<endl;
    }
}
void diagonalMayor(int tabla [][max], int f, int c){
    int sumaPrincipal = sumaDiagonalPrincipal(tabla, f, c);
    int sumaSecundaria = sumaDiagonalSecundaria(tabla, f, c);
    if (sumaPrincipal == sumaSecundaria){
        cout << "Las diagonales son iguales\n";
    } else if (sumaPrincipal > sumaSecundaria){
        cout << "La diagonal principal es mayor\n";
    } else {
        cout << "La diagonal secundaria es mayor\n";
    }
}
int main ()
{
    int tabla [max][max], filas , columnas, opcion;
    cout << "Ingrese el numero de filas y columnas de la tabla: ";
    cin >> filas >> columnas; 
        cout << "1. Llenado manual\n";
        cout << "2. Llenado aleatorio\n";
        cout << "Elija una opcion para llenar la tabla:";
        cin >> opcion;
        switch (opcion) {
            case 1:
                llenaTabla(tabla, filas, columnas);
                break;
            case 2:
                llenaDatos(tabla, filas, columnas);
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
              return 1;
    }
    imprimeDiagonales(tabla, filas, columnas);
   cout << "La suma de la diagonal principal es: " << sumaDiagonalPrincipal(tabla, filas, columnas) << endl;
cout << "La suma de la diagonal secundaria es: "<< sumaDiagonalSecundaria(tabla, filas, columnas) << endl;
    diagonalMayor(tabla, filas, columnas);
return 0;
}