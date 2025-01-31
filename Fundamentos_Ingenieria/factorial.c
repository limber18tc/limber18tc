#include "factorial.h"

// Implementación de la función para calcular el factorial de un número
int calcularFactorial(int n) {
    if (n < 0) {
        return -1;  // Retorna -1 si el número es negativo (caso inválido)
    }

    int resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }

    return resultado;
}