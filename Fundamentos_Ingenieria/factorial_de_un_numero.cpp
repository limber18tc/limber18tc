#include <stdio.h>
#include "factorial.h"

int main() {
    int num, resultado;

    // Solicitar al usuario un número
    printf("Ingrese un número para calcular su factorial: ");
    scanf("%d", &num);

    // Calcular el factorial
    resultado = calcularFactorial(num);

    // Verificar si el número es negativo
    if (resultado == -1) {
        printf("El factorial de un número negativo no está definido.\n");
    } else {
        printf("El factorial de %d es: %d\n", num, resultado);
    }

    return 0;
}