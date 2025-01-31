#include <iostream>
using namespace std;

int main() 
{
    int numeros[5] = {5,3,1,2,4}, i, aux;
    bool cambios;
    int pasada = 0;
    
    do 
    {
        cambios = false;
        for (i = 0; i < 4; i++) 
        {
            if (numeros[i] > numeros[i + 1]) 
            {
                aux = numeros[i];
                numeros[i] = numeros[i + 1];
                numeros[i + 1] = aux;
                cambios = true;
            }
        }
    } while (cambios);
}