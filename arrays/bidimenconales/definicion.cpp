#include <iostream>
using namespace std;
int main() 
{
    int tabla[3][3]; //Declarando
    float pesos[2][3] = { {1.2, 3.4, 5.6}, {7.8, 9.0, 1.2}}; //Declarando e inicializando
    cout << pesos[0][0] << endl; //Imprimiendo el primer elemento de la primera fila y primer columna
    cout << pesos[1][1] << endl;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            cout << pesos[i][j] << " ";
        }
        cout << endl;
    }
}