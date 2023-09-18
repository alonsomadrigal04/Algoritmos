#include <iostream>
using namespace std;

int contar(int n)
{
    if (n == 0)
        return 0;
    else
        return 1 + contar(n / 10);    
}

int main()
{
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;
    cout << "El numero " << n << " tiene " << contar(n) << " digitos." << endl;
    return 0;
}