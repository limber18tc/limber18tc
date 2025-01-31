#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funcion para generar y encontrar la matriz
void generarMatriz(int filas,int colimnas) {
    int matriz[filas][colimnas];

    //
    srand(time(NULL));

    //
    printf("Matriz generada:\n");
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < colimnas; j++){
            //
            matriz[i][j] = rand() % 100;

            //
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int filas, columnas;

    //
    printf("Ingrese el numero de filas: ");
    scanf("%d", &filas);

    //
    printf("Ingrese el numero de columnas: ");
    scanf("%d", &columnas);

    //
    generarMatriz(filas, columnas);
}