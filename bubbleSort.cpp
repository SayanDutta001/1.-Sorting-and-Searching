#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],int n)
{
    for(int i =0 ;i<n-1;i++)
    {
        bool flag = false;
        for(int j = 0 ;j< n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                flag = true;
                swap(arr[j],arr[j+1]);
            }
            
        }

        if(!flag) // if the input data is already sorted then loop will run only once
            break;
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
    bubbleSort(arr,n);
    print(arr,n);
    
    return 0;
}	
	
