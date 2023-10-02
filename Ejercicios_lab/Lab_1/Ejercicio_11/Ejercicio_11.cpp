#include <iostream>
#include <vector>

using namespace std;


int Contar_doble(vector<int> a, vector<int> b)
{
    int j = 0;
    int i = 0;
    int cont = 0;

    while (i < a.size()-1 && j < b.size()-1)
    {
        if(a[i] > b[j])    j++;
        else if(a[i] < b[j]) i++;
        else cont++;
    }

    return 0;
}

int main()
{
    vector<int> a = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    vector<int> b = {35, 37, 40, 47, 70, 85};

    cout << Contar_doble(a, b) << endl;
}
