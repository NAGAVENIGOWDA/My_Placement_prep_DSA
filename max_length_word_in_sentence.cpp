#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(); // Ignore the newline character in the input buffer

    char array[n + 1];
    cin.getline(array, n + 1);

    int mx = INT_MIN;
    int length = 0;
    int i = 0;

    while (array[i] != '\0')
    {
        if (array[i] != ' ')
        {
            if (array[i - 1] == ' ' || i == 0)
            {

                length = 0;
            }
            length++;
        }
        else
        {

            mx = max(mx, length);
        }

        i++;
    }

    // when it is equal to null -update

    mx = max(mx, length);

    cout << "Length of the longest word: " << mx << endl;

    return 0;
}
