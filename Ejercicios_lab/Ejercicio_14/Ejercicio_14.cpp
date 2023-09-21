#include <vector>
#include <iostream>

using namespace std;

int estudio_fidelidad(vector<int> A, vector<int> B)
{
    vector<int> resto;
    bool fiel = false;

    for(int i = 0; i < A.size(); i++)
    {
        for(int j = 0; j < B.size(); j++)
        {
            if(A[i] == B[j])
            {
                fiel = true;
                break;
            } 
        }

        if (!fiel) resto.push_back(A[i]);
    }
}