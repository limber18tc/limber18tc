#include <iostream>
#include <stdio.h>
#include <ctype.h>
const char* identificarCadena(const char* cadena) {
    int esNumerica = 1;
    int esAlfabetica = 1;

    for (int i = 0; cadena[i] != '\0'; i++) {
        char c = cadena[i];
        if (!isdigit(c)) { 
            esNumerica = 0;
        }
        if (!isalpha(c)) {
            esAlfabetica = 0; 
        }
    }

    if (esNumerica) {
        return "Numérica";
    } else if (esAlfabetica) {
        return "Alfabética";
    } else {
        return "Alfanumérica";
    }
}

int main() {
    char cadena[100];

    printf("Ingrese una cadena de caracteres: ");
    scanf("%s", cadena);

    printf("La cadena es: %s\n", identificarCadena(cadena));
    return 0;
}