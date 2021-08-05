#include<bits/stdc++.h>
using namespace std;

int mx; // to store the max element in the array + 1 
int countAndMerge(int arr[], int l, int mid, int r)
{
    //old-value -> arr[i]%mx
    //new-value -> arr[i]/mx

    //arr[i] += mx*new_val

    int i = l, j = mid + 1, k = l;
    int cnt = 0;
    while (i <= mid and j <= r)
    {
        if (arr[i] % mx <= arr[j] % mx) // compare old values
            arr[k++] += mx * (arr[i++] % mx);

        else
        {
            cnt += mid-i+1 ;
            arr[k++] += mx * (arr[j++] % mx);
        }
    }

    while (j <= r)
        arr[k++] += mx * (arr[j++] % mx);

    while (i <= mid)
        arr[k++] += mx * (arr[i++] % mx);

    for (int i = l; i <= r; ++i)
        arr[i] /= mx;

    return cnt;

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
    mx = *(max_element(arr,arr+n))+1;
    cout<<countAndSort(arr,0,n-1);
    return 0;
}	
	
