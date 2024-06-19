//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int left=l;
         int right=m+1;
         vector<int>tmp(r-l+1,0);
         int k=0;
         
         while(left<=m && right<=r ){
             if(arr[left]<=arr[right]){
                 tmp[k++]=arr[left];
                 left++;
             }
             
             else{
                 tmp[k++]=arr[right];
                 right++;
             }
         }
         
         while(left<=m){
             tmp[k++]=arr[left];
             left++;
         }
         while(right<=r){
             tmp[k++]=arr[right];
             right++;
         }
         
         for(int i=l;i<=r;i++){
             arr[i]=tmp[i-l];
         }
         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        
        //l=0,r=n-1
        if(l>=r) return;
        if(l<r){
            int mid=(l+r)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends