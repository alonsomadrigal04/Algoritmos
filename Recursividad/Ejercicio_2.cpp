#include <iostream>
using namespace std;

int contar2(int n, int c)
{
    if (n / 10 == 0 )
    {
        if (n % 10 == c)
            return 1;
        else
            return 0;
    }
    else
    {
        if (n % 10 == c)
            return 1 + contar2(n / 10, c);
        else
            return contar2(n / 10, c);
    }
        
}

// this is the main function of the program that uses the contar2 function above to count the number of times a digit appears in a number n
int main ()
{
    int n;
    int c;

    cout << "Dime un numero: ";
    cin >> n;
    cout << "Dime una cifra: ";
    cin >> c;
    cout << "en " << n << "hay " << contar2(n, c) << ", " << c << endl; 
    return 0;
}