#include <iostream>
#include <stdlib.h> 
#define MAX 20
using namespace std;

void determinarCategoria(int valor, char categoria[]) {
    char categorias[5][15] = {"Deficiente", "Regular", "Bueno", "Muy bueno", "Excelente"};
    int indice = (valor > 18) ? 4 : (valor - 1) / 5;

    int i = 0;
    while (categorias[indice][i] != '\0') {
        categoria[i] = categorias[indice][i];
        i++;
    }
    categoria[i] = '\0';
}

int main() {
    char opcion;

    do {
        system("clear");

        int valor;
        char categoria[15];

        cout << "Ingresa un valor entre 1 y 20: ";
        cin >> valor;

        if (valor < 1 || valor > MAX) {
            cout << "El valor ingresado esta fuera del rango permitido." << endl;
        } else {
            determinarCategoria(valor, categoria);
            cout << "Categoria: " << categoria << endl;
        }

        cout << "\nDeseas volver a ejecutar el programa? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S'); 

    return 0;
}