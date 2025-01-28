#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int obtenerEleccionUsuario() {
    int eleccion;
    printf("Elige: 1. Piedra, 2. Papel, 3. Tijera: ");
    scanf("%d", &eleccion);

    if (eleccion < 1 || eleccion > 3) {
        printf("Opción no válida. Elige entre 1, 2 o 3.\n");
        return obtenerEleccionUsuario();
    }
    return eleccion;
}

int obtenerEleccionMaquina() {
    return rand() % 3 + 1;
}

int determinarGanador(int eleccionUsuario, int eleccionMaquina) {
    if (eleccionUsuario == eleccionMaquina) {
        return 0;
    }
    if ((eleccionUsuario == 1 && eleccionMaquina == 3) || 
        (eleccionUsuario == 2 && eleccionMaquina == 1) || 
        (eleccionUsuario == 3 && eleccionMaquina == 2)) {
        return 1;
    }
    return -1;
}

void determinarGanadorJuego(int puntosUsuario, int puntosMaquina) {
    printf("\nResultado final:\n");
    printf("Puntos del Usuario: %d\n", puntosUsuario);
    printf("Puntos de la Máquina: %d\n", puntosMaquina);

    if (puntosUsuario > puntosMaquina) {
        printf("¡Felicidades! ¡Has ganado el juego!\n");
    } else if (puntosUsuario < puntosMaquina) {
        printf("La máquina gana el juego. ¡Mejor suerte la próxima vez!\n");
    } else {
        printf("El juego terminó en empate.\n");
    }
}

int main() {
    int puntosUsuario = 0, puntosMaquina = 0;
    int nivel, eleccionUsuario, eleccionMaquina, resultado;

    srand(time(0));

    printf("Elige el nivel de dificultad:\n");
    printf("1. Principiante\n");
    printf("2. Intermedio\n");
    printf("3. Avanzado\n");
    printf("Ingrese el número del nivel (1, 2, 3): ");
    scanf("%d", &nivel);

    if (nivel == 1) {
        puntosMaquina = 0;
    } else if (nivel == 2) {
        puntosMaquina = 1;
    } else if (nivel == 3) {
        puntosMaquina = 2;
    }

    for (int ronda = 1; ronda <= 5; ronda++) {
        printf("\nRonda %d\n", ronda);
        eleccionUsuario = obtenerEleccionUsuario();
        eleccionMaquina = obtenerEleccionMaquina();

        printf("Tu elección: ");
        if (eleccionUsuario == 1) printf("Piedra\n");
        else if (eleccionUsuario == 2) printf("Papel\n");
        else if (eleccionUsuario == 3) printf("Tijera\n");

        printf("La máquina elige: ");
        if (eleccionMaquina == 1) printf("Piedra\n");
        else if (eleccionMaquina == 2) printf("Papel\n");
        else if (eleccionMaquina == 3) printf("Tijera\n");

        resultado = determinarGanador(eleccionUsuario, eleccionMaquina);

        if (resultado == 1) {
            puntosUsuario++;
            printf("¡Ganaste esta ronda!\n");
        } else if (resultado == -1) {
            puntosMaquina++;
            printf("La máquina ganó esta ronda.\n");
        } else {
            printf("Empate en esta ronda.\n");
        }
    }

    determinarGanadorJuego(puntosUsuario, puntosMaquina);

    return 0;
}