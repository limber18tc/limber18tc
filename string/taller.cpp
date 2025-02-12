#include <iostream>
using namespace std;

int main(){
    string cadena = "informatica";
    //Borramos los caracteres de la cadena
    cadena.clear();
    cout << cadena; //No muestra nada
    //Volvemos a inicializar con un valor
    cadena = "informatica";

    //Longitud de la cadena
    cout << "La cadena " << cadena << " tiene " << cadena.length() << " caracteres." << endl;

    //Primer y ultimo caracter
    cout << "Primer caracter: " << cadena.front() << endl; //Igual que cadena[0]
    cout << "Ultimo caracter: " << cadena.back() << endl; //Igual que cadena[cadena.length() - 1]
    
    //Añadir cadenas
    cadena.append(" moderna"); //Es lo mismo que cadena += " moderna";
    cout << cadena << endl;

    //Añadir un caracter
    char car = '0';
    cadena.append(1, car);
    cout << cadena << endl;

    //Volvemos a inicializar con un valor
    cadena = "informatica";

    //Buscar caracter
    if(cadena.find("i") != -1)
        cout << "posicion del priomer caracter i: " << cadena.find("i") << endl;
    cout << "posicion del segundo caracter i: " << cadena.find("i", 1) << endl;

    //Extraer subcadenas
    string subcad;
    subcad = cadena.substr(2, 3);
    cout << subcad << endl;
    subcad = cadena.substr(5);
    cout << subcad << endl;

    //Reemplazar para la cadena
    cadena.replace(6, 5, "ación");
    cout << cadena << endl;
    return 0;
}