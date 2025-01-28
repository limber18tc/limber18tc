#include <iostream>
using namespace std;
int main() {
    int anios[5]; //Declaracion de un vector de 5 elementos
    int edad[5] = {20, 25, 30, 35, 40}; //Declaracion y asignacion de un vector de 5 elementos
    double estatura[] = {1.25, 1.66, 1.78, 1.70, 1.90}; //Declaracion y asignacion de un vector de 5 elementos
    char sexo[] = {'M', 'F', 'M', 'F', 'M'}; //Declaracion y asignacion de un vector de 5 elementos
    cout << "El primer elemento del vector de edad es: "<< edad[0] << endl;
    cout << "El ulti o elemento de estatura es: " << estatura[4] << endl;
    cout << "El elemento mitad de sexo es: " << sexo[5/2] << endl;
    for(int i = 0; i < 5; i++) {
        cout << "El elemento " << i << " del vector edad es: " << edad[i] << endl;
    }
    for(int i = 0; i < 5; i++) {
        cout << "El elemento " << i << " del vector edad es: " << estatura[i] << endl;
    }

}