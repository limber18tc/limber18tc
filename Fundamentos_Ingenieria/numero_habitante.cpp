#include <stdio.h>
#include <stdlib.h>

int main() {
    int habitantesVivienda[5][25];
    habitantesVivienda[3][24] = 4;
    printf("El numero de personas que viven el la vivienda 25 del piso 3 es: %d\n", habitantesVivienda[3][24]);
    return 0;
}