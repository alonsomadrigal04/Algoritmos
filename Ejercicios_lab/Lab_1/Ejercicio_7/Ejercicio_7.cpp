#include <iostream>
#include <vector>

using namespace std;

int pares_buscar(vector<int> v)
{
    int resultado, primero, segundo;

    for(int i = 0; i < v.size() - 1; i++)
    {
        for(int j = i + 1; j < v.size() - 1; j++)
        {
            if(v[i] - v[j])
            {
                resultado = v[i] - v[j];
                primero = v[i];
                segundo = v[j];
            }
        }
    }
    

}
