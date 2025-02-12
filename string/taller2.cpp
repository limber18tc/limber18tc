#include <iostream>
using namespace std;

int main(){
    string cadena1 = ("informatica");
    string cadena4;
    const char *auxiliar;
    string cadena2(cadena1); //cadena2 = cadena1
    string cadena3(10, '*');
    cadena1.push_back('Z'); //permite añadir un caracter al final
    cout << cadena1 << endl;
    cadena1.at(0) = 'I'; //metodo at accede a un indice de la cadena : caden1[0]
    cout << cadena1 << endl;
    //usamos el metodo front y back para acceder al primer y ultimo caracter de la cadena
    cadena1.front() = 'i';
    cadena1.back() = 'A';
    cout << cadena1 << endl;
    auxiliar = cadena1.c_str(); //convertir 
    cout << "auxiliar array char: " << auxiliar << endl;
    //cadena empty para conocer si una cadena esta vacia o no
    (cadena4.empty())? cout << "Cadena vacia\n" : cout << "Cadena no vacia\n";
    //tamaño maximo de caracteres que puede almacenar la cadena
    cout << "Tamaño maximo: " << cadena1.max_size() << endl;
    //tamaño en bytes del objeto string que ocupa actualamente
    cout << "Capacidad: " << cadena1.capacity() << endl;
}