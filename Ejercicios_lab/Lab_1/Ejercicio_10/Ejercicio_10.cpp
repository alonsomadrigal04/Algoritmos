#include <iostream>

using namespace std;

double Elevar(double base, int exp, double result = 0)
{
    if(exp == 1)
        return base;
    else if (exp % 2 == 1) 
    {
        result = Elevar(base, exp / 2, result);
        return result * result * base;
    }

    result = Elevar(base, exp / 2, result);
    return result * result;
}

int main()
{
    cout << Elevar(2, 3) << endl;
}