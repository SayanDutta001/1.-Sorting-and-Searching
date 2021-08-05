#include<bits/stdc++.h>
using namespace std;

int countAndMerge(int arr[],int lo,int mid,int hi)
{
    int n1 = mid + 1 - lo;
    int n2 = hi - mid;

    int l_a[n1],r_a[n2];
    for(int i = 0;i < n1 ;i++)
        l_a[i] = arr[i+lo];
    for(int i = 0;i < n2 ;i++)
        r_a[i] = arr[i+mid+1];

    int l_i,r_j,index = lo;
    l_i=r_j=0;

    int count = 0;
    while(l_i < n1 and r_j < n2)
    {
        if(l_a[l_i]<=r_a[r_j])
            arr[index++] = l_a[l_i++];
        else
        {
            count += (n1 - l_i);
            arr[index++] = r_a[r_j++];
        }
    }

    while(l_i<n1)
        arr[index++] = l_a[l_i++];
    while(r_j<n2)
        arr[index++] = r_a[r_j++];

    return count;
}

int countAndSort(int arr[],int lo,int hi)
{
    if(lo>=hi)
        return 0;
    int mid = lo + (hi -lo)/2;
    return countAndSort(arr,lo,mid) + countAndSort(arr,mid+1,hi) + countAndMerge(arr,lo,mid,hi);
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
	// for getting input from input1.txt
	freopen("input1.txt", "r", stdin);
	// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
    #endif

    int n;
    cin>>n;

    int arr[n];    
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<countAndSort(arr,0,n-1);
    return 0;
}	
	
