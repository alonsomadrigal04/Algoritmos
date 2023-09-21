#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int busqueda_binaria(vector<int> lista, int n)
{
    int inicio = 0;
    int fin = lista.size() - 1;

    while(inicio <= fin)
    {
        int medio = (inicio + fin) / 2;
        if(lista[medio] < n) inicio = medio + 1;
        else if (lista[medio] > n) fin = medio -1;
        else return medio;
    }

    return -1;
}

int main()
{
    cout << busqueda_binaria({1, 2, 3, 4, 5, 7, 8, 9, 10}, 9) << endl;
}