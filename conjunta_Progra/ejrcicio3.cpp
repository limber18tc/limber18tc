#include <iostream>
#include <stdio.h>

const char* obtenerCategoria(int numero) {
    const char* categorias[] = {"Deficiente", "Regular", "Bueno", "Muy bueno", "Excelente"};

    if (numero < 1 || numero > 20) {
        return "Valor fuera de rango";
    }

    if (numero >= 16) {
        return categorias[4];
    } else {
        return categorias[(numero - 1) / 5];
    }
}

int main() {
    int numero;

    printf("Por favor, ingrese un número entre 1 y 20: ");
    scanf("%d", &numero);

    printf("La categoría del número %d es: %s\n", numero, obtenerCategoria(numero));
    
    return 0;
}
