#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> 
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

void sortBinaryArray(vi&arr)
{
    int pivot = 0; // a pivot to partition the elements smaller than 0 to the right and the elements greater than the pivot to the right
    int i,j;
    i=0,j=arr.size()-1; // pointers to keep track of the elements
    while(i<=j)
    {
        while(arr[i]<=pivot)    i++; // if current element is smaller than the pivot element than move forward else stop
        while(arr[j]>pivot)     j--; // if current element is greater than the pivot element then move backward else stop
        swap(arr[i],arr[j]); // swap the values where the two pointers stop
    }
    // there will be a case where the pointers inside the while loop will overtake each other and the values will be swapped
    swap(arr[i],arr[j]); // to tackle this, the swap function is used.
    return;
}

int32_t main()
{
	FIO;
	
	#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
    #endif
	
	int n;
    cin>>n; // size of the array
    vector<int>arr; 
    for(int i=0;i<n;i++)
    {
        int x; // input array elements
        cin>>x;
        arr.pb(x);
    }
    sortBinaryArray(arr);
    for(auto x:arr)
        cout<<x<<" ";
	return 0;
}
