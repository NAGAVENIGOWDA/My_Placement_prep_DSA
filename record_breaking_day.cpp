#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int array[10];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    int rbd = 0;
    int mx = array[0];
    if (n == 1)
    {
        rbd++;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1 && array[i] > mx)
        {
            rbd++;
        }
        else
        {
            if (array[i + 1] < array[i] && array[i] > mx)
            {
                rbd++;
            }
        }

       mx=max(mx,array[i]);
    }

    cout << rbd;

    return 0;
}