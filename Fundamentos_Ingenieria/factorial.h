#ifndef FACTORIAL_H
#define FACTORIAL_H

// Declaración de la función para calcular el factorial
int calcularFactorial(int n);

//
int calcularFactorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * calcularFactorial(n - 1);
    }
}
#endif