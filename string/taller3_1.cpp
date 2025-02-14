#include <iostream>
#include <string>
using namespace std;

int main() {
    string cadena;
    string objetivo;
    string porcion;

    cout << "Ingrese la frase original: ";
    getline(cin, cadena);

    cout << "Ingrese la palabra a buscar: ";
    cin >> objetivo;

    int pos = cadena.find(objetivo);
    if (pos != string::npos) {

        cout << "Ingrese la nueva palabra: ";
        cin >> porcion;

        cadena.replace(pos, objetivo.length(), porcion);
        cout << "Nueva frase: " << cadena << endl;
    } else {
        cout << "La palabra \"" << objetivo << "\" no se encuentra en la frase." << endl;
    }

    return 0;
}
