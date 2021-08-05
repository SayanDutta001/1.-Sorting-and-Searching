#include<bits/stdc++.h>
using namespace std;

// arr[] = {3, 8 ,6, 10 ,12, 7}
// p = 5 -> arr[5] = 7
// So elements that are lesser than or equal to 7 should be present in the array before the element 7
// Elements greater than 7 should be present after the element 7
// After partitioning arr[] = {3, 6, 7, 8, 10, 12}
//                                   ^
//                            partition element

void naivePartition(int arr[],int lo,int hi,int p) // Stable, O(3N)
{
    int temp[hi-lo+1];
    int index = 0;

    // First of all, if array elements that are smaller than or equal to the partion 
    // element gets added to the temp array 
    for(int i=lo;i<=hi;i++) 
        if(arr[i]<=arr[p]) 
            temp[index++] = arr[i];

    // Then array elements are greater than the partition element gets added after the partition elment
    for(int i=lo;i<=hi;i++)
        if(arr[i]>arr[p])
            temp[index++] = arr[i];

    // the temp array is copied to the orig_array
    for(int i = lo; i<= hi;i++)
        arr[i] = temp[i];
}

void printArray(int arr[],int n)
{
    for(int i = 0;i < n; i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int n;
    cin>>n;

    int arr[n];    
    for(int i=0;i<n;i++)
        cin>>arr[i];
  
    int p;
    cin>>p; // input pivot element
    naivePartition(arr,0,n-1,p);
    printArray(arr,n);
    return 0;
}	
	
