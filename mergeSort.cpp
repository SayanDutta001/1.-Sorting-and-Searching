#include<bits/stdc++.h>
using namespace std;

// 1.basic merge funtion with O(N) space

// void merge(int arr[],int lo,int mid,int hi)
// {
//     int n1 = mid + 1 - lo;
//     int n2 = hi - mid;
    
//     int l_a[n1],r_a[n2];

//     for(int i = 0;i < n1;i++)
//         l_a[i] = arr[i+lo];

//     for(int i = 0;i < n2; i++)
//         r_a[i] = arr[mid+1+i]; 
    
//     int l_i, r_j,index = lo;
//     l_i = r_j = 0;

//     while(l_i < n1 and r_j < n2)     
//     {
//         if(l_a[l_i]<r_a[r_j])
//             arr[index++] = l_a[l_i++]; 
//         else
//             arr[index++] = r_a[r_j++];
//     }

//     while(l_i<n1)
//         arr[index++] = l_a[l_i++]; 
//     while(r_j < n2)
//         arr[index++] = r_a[r_j++];
//     return;
// }

// 2.merge function with O(N) Extra Space (slight optimisation than the above one)

// void merge(int arr[],int lo,int mid,int hi)
// {
//     int n1 = mid + 1 - lo;
//     int n2 = hi - mid;
    
//     int l_a[n1+1],r_a[n2+1];

//     for(int i = 0;i < n1;i++)
//         l_a[i] = arr[i+lo];

//     for(int i = 0;i < n2; i++)
//         r_a[i] = arr[mid+1+i];

//     l_a[n1] = r_a[n2] = INT_MAX;
    
//     int l_i, r_j;
//     l_i =r_j = 0;

//     for(int index = lo; index<=hi;index++)
//     {
//         if(l_a[l_i]<r_a[r_j])
//             arr[index] = l_a[l_i++];
//         else
//             arr[index]=r_a[r_j++];
//     }

//     return;
// }

// 3.merge function with O(1) extra space 

void merge(int arr[],int lo,int mid,int hi,int mx)
{
    // arr[i] += arr[i] * mx
    // arr[i] % mx -> old_value
    // arr[i] / mx -> new_value

    int l_i,r_j,index;

    index = lo;     //Index of the orig_array 
    l_i = lo;      // left array index
    r_j = mid + 1; // right array index

    while(l_i <= mid and r_j<=hi)
    {
        if((arr[l_i] % mx) <= (arr[r_j] % mx)) // comparsion of old values
            arr[index++] += mx*(arr[l_i++] % mx);
        else
            arr[index++] += mx*(arr[r_j++] % mx);
    }   

    while(l_i <= mid) // variables of non exhausted array 
        arr[index++] += mx*(arr[l_i++] % mx);

    while(r_j <= hi)
        arr[index++] += mx*(arr[r_j++] % mx);

    for(int i =lo;i <= hi; i++) // updation of the old value to the new value
        arr[i]/=mx;
}

void mergeSort(int arr[],int lo,int hi,int mx) // for funtion 3
// void mergeSort(int arr[],int lo,int hi) // for function 1 and 2
{
    if(lo>=hi)
        return;
    int mid = lo + (hi - lo)/2;

    // mergeSort(arr,lo,mid);
    // mergeSort(arr,mid+1,hi);
    // merge(arr,lo,mid,hi); // for function 1 and 2

    mergeSort(arr,lo,mid,mx); // for function 3
    mergeSort(arr,mid+1,hi,mx);
    merge(arr,lo,mid,hi,mx);
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

    int mx;
    mx = *(max_element(arr,arr+n)) + 1; // max_value of the array + 1 
    
    // mergeSort(arr,0,n-1); // for functions 1 and 2
  
    mergeSort(arr,0,n-1,mx); // for function 3
    print(arr,n);

    return 0;
}	
	
