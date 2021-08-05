#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[],int n)
{
    for(int i =0 ;i<n-1;i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while(j>=0 and arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    return;
}

void print(int arr[],int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout<<arr[i]<<' ';
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ;i < n ;i++)
    {
        cin>>arr[i];
    }
    insertionSort(arr,n);
    print(arr,n);

    return 0;
}	
	
