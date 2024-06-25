// C++ program to find Maximum Product Subarray
#include <bits/stdc++.h>
using namespace std;

/* Returns the product
of max product subarray. */
long long int maxSubarrayProduct(int arr[], int n)
{
    long long ans = INT_MIN;
  
    // leftToRight to store product from left to Right
    long long leftToRight = 1;
  
    // rightToLeft to store product from right to left
    long long rightToLeft = 1;
  
    for (int i = 0; i < n; i++)
    {
        if (leftToRight == 0)
            leftToRight = 1;
        if (rightToLeft == 0)
            rightToLeft = 1;
      
        //calculate product from index 0 to n-1
        leftToRight *= arr[i];
      
        //calculate product from index n-1 to 0
        rightToLeft *= arr[(n - 1) - i];

        ans = max(max(leftToRight, rightToLeft), ans);
    }
    return ans;
}

// Driver code
int main()
{
    int arr[] = { 1, -2, -3, 0, 7, -8, -2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Sub array product is "
         << maxSubarrayProduct(arr, n);
    return 0;
}
