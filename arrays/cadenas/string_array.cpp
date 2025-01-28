#include <iostream>
using namespace std;
void cambiarString(string &nombres){
    nombres = "Sin nombres";

}
void cambiarArray(char apellido[]){
    /*apellido[0] = 'A';
    apellido[1] = 'l';
    apellido[2] = 'v';
    apellido[3] = 'a';
    apellido[4] = 'r';
    apellido[5] = 'e';
    apellido[6] = 'z';
    apellido[7] =  '\0';*/ //Caracter nulo para indicar el fin de una cadena
    cout << "Ingrese el nuevo apellido: ";
    cin.getline(apellido, 20);
}
int main(){
    string nombres, apodo;
    string curso[5] = {"C++", "Java", "Python", "C#", "PHP"};
    char apellido[20], apodo1[20];
    cout << "Ingrese sus nombres: ";
    getline(cin, nombres);
    cout << "Su nombre es: " << nombres << endl;
    cambiarString(nombres);
    cout << "Su nombre es luego de llamar a la funcion: " << nombres << endl;
    cout << "Ingrese sus apellidos: ";
    cin.getline(apellido, 20);
    cout << "Su apellid inicial es: " << apellido << endl;
    cambiarArray(apellido);
    cout << "Su apellido es luego de llamar a la funcio:" << apellido << endl;

}