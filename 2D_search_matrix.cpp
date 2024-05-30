#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    // given : rows and cols are sorted

    int n, m, target;
    cin >> n >> m >> target;
     bool flag=false;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int i = 0, j = m - 1;

    while (i < n && j < m)
    {
        if (target > a[i][j])
        {
            i++;
        }
        if (target < a[i][j])
        {
            j--;
        }

        if (target == a[i][j])
        {
            cout << "target found :" << i << " " << j;
            flag=true;
            break;
        }
    }

    if(flag==false){
        cout<<"target is not found";
    }

    return 0;
}